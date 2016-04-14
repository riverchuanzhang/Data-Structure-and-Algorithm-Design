#include <stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct CSNode {
	ElemType data;
	struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
//操作结果：构造空树
void InitTree(CSTree &T) {
	T = NULL;
}

/**初始条件：树存在
 * 操作结构：销毁树
 * 操作成功则返回true，否则返回false;
 */
bool DestoryTree(CSTree &T) {
	if(T==NULL)
		return false;
	CSNode *firstchild, *nextsibling;
	firstchild = T->firstchild;
	nextsibling = T->nextsibling;
	if (firstchild != NULL)
		DestoryTree(firstchild);
	if (nextsibling != NULL)
		DestoryTree(nextsibling);
	free(T);
	T=NULL;
	return true;

}

//此方法为CreateTree方法的辅助方法，利用递归产生结点。flag作为标示pNode是否为根结点，flag=0则为根结点，为1则不为根结点。注意：当请求输入结点的孩子或兄弟值时，当输入空格则表示没有孩子或兄弟。
void creatNodes(CSNode *pNode, int flag) {
	CSNode * childPNode;
	CSNode * brotherPNode;
	ElemType tempElem;
	printf("请输入%c的孩子(请输入一个字符，输入空格表示没有)：", pNode->data);
	getchar();
	scanf("%c", &tempElem);
	if (tempElem != 0x20) {  //0x20:表示空格
		childPNode = (CSNode *) malloc(sizeof(CSNode));
		childPNode->nextsibling=NULL;
		childPNode->firstchild=NULL;
		childPNode->data = tempElem;
		pNode->firstchild = childPNode;
		creatNodes(childPNode, 1);
	}
	if (flag == 0) //因为是根结点，所以不需要关注它的兄弟
		return;
	printf("请输入%c的兄弟(请输入一个字符，输入空格表示没有)：", pNode->data);
	getchar();
	scanf("%c", &tempElem);
	if (tempElem != 0x20) {  //0x20:表示空格
		brotherPNode = (CSNode *) malloc(sizeof(CSNode));
		brotherPNode->firstchild=NULL;
		brotherPNode->nextsibling=NULL;
		brotherPNode->data = tempElem;
		pNode->nextsibling = brotherPNode;
		creatNodes(brotherPNode, 1);
	}

}

/**
 * 操作结果：根据用户需要构造树
 * 
 */
void CreateTree(CSTree &T) {
	T = (CSNode *) malloc(sizeof(CSNode));
	T->firstchild=NULL;
	T->nextsibling=NULL;
	printf("请输入头节点(请输入一个字符，输入空格表示没有)：");
	getchar();
	scanf("%c", &(T->data));
	if(T->data!=0x20){
		creatNodes(T,0);
	}else{
		printf("头结点为空\n");
	}
	
}

/**初始条件：树存在
 * 操作结果：将树清空
 * 操作成功则返回true，否则返回false;
 */
bool ClearTree(CSTree &T) {
	if (T != NULL) {
		T = NULL;
		return true;
	}
	return false;
}

/**
 * 操作结果：若树为空树，返回true，否则返回false
 * 
 */
bool TreeEmpty(CSTree &T) {
	if (T == NULL)
		return true;
	else
		return false;
}


/**初始条件：树存在
 * 操作结果：返回树的深度
 * 
 */
int TreeDepth(CSTree &T) {  //递归调用获得深度
	int depth = 0;
	if (T == NULL)
		return 0;
	if (T->firstchild == NULL)
		return 1;
	depth=TreeDepth(T->firstchild);
	for (int max = 0; T->nextsibling != NULL; T = T->nextsibling) {
		max = TreeDepth(T->firstchild);
		if (depth < max)
			depth = max;
	}
	return depth+1;
}

/**
 *初始条件：树存在
 * 操作结果：返回树的根
 */
CSNode Root(CSTree &T) {
	return *T;
}

/**
 *初始条件：树存在
 *操作结果：通过cur_e，在树T中找到它对应的结点，找不到返回空，找到则返回该结点
 */
CSNode *getNodeInTree(CSTree &T, ElemType cur_e) {  
	CSNode *resultNode = NULL;
	if (T == NULL)
		return NULL;
	if (T->data == cur_e) {
		return T;
	}
	resultNode = getNodeInTree((T->firstchild), cur_e);
	if (resultNode != NULL)
		return resultNode;
	resultNode = getNodeInTree((T->nextsibling), cur_e);
	if (resultNode != NULL)
		return resultNode;
	return NULL;

}

