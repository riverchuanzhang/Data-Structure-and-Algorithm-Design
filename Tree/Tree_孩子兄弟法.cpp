#include <stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct CSNode {
	ElemType data;
	struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
//����������������
void InitTree(CSTree &T) {
	T = NULL;
}

/**��ʼ������������
 * �����ṹ��������
 * �����ɹ��򷵻�true�����򷵻�false;
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

//�˷���ΪCreateTree�����ĸ������������õݹ������㡣flag��Ϊ��ʾpNode�Ƿ�Ϊ����㣬flag=0��Ϊ����㣬Ϊ1��Ϊ����㡣ע�⣺������������ĺ��ӻ��ֵ�ֵʱ��������ո����ʾû�к��ӻ��ֵܡ�
void creatNodes(CSNode *pNode, int flag) {
	CSNode * childPNode;
	CSNode * brotherPNode;
	ElemType tempElem;
	printf("������%c�ĺ���(������һ���ַ�������ո��ʾû��)��", pNode->data);
	getchar();
	scanf("%c", &tempElem);
	if (tempElem != 0x20) {  //0x20:��ʾ�ո�
		childPNode = (CSNode *) malloc(sizeof(CSNode));
		childPNode->nextsibling=NULL;
		childPNode->firstchild=NULL;
		childPNode->data = tempElem;
		pNode->firstchild = childPNode;
		creatNodes(childPNode, 1);
	}
	if (flag == 0) //��Ϊ�Ǹ���㣬���Բ���Ҫ��ע�����ֵ�
		return;
	printf("������%c���ֵ�(������һ���ַ�������ո��ʾû��)��", pNode->data);
	getchar();
	scanf("%c", &tempElem);
	if (tempElem != 0x20) {  //0x20:��ʾ�ո�
		brotherPNode = (CSNode *) malloc(sizeof(CSNode));
		brotherPNode->firstchild=NULL;
		brotherPNode->nextsibling=NULL;
		brotherPNode->data = tempElem;
		pNode->nextsibling = brotherPNode;
		creatNodes(brotherPNode, 1);
	}

}

/**
 * ��������������û���Ҫ������
 * 
 */
void CreateTree(CSTree &T) {
	T = (CSNode *) malloc(sizeof(CSNode));
	T->firstchild=NULL;
	T->nextsibling=NULL;
	printf("������ͷ�ڵ�(������һ���ַ�������ո��ʾû��)��");
	getchar();
	scanf("%c", &(T->data));
	if(T->data!=0x20){
		creatNodes(T,0);
	}else{
		printf("ͷ���Ϊ��\n");
	}
	
}

/**��ʼ������������
 * ����������������
 * �����ɹ��򷵻�true�����򷵻�false;
 */
bool ClearTree(CSTree &T) {
	if (T != NULL) {
		T = NULL;
		return true;
	}
	return false;
}

/**
 * �������������Ϊ����������true�����򷵻�false
 * 
 */
bool TreeEmpty(CSTree &T) {
	if (T == NULL)
		return true;
	else
		return false;
}


/**��ʼ������������
 * ��������������������
 * 
 */
