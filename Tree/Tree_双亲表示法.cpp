
//============================================================================
// Name        : Whole.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include<malloc.h>
typedef char TElemType;
#define MAX_TREE_SIZE 50

typedef struct PTNode { //结点结构
	TElemType data;
	int parent; //双亲位置
} PTNode;
typedef struct { //树结构
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; //根的位置和节点数
} PTree;

//判断树是否是空树【turbo c里面实现的时候是用boolean true要用大写，包括 eclipse中：typedef char TElemType;  turbo c中是typedef TElemType char;】
bool TreeEmpty(PTree T) {
	if (T.n == 0)
		return true;
	else
		return false;
}

//将树c插入为树T中值为p的结点的第i棵子树
void InsertChild(PTree &T, char p, int i, PTree c) {
	//1≤i≤p
	int j, k, temp, flag = 1, n = 0;
	PTNode t;
	//j定位结点p
	for (j = 0; j < T.n; j++) {
		if (T.nodes[j].data == p) {
			break;
		}
	}
	//c是p的第1棵子树下移=j+1
	temp = j + 1;
	//如果c不是p的第1棵子树（判断起始）
	if (i > 1) {
		//先查找到+跳过p的i-1棵子树。
		for (k = j + 1; k < T.n; k++)
			//j+1开始，到总结点数目为止
			if (T.nodes[k].parent == j) {
				//找到一棵变记录个数
				n++;
				//找完前i-1棵p的子树则结束查找
				if (n == i - 1)
					break;
			}
		//temp记录p的第i棵子树位置（是第i棵，不是第k棵，k是作为总的来记录，i是指第几棵子树）
		temp = k + 1;
	}
	//插入点temp不在最后（判断收尾，后移）
	if (temp < T.n) {
		for (k = T.n - 1; k >= temp; k--) {
			//后移出c.n个位置，留给树c
			T.nodes[k + c.n] = T.nodes[k];
			//如果双亲位置
			if (T.nodes[k].parent >= temp)
				T.nodes[k + c.n].parent += c.n;
		}
	}
	//开始插入树c【temp是记录p的第i棵子树的总位置=k+j K是待插入的c的棵树】
	for (k = 0; k < c.n; k++) {
		T.nodes[temp + k].data = c.nodes[k].data;
		T.nodes[temp + k].parent = c.nodes[k].parent + temp;
	}
	//树c的根结点双亲为p【双亲也需要标记进去，j定位了结点P】
	T.nodes[temp].parent = j;
	// 树T结点数增加c.n个
	T.n += c.n;
	//插入完毕后，因是平移出c.n个空间直接将树c插入，故可能造成层序混乱
	while (flag) {
		//使存储仍按层序排列
		flag = 0; //设置交换标志 为0时说明整理完毕，符合层序结构
		for (j = temp; j < T.n - 1; j++) {
			if (T.nodes[j].parent > T.nodes[j + 1].parent) {
				//设置交换标志为1,因仍需交换孩子结点
				flag = 1;

				//结点j的双亲排在结点p+1的双亲后（层序混乱），交换两结点
				t = T.nodes[j];
				T.nodes[j] = T.nodes[j + 1];
				T.nodes[j + 1] = t;
				//开始交换孩子结点
				for (k = j; k < T.n; k++) {
					if (T.nodes[k].parent == j)
						T.nodes[k].parent++;
					else if (T.nodes[k].parent == j + 1)
						T.nodes[k].parent--;
				}
			}
		}
	}
}

//返回树T中序号为i的结点的值
 char Value(PTree T,int cur_e)    { 
  if(TreeEmpty(T)){return '\0';}   
  if(cur_e<T.n) 
    return T.nodes[cur_e].data;    
  else   
    return '\0';    
}    

void InitTree(PTree &T) {
	T.n = 0;
	T.r = 0;
}