/**
 * 初始条件：树存在，cur_e是树中某个节点的值
 * 操作结果：返回cur_e的值
 */
ElemType Value(CSTree &T, ElemType cur_e) {
	if (!getNodeInTree(T, cur_e))
		return NULL;
	return cur_e;
}

/**
 * 初始条件：树存在，cur_e是树中某个节点的值
 * 操作结果：cur_e对应的结点赋值为value。操作成功返回true，否则fasle
 */
bool Assign(CSTree &T, ElemType cur_e, ElemType value) {
	CSNode *nodeP = getNodeInTree(T, cur_e);
	if (nodeP != NULL) {
		nodeP->data = value;
		return true;
	} else{
		return false;
	}
		
}

/**
 * 初始条件：树存在，cur_e是树中某个节点的值
 * 操作结果：cur_e对应的结点是树的非根结点则返回它的双亲，否则返回空
 */
CSNode *Parent(CSTree &T, ElemType cur_e) {
	CSNode *nodeParent = NULL;
	if (T == NULL)
		return NULL;
	if(T->firstchild!=NULL){
		if (T->firstchild->data == cur_e) {
		return T;
	     }
	}
	nodeParent = Parent((T->firstchild), cur_e);
	if (nodeParent != NULL)
		return nodeParent;
	nodeParent = Parent((T->nextsibling), cur_e);
	if (nodeParent != NULL)
		return nodeParent;
	return nodeParent;
}

/**
 * 初始条件：树存在，cur_e是树中某个节点的值
 * 操作结果：cur_e对应的结点是非叶子结点则返回它的最左孩子，否则返回空
 */
CSNode *LeftChild(CSTree &T, ElemType cur_e) {
	CSNode *nodeP = getNodeInTree(T, cur_e);
	if (nodeP != NULL)
		return nodeP->firstchild;
	else
		return NULL;
}

/**
 * 初始条件：树存在，cur_e是树中某个节点的值
 * 操作结果：若cur_e对应的结点是有右兄弟则返回它的右兄弟，否则返回空
 * 注意返回的右兄弟可能有多个，所以这里存放指向这些兄弟节点的指针数组
 */
CSTree* RightSibling(CSTree &T, ElemType cur_e) { //返回存放指向节点的指针数组
	CSTree* pNodes = NULL;
	CSNode *pNode = getNodeInTree(T, cur_e);
	if(pNode==NULL){
		return NULL;
	}
	int i = 1;
	while (pNode->nextsibling != NULL) {
		pNode = pNode->nextsibling;
		pNodes = (CSTree*)realloc(pNodes, sizeof(CSTree) * (i+1));
		pNodes[i - 1] = pNode;
		i++;
	}
	if(i!=1)
	  pNodes[i - 1] = NULL;
	return pNodes;

}

/**
 * 初始条件：树T存在，p指向树T中某个结点，1<=i<=p所指结点的度+1，非空树c与T不相交
 * 操作结果：插入c为树T中p指结点的第i棵树
 */
bool InsertChild(CSTree &T, ElemType p, int i, CSTree c) {
	CSNode *pp = getNodeInTree(T, p);
	if (!pp) {
		return false;
	}
	if (i == 1) {
		c->nextsibling =pp->firstchild ;
		pp->firstchild = c;
		return true;

	}else{
		int j = 1;
		for (CSNode *pNode = pp->firstchild; pNode != NULL && j < i;
				pNode = pNode->nextsibling) {
			if (j + 1 == i) {
				c->nextsibling = pNode->nextsibling;
				pNode->nextsibling = c;
				return true;
			}
			j++;
		}
		
		
	}
	return false;

}

/**
 * 初始条件：树T存在，p指向树T中某个结点，1<=i<=p所指结点的度
 * 操作结果：删除树中p指结点的第i棵树
 */
bool DeleteChild(CSTree &T, ElemType p, int i) {
	CSNode *pp = getNodeInTree(T, p);
	if (!pp) {
		return false;
	}
	if(i==1){
		if(pp->firstchild!=NULL){
			pp->firstchild=pp->firstchild->nextsibling;
			return true;
		}
		return false;

	}
	int j = 1;
	for (CSNode *pNode = pp->firstchild; pNode != NULL && j <i;
			pNode = pNode->nextsibling) {
		if (j + 1 == i) {
			pNode->nextsibling = pNode->nextsibling->nextsibling;
			return true;
		}
		j++;
	}
	return false;
}

void Vi(CSNode node){
    printf("%c",node.data);
}