int TreeDepth(CSTree &T) {  //�ݹ���û�����
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
 *��ʼ������������
 * ����������������ĸ�
 */
CSNode Root(CSTree &T) {
	return *T;
}

/**
 *��ʼ������������
 *���������ͨ��cur_e������T���ҵ�����Ӧ�Ľ�㣬�Ҳ������ؿգ��ҵ��򷵻ظý��
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
 * ��ʼ�����������ڣ�cur_e������ĳ���ڵ��ֵ
 * �������������cur_e��ֵ
 */
ElemType Value(CSTree &T, ElemType cur_e) {
	if (!getNodeInTree(T, cur_e))
		return NULL;
	return cur_e;
}

/**
 * ��ʼ�����������ڣ�cur_e������ĳ���ڵ��ֵ
 * ���������cur_e��Ӧ�Ľ�㸳ֵΪvalue�������ɹ�����true������fasle
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
 * ��ʼ�����������ڣ�cur_e������ĳ���ڵ��ֵ
 * ���������cur_e��Ӧ�Ľ�������ķǸ�����򷵻�����˫�ף����򷵻ؿ�
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
 * ��ʼ�����������ڣ�cur_e������ĳ���ڵ��ֵ
 * ���������cur_e��Ӧ�Ľ���Ƿ�Ҷ�ӽ���򷵻����������ӣ����򷵻ؿ�
 */
CSNode *LeftChild(CSTree &T, ElemType cur_e) {
	CSNode *nodeP = getNodeInTree(T, cur_e);
	if (nodeP != NULL)
		return nodeP->firstchild;
	else
		return NULL;
}

/**
 * ��ʼ�����������ڣ�cur_e������ĳ���ڵ��ֵ
 * �����������cur_e��Ӧ�Ľ���������ֵ��򷵻��������ֵܣ����򷵻ؿ�
 * ע�ⷵ�ص����ֵܿ����ж��������������ָ����Щ�ֵܽڵ��ָ������
 */
CSTree* RightSibling(CSTree &T, ElemType cur_e) { //���ش��ָ��ڵ��ָ������
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
 * ��ʼ��������T���ڣ�pָ����T��ĳ����㣬1<=i<=p��ָ���Ķ�+1���ǿ���c��T���ཻ
 * �������������cΪ��T��pָ���ĵ�i����
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
 * ��ʼ��������T���ڣ�pָ����T��ĳ����㣬1<=i<=p��ָ���Ķ�
 * ���������ɾ������pָ���ĵ�i����
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
 * ��ʼ��������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
 * �����������ǰ��������T��ÿ�������ú���visit,һ�������һ�Ρ�һ��visitʧ�ܣ������ʧ��
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
 * ���ڲ��Եĺ���������������
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
	//1��InitTree �������  ͨ��
	printf("testInitTree()\n");
	printf("����");
	if(!TraverseTree(T,Vi))
		printf("����");
	printf("\n");
	printf("���÷�����\n");
	printf("��(ǰ��)��");
	InitTree(T);   //����Ϊ��
	if(!TraverseTree(T,Vi))
		printf("����");
}

void testDestoryTree(CSTree &T){
	//2��DestoryTree ������  �ͷſռ�
	printf("testDestoryTree()\n");
	printf("����");
	if(!TraverseTree(T,Vi))
		printf("����");
    printf("\n");
	printf("���÷�����\n");
	printf("��(ǰ��)��");
	DestoryTree(T);
	if(!TraverseTree(T,Vi))
		printf("����");
}

void testCreateTree(CSTree &T){
	//3��CreaTree  ͨ�� 
	printf("testCreateTree()\n");
	CreateTree(T);
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
}

void testClearTree(CSTree &T){
	//4��ClearTree �����  ͨ��
	printf("testClearTree()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	 printf("\n");
	printf("���÷�����\n");
	if(ClearTree(T))
		printf("�������");
	else
       printf("���ʧ��");
}

void testTreeEmpty(CSTree &T){
	//5��TreeEmpty
	printf("testTreeEmpty()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("���÷�����\n");
	if(TreeEmpty(T))
		printf("����");
	else
        printf("���ǿ���");
}

void testTreeDepth(CSTree &T){
//6��TreeDepth ���  ͨ�� ���ܻ��д�
	printf("testTreeDepth()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("���÷�����\n");
	printf("�����Ϊ%d",TreeDepth(T));
}

void testRooot(CSTree &T){
	//7��Root  ��  ͨ��
	printf("testRooot()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("���÷�����\n");
	printf("��Ϊ��%c",Root(T).data);
}

void testValue(CSTree &T){
	//8 Value    ͨ��
	printf("testValue()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType elem;
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ:");
	getchar();
	scanf("%s",&elem);
	ElemType myElem=Value(T,elem);
	printf("���÷�����\n");
	if(myElem!=NULL)
		printf("%c�����Ľ�㣬ֵΪ��%c",elem,myElem);
	else
	   printf("%c�������Ľ��",elem);

}

void testAssign(CSTree &T){
	//9 Assign ͨ��
	printf("testAssign()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType oldElem='k';
	ElemType newElem='A';
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������ԭ������ֵ�͸ı��ֵ:");
	getchar();
	scanf("%c,%c",&oldElem,&newElem);
	printf("���÷�����\n");
	if(!Assign(T,oldElem,newElem))
		printf("%c�������Ľ�㣬���Բ���ʧ��",oldElem);
	else 
		TraverseTree(T,Vi);

}

void testParent(CSTree &T){
	//10��Parent  ͨ��
	printf("testParent()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType childElem='p';
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ:");
	getchar();
	scanf("%c",&childElem);
	CSNode *parentPNode=Parent(T,childElem);
	printf("���÷�����\n");
	if(parentPNode!=NULL)
		printf("%c��˫����%c",childElem,parentPNode->data);
	else
		printf("�Ҳ���%c��˫��",childElem);
}

void testLeftChild(CSTree &T){
		//11��LeftChild  ͨ��
	printf("testLeftChild()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType parentElem;
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ:");
	getchar();
	scanf("%c",&parentElem);
	CSNode *childPNode=LeftChild(T,parentElem);
	printf("���÷�����\n");
	if(childPNode!=NULL)
       printf("%c��������%c",parentElem,childPNode->data);
	else
		printf("%cû������",parentElem);
}

void testRightSibling(CSTree &T){
	//12��RightSibling  ͨ��
	printf("testRightSibling()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType elem=NULL;
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ:");
	getchar();
	scanf("%c",&elem);
	CSTree *pNodes=RightSibling(T,elem);
	printf("���÷�����\n");
	if(pNodes!=NULL){
		 printf("%c�����ֵ��ǣ�",elem);
         for(int i=0;*(pNodes+i)!=NULL;i++){
			 printf("%c",(*(pNodes+i))->data);
		 }
	}else
		printf("%cû�����ֵ�",elem);
}

void testInsertChild(CSTree &T){
	//13��InsertChild ͨ��
	printf("testInsertChild()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType p=NULL;
	int i=0;
	CSTree addedTree=getTestTree();
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ�͵ڼ���:");
	getchar();
	scanf("%c,%d",&p,&i);
	printf("��ӵ�%d����\n",i);
	printf("���÷�����\n");
	InsertChild(T,p,i,addedTree);
	TraverseTree(T,Vi);
}

void testDeleteChild(CSTree &T){
	//14��DeleteChild
	printf("testDeleteChild()\n");
	if(TreeEmpty(T)){
		printf("����");
		return ;
	}
	ElemType p=NULL;
	int i=0;
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
	printf("\n");
	printf("������һ������ֵ�͵ڼ���:");
	getchar();
	scanf("%c,%d",&p,&i);
	printf("���÷�����\n");
	printf("ɾ����%d����",i);
	printf("\n");
	if(DeleteChild(T,p,i))
	  TraverseTree(T,Vi);
	else
		printf("ɾ��ʧ��");
}

void testTraverseTree(CSTree &T){
    //15��TraverseTree  ǰ�����  ͨ��
	printf("testTraverseTree()\n");
	printf("��(ǰ��)��");
	TraverseTree(T,Vi);
}


int main(){
	CSTree mainTree=NULL;
	int select=0;
	do{
      printf("select 1 ������� InitTree()\n");
      printf("select 2 ������ DestoryTree()\n");
      printf("select 3 ������ CreateTree()\n");
      printf("select 4 ����� ClearTree()\n");
      printf("select 5 �Ƿ�Ϊ���� TreeEmpty()\n");
      printf("select 6 ������� TreeDepth()\n");
      printf("select 7 ���ĸ� Root()\n");
      printf("select 8 ����ֵ Value()\n");
      printf("select 9 ����ĸ�ֵ Assign()\n");
      printf("select 10 ����˫�� Parent()\n");
      printf("select 11 �������� LeftChild()\n");
      printf("select 12 �����Һ��� RightSibling()\n");
      printf("select 13 �������� InsertChild()\n");
      printf("select 14 ɾ������ DeleteChild()\n");
      printf("select 15 ������ TraverseTree()\n");
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