//求树的深度
void InitTree(PTree &T) {
	T.n = 0;
	T.r = 0;
}
int TreeDepth(PTree &T) {
	int dp = 0, i,j = 0;
	PTNode *pn;
	if (TreeEmpty(T)) {
		return 0;
	} else {
		pn = T.nodes;
		for (i = 0; i < T.n; i++,j++) {
			if ((pn+j)->parent != (pn+j+1)->parent) {
				dp++;
			}
		}
		return dp;
	}
}

PTNode * LeftChild(PTree &T, int cur_e) {
	PTNode * lChildPN=NULL;
	if(cur_e>=T.n)
		return NULL;
	if(1+cur_e<T.n){
		lChildPN=T.nodes+cur_e+1;
		if(lChildPN->parent==cur_e){
			return lChildPN;
		}
		
	}
	return NULL;
}


//-----------------------
/*
 void DestroyTree(PTree &T){
 // can't do that.
 }
 */
//-----------------------
TElemType Root(PTree T) {
	//Condition:The tree is existing.
	//Result:Return the tree's root.
	for (int i = 0; i < T.n; i++)
		if (T.nodes[i].parent < 0)
			return T.nodes[i].data;
}
//-----------------------

int *RightSibling(PTree T, PTNode cur_e) {
	int d[MAX_TREE_SIZE],i=0,*p,t=0;
	int *q;
	q=&t;
	for(;i<T.n;i++)
		if(T.nodes[i].data== cur_e.data && T.nodes[i].parent==cur_e.parent)
			break;
	if(i==T.n)
		return q;
	i++;
	int n;
	for(n=0;i<T.n;i++)
		if(T.nodes[i].parent==cur_e.parent)
			d[n++]=i;
	d[n]=0;
	p=d;
	return p;
}


/** 弃用*/
void CreateTree(PTree &T) {
	char e;
	int pa, num;
	printf("Input num:");
	scanf("%d", &num);
	if (num == 0)
		return;
	else
		for (int i = 0; i < num; i++) {
			printf("Input data:");
			getchar();
		    scanf("%c", &e);
			printf("Input parent:");		
			scanf_s("%d", &pa);
			T.nodes[i].data = e;
			T.nodes[i].parent = pa;
			//dk,添加的
			if (pa == -1)
				T.r = i;
		}
	//dk,添加的
	T.n = num;
}
/** */
void CreateTree(PTree &T,PTNode *nodes,int n){
	for(int i=0;i<n;i++){
		T.nodes[i].data=nodes[i].data;
		T.nodes[i].parent =nodes[i].parent;
		if(nodes[i].parent==-1){
			T.r=i;
		}
	}
	T.n = n;
}
//TElemType Parent(PTree T,TElemType cur_e)
//{ 
//	int j;
//	for(j=1; j < T.n;j++)  
//		if(T.nodes[j].data == cur_e)
//			return T.nodes[T.nodes[j].parent].data;
//	return NULL;
//}

PTNode* Parent(PTree T,int cur_e)
{ 
	if(cur_e>=T.n)
		return NULL;
	PTNode* pp=T.nodes;
	int parent=T.nodes[cur_e].parent;
	return pp+parent;
}
void TraverseTree(PTree T,void(*Visit)(TElemType))
{ 
	int i;
	for(i=0;i<T.n;i++)
		Visit(T.nodes[i].data);
	printf("\n");
}

void vi(TElemType c)
{
   printf("%c ",c);
}