/**
 * 初始条件：树T存在，Visit是对结点操作的应用函数
 * 操作结果：按前序次序对树T的每个结点调用函数visit,一次且最多一次。一旦visit失败，则操作失败
 */
bool TraverseTree(CSTree &T, void (*Visit)(CSNode node)) {
	if (T == NULL)
		return false;
	Visit(*T);
	TraverseTree((T->firstchild), Visit);
	TraverseTree((T->nextsibling), Visit);
	return true;
}

/**
 * 用于测试的函数，用来生成树
 */
CSTree getTestTree(){
	CSTree T=(CSTree)malloc(sizeof(CSNode));
	CSNode *pNode1=(CSNode*)malloc(sizeof(CSNode));
	CSNode *pNode2=(CSNode*)malloc(sizeof(CSNode));
	CSNode *pNode3=(CSNode*)malloc(sizeof(CSNode));
	T->firstchild=pNode1;
	T->nextsibling=NULL;
	T->data='A';
	pNode1->firstchild=pNode3;
	pNode1->nextsibling=pNode2;
	pNode1->data='B';
	pNode2->firstchild=NULL;
	pNode2->nextsibling=NULL;
	pNode2->data='C';
	pNode3->firstchild=NULL;
	pNode3->nextsibling=NULL;
	pNode3->data='D';
	return T;
}

void testInitTree(CSTree &T){
	//1、InitTree 构造空树  通过
	printf("testInitTree()\n");
	printf("树：");
	if(!TraverseTree(T,Vi))
		printf("空树");
	printf("\n");
	printf("调用方法后\n");
	printf("树(前序)：");
	InitTree(T);   //令树为空
	if(!TraverseTree(T,Vi))
		printf("空树");
}

void testDestoryTree(CSTree &T){
	//2、DestoryTree 销毁树  释放空间
	printf("testDestoryTree()\n");
	printf("树：");
	if(!TraverseTree(T,Vi))
		printf("空树");
    printf("\n");
	printf("调用方法后\n");
	printf("树(前序)：");
	DestoryTree(T);
	if(!TraverseTree(T,Vi))
		printf("空树");
}

void testCreateTree(CSTree &T){
	//3、CreaTree  通过 
	printf("testCreateTree()\n");
	CreateTree(T);
	printf("树(前序)：");
	TraverseTree(T,Vi);
}