void ClearTree(PTree &T) {
	if (TreeEmpty(T))
		return;
	T.r=-1;
	T.n=0;

}
void Assign(PTree &T, int cur_e, TElemType value) { //书上没有用&,我觉得有点问题
	if (TreeEmpty(T))
		return;
	if (T.n > cur_e && cur_e >= 0) {
		T.nodes[cur_e].data = value;
	}
}


    PTree getNewTree();
    //1*、InitTree 通过
	void testInitTree(){
	    PTree T, p;
	    InitTree(T);
	    printf("Tree null? %d(1:Yes 0:No) Tree Root %c Tree deep %d\n",
			TreeEmpty(T), Root(T), TreeDepth(T));
	}
	//2*、Destroy
	//数组无法主动去销毁
	void testDestroy(){
	   printf("数据结构无法销毁！ ");
	}

	//3*、CreateTree,我修改过了，考虑到调用CreateTree方法，它的执行过程应该是透明的，我们不应该去操作，所以我把操作写在了main（）中。 通过
	void testCreateTree(){
		PTree createT;
		int num=0;
		printf("请输入新树的结点数目:");
		scanf("%d", &num);
		if(num<=0){
			printf("要大于0");
		}else{
			PTNode *nodes=(PTNode *)malloc(sizeof(PTNode)*num);
			for (int i = 0; i < num; i++) {
				printf("请输入结点数据:");
				getchar();
				scanf("%c", &nodes[i].data);
				printf("请输入双亲:");		
				scanf_s("%d", &nodes[i].parent);
			}
			CreateTree(createT,nodes,num);
			printf("树的根是： %c  \n树的深度是： %d\n",
				Root(createT), TreeDepth(createT));
			printf("该树各个结点为：");
			TraverseTree(createT,vi);
		}
	}
	 ////4*、ClearTree 通过
	void testClearTree(){
		  PTree clearTree=getNewTree();
		  printf("原来的树:\n");
		  TraverseTree(clearTree,vi);
		  ClearTree(clearTree);
		  printf("清空后该树为空:\n");
		  TraverseTree(clearTree,vi);
	}
	  //5*、TreeEmpty 通过
	void testTreeEmpty(){
		PTree EmptyTree=getNewTree();
		if(TreeEmpty(EmptyTree)){
			printf("空树\n");
		}
		else{
			printf("不是空树\n");
		}
		/*
		ClearTree(EmptyTree);
		if(TreeEmpty(EmptyTree)){
			printf("空树\n");
		}
		else{
			printf("不是空树\n");
		}*/
	}
	  //6*、TreeDepth    通过
	void testTreeDepth(){
		   PTree depthT=getNewTree();
		   InitTree(depthT);
		   TraverseTree(depthT,vi);
		   printf("树的深度是%d\n",TreeDepth(depthT));
	}

	  //7！、Root----修改返回值应该是节点（根） 通过
	  //printf("树的根是%c\n",Root(getNewTree()));

	  //8！、Value（T，cur_e） 通过
	  //printf("树的节点的值是%c\n",Value(getNewTree(),0));

	  //9！、Assign（T，cur_e,value）通过
	void testAssign(){
		  TElemType ae;
		  PTree aT=getNewTree();
		  printf("该树为:\n");
		  TraverseTree(aT,vi);
		  int cur_e;
		  printf("请输入要改变的结点下标：");
		  getchar();
		  scanf("%d",&cur_e);
		  printf("\n");
		  printf("请输入改变后的结点的值：");
		   getchar();
		  scanf("%c%*c",&ae);
		  printf("\n");
		  Assign(aT,cur_e,ae);
		  printf("修改后的树为:\n");
		  TraverseTree(aT,vi);
	}
		  //10！、Parent（T，cur_e）通过
	void testParent(){
		 PTree pT=getNewTree();
		 TraverseTree(pT,vi);
		 PTNode* parentN=Parent(pT,2);
		 if(parentN!=NULL)
		 printf("该结点的双亲结点是:%c\n",parentN->data);
	}
	  //11！、LeftChild（T，cur_e） ,通过
	 void testLeftChild(){
		  PTree lT=getNewTree();
		  TraverseTree(lT,vi);
		  int cur_e=2;
		  PTNode * lchidPN=LeftChild(lT,cur_e);
		  if(lchidPN!=NULL)
			printf("改结点的左孩子是： %c",lchidPN->data);
		  else
			  printf("%c没有左孩子",lT.nodes[cur_e]);
	}

	  //12！、RightSibling（T，cur_e）,修改---cur_e应该是节点类型PTNode，返回的类型不好说，建议是子树
	 void testRightSibling(){
		  PTree rT=getNewTree();
		  TraverseTree(rT,vi);
		  int cur_e=2;
		  int *p=RightSibling(rT,rT.nodes[cur_e]);
		  if(p==NULL)
			  printf("%c 没有右孩子",rT.nodes[cur_e]);
		   printf("%c的右孩子是：",rT.nodes[cur_e]);
		  for(;*p!=NULL;p++){  
			  printf("该结点的右孩子是： %c",rT.nodes[*p].data);	
		  }
	 }

	   //13！ InsertChild（&T，&P，i,c） 通过
	void testInsertChild(){
		   PTree tree1=getNewTree();
		   PTree tree2=getNewTree();
		   printf("Ceng BianLi Tree:\n");
		   TraverseTree(tree1,vi);
		   printf("\n");
		   TraverseTree(tree2,vi);
		   InsertChild(tree1,'b',1,tree2);
		   printf("插入后的结果\n");
		   TraverseTree(tree1,vi);
	 }

	   //14、DeleteChild（&T，&P，i） 此方法无意义且难以实现

	   //15TraverseTree   通过
	int testTraverseTree(){
		   PTree ttree=getNewTree();
		   printf("Ceng BianLi Tree:\n");
		   TraverseTree(ttree,vi);
		   return 0;
	 }
int main() { /* 主函数*/
	int select=0;
	do{
      printf("select 1 构造空树T InitTree(T)\n");
      printf("select 2 销毁树T DestroyTree（T）\n");
      printf("select 3 按definition构造树T creatTree(T)\n");
      printf("select 4 将树T清为空树 ClearTree(T)\n");
      printf("select 5 判断树是否为空 TreeEmpty(T)\n");
      printf("select 6 求树的深度 TreeDepth（T）\n");
      printf("select 7 树的根 Root(T)\n");
      printf("select 8 树种某个节点的值 Value(T)\n");
      printf("select 9 将树中某个节点赋值 Assign（T）\n");
      printf("select 10 返回某个节点的双亲 Parent(T)\n");
      printf("select 11 返回某个结点的左孩子 LeftChild(T)\n");
      printf("select 12 返回结点的右兄弟 RightSibling（T）\n");
      printf("select 13 插入子树 InsertChild(T)\n");
      printf("select 14 删除子树 Value(T)\n");
      printf("select 15 对结点调用函数 Value(T)\n");
      printf("input your select: ");
      scanf("%d",&select);
      switch(select) {
         case 1:testInitTree(); 		    
                 break;
         case 2:  testDestroy();
                  break;
         case 3: testCreateTree();
                  break;
         case 4:  testClearTree();
                  break;
		 case 5:  testTreeEmpty();
				break;
		 case 6: testTreeDepth();
			   break;
		 case 7: printf("树的根是%c\n",Root(getNewTree()));
			   break;
		 case 8: printf("树的节点的值是%c\n",Value(getNewTree(),0));
			 break;
		 case 9: testAssign();
			 break;
		 case 10:testParent();
			 break;
		 case 11: testLeftChild();
			 break;
		 case 12: testRightSibling();
			 break;
		 case 13:testInsertChild();
			   break;
		 case 14: printf("此方法无意义且难以实现！！");
			 break;
		 case 15:testTraverseTree();
			  break;
		 default:
			 select=30;
      }
	  printf("\n");
   } while (select>0 && select <16);

}

PTree getNewTree(){
	PTree myTree;
	myTree.n=4;
	myTree.r=0;
	int i=0;
	for(;i<3;i++){
		myTree.nodes[i].data=97+i;
		myTree.nodes[i].parent=i-1;
	}
	myTree.nodes[i].data='d';
	myTree.nodes[i].parent=1;
	return myTree;
}