void testClearTree(CSTree &T){
	//4、ClearTree 清空树  通过
	printf("testClearTree()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	printf("树(前序)：");
	TraverseTree(T,Vi);
	 printf("\n");
	printf("调用方法后\n");
	if(ClearTree(T))
		printf("清空了树");
	else
       printf("清空失败");
}

void testTreeEmpty(CSTree &T){
	//5、TreeEmpty
	printf("testTreeEmpty()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("调用方法后\n");
	if(TreeEmpty(T))
		printf("空树");
	else
        printf("不是空树");
}

void testTreeDepth(CSTree &T){
//6、TreeDepth 深度  通过 可能会有错
	printf("testTreeDepth()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("调用方法后\n");
	printf("树深度为%d",TreeDepth(T));
}

void testRooot(CSTree &T){
	//7、Root  根  通过
	printf("testRooot()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("调用方法后\n");
	printf("根为：%c",Root(T).data);
}

void testValue(CSTree &T){
	//8 Value    通过
	printf("testValue()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType elem;
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值:");
	getchar();
	scanf("%s",&elem);
	ElemType myElem=Value(T,elem);
	printf("调用方法后\n");
	if(myElem!=NULL)
		printf("%c是树的结点，值为：%c",elem,myElem);
	else
	   printf("%c不是树的结点",elem);

}

void testAssign(CSTree &T){
	//9 Assign 通过
	printf("testAssign()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType oldElem='k';
	ElemType newElem='A';
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入原来结点的值和改变的值:");
	getchar();
	scanf("%c,%c",&oldElem,&newElem);
	printf("调用方法后\n");
	if(!Assign(T,oldElem,newElem))
		printf("%c不是树的结点，所以操作失败",oldElem);
	else 
		TraverseTree(T,Vi);

}

void testParent(CSTree &T){
	//10、Parent  通过
	printf("testParent()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType childElem='p';
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值:");
	getchar();
	scanf("%c",&childElem);
	CSNode *parentPNode=Parent(T,childElem);
	printf("调用方法后\n");
	if(parentPNode!=NULL)
		printf("%c的双亲是%c",childElem,parentPNode->data);
	else
		printf("找不到%c的双亲",childElem);
}

void testLeftChild(CSTree &T){
		//11、LeftChild  通过
	printf("testLeftChild()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType parentElem;
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值:");
	getchar();
	scanf("%c",&parentElem);
	CSNode *childPNode=LeftChild(T,parentElem);
	printf("调用方法后\n");
	if(childPNode!=NULL)
       printf("%c的左孩子是%c",parentElem,childPNode->data);
	else
		printf("%c没有左孩子",parentElem);
}

void testRightSibling(CSTree &T){
	//12、RightSibling  通过
	printf("testRightSibling()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType elem=NULL;
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值:");
	getchar();
	scanf("%c",&elem);
	CSTree *pNodes=RightSibling(T,elem);
	printf("调用方法后\n");
	if(pNodes!=NULL){
		 printf("%c的右兄弟是：",elem);
         for(int i=0;*(pNodes+i)!=NULL;i++){
			 printf("%c",(*(pNodes+i))->data);
		 }
	}else
		printf("%c没有右兄弟",elem);
}

void testInsertChild(CSTree &T){
	//13、InsertChild 通过
	printf("testInsertChild()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType p=NULL;
	int i=0;
	CSTree addedTree=getTestTree();
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值和第几个:");
	getchar();
	scanf("%c,%d",&p,&i);
	printf("添加第%d颗树\n",i);
	printf("调用方法后\n");
	InsertChild(T,p,i,addedTree);
	TraverseTree(T,Vi);
}

void testDeleteChild(CSTree &T){
	//14、DeleteChild
	printf("testDeleteChild()\n");
	if(TreeEmpty(T)){
		printf("空树");
		return ;
	}
	ElemType p=NULL;
	int i=0;
	printf("树(前序)：");
	TraverseTree(T,Vi);
	printf("\n");
	printf("请输入一个结点的值和第几个:");
	getchar();
	scanf("%c,%d",&p,&i);
	printf("调用方法后\n");
	printf("删除第%d颗树",i);
	printf("\n");
	if(DeleteChild(T,p,i))
	  TraverseTree(T,Vi);
	else
		printf("删除失败");
}

void testTraverseTree(CSTree &T){
    //15、TraverseTree  前序查找  通过
	printf("testTraverseTree()\n");
	printf("树(前序)：");
	TraverseTree(T,Vi);
}


int main(){
	CSTree mainTree=NULL;
	int select=0;
	do{
      printf("select 1 构造空树 InitTree()\n");
      printf("select 2 销毁树 DestoryTree()\n");
      printf("select 3 构造树 CreateTree()\n");
      printf("select 4 清空树 ClearTree()\n");
      printf("select 5 是否为空树 TreeEmpty()\n");
      printf("select 6 树的深度 TreeDepth()\n");
      printf("select 7 树的根 Root()\n");
      printf("select 8 结点的值 Value()\n");
      printf("select 9 给点的赋值 Assign()\n");
      printf("select 10 结点的双亲 Parent()\n");
      printf("select 11 树的左孩子 LeftChild()\n");
      printf("select 12 树的右孩子 RightSibling()\n");
      printf("select 13 插入子树 InsertChild()\n");
      printf("select 14 删除子树 DeleteChild()\n");
      printf("select 15 遍历树 TraverseTree()\n");
      printf("input your select: ");
      scanf("%d",&select);
	  switch(select){
	  case 1:
		  testInitTree(mainTree);
		  break;
	  case 2:
		  testDestoryTree(mainTree);
		  break;
	  case 3:
		  testCreateTree(mainTree);
		  break;
	  case 4:
		  testClearTree(mainTree);
		  break;
	  case 5:
		  testTreeEmpty(mainTree);
		  break;
	  case 6:
		  testTreeDepth(mainTree);
		  break;
	  case 7:
		  testRooot(mainTree);
		  break;
	  case 8:
		  testValue(mainTree);
		  break;
	  case 9:
		  testAssign(mainTree);
		  break;
	  case 10:
		  testParent(mainTree);
		  break;
	  case 11:
		  testLeftChild(mainTree);
		  break;
	  case 12:
		  testRightSibling(mainTree);
		  break;
	  case 13:
		  testInsertChild(mainTree);
		  break;
	  case 14:
		  testDeleteChild(mainTree);
		  break;
	  case 15:
		  testTraverseTree(mainTree);
		  break;

	  default :
		  select=50;
	  }
	  printf("\n");

	}while(select>0&&select<16);
	return 0;
}
