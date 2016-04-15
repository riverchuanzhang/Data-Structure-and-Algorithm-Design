
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

typedef struct PTNode { //���ṹ
	TElemType data;
	int parent; //˫��λ��
} PTNode;
typedef struct { //���ṹ
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; //����λ�úͽڵ���
} PTree;

//�ж����Ƿ��ǿ�����turbo c����ʵ�ֵ�ʱ������boolean trueҪ�ô�д������ eclipse�У�typedef char TElemType;  turbo c����typedef TElemType char;��
bool TreeEmpty(PTree T) {
	if (T.n == 0)
		return true;
	else
		return false;
}

//����c����Ϊ��T��ֵΪp�Ľ��ĵ�i������
void InsertChild(PTree &T, char p, int i, PTree c) {
	//1��i��p
	int j, k, temp, flag = 1, n = 0;
	PTNode t;
	//j��λ���p
	for (j = 0; j < T.n; j++) {
		if (T.nodes[j].data == p) {
			break;
		}
	}
	//c��p�ĵ�1����������=j+1
	temp = j + 1;
	//���c����p�ĵ�1���������ж���ʼ��
	if (i > 1) {
		//�Ȳ��ҵ�+����p��i-1��������
		for (k = j + 1; k < T.n; k++)
			//j+1��ʼ�����ܽ����ĿΪֹ
			if (T.nodes[k].parent == j) {
				//�ҵ�һ�ñ��¼����
				n++;
				//����ǰi-1��p���������������
				if (n == i - 1)
					break;
			}
		//temp��¼p�ĵ�i������λ�ã��ǵ�i�ã����ǵ�k�ã�k����Ϊ�ܵ�����¼��i��ָ�ڼ���������
		temp = k + 1;
	}
	//�����temp��������ж���β�����ƣ�
	if (temp < T.n) {
		for (k = T.n - 1; k >= temp; k--) {
			//���Ƴ�c.n��λ�ã�������c
			T.nodes[k + c.n] = T.nodes[k];
			//���˫��λ��
			if (T.nodes[k].parent >= temp)
				T.nodes[k + c.n].parent += c.n;
		}
	}
	//��ʼ������c��temp�Ǽ�¼p�ĵ�i����������λ��=k+j K�Ǵ������c�Ŀ�����
	for (k = 0; k < c.n; k++) {
		T.nodes[temp + k].data = c.nodes[k].data;
		T.nodes[temp + k].parent = c.nodes[k].parent + temp;
	}
	//��c�ĸ����˫��Ϊp��˫��Ҳ��Ҫ��ǽ�ȥ��j��λ�˽��P��
	T.nodes[temp].parent = j;
	// ��T���������c.n��
	T.n += c.n;
	//������Ϻ�����ƽ�Ƴ�c.n���ռ�ֱ�ӽ���c���룬�ʿ�����ɲ������
	while (flag) {
		//ʹ�洢�԰���������
		flag = 0; //���ý�����־ Ϊ0ʱ˵��������ϣ����ϲ���ṹ
		for (j = temp; j < T.n - 1; j++) {
			if (T.nodes[j].parent > T.nodes[j + 1].parent) {
				//���ý�����־Ϊ1,�����轻�����ӽ��
				flag = 1;

				//���j��˫�����ڽ��p+1��˫�׺󣨲�����ң������������
				t = T.nodes[j];
				T.nodes[j] = T.nodes[j + 1];
				T.nodes[j + 1] = t;
				//��ʼ�������ӽ��
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

//������T�����Ϊi�Ľ���ֵ
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

//���������
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


/** ����*/
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
			//dk,��ӵ�
			if (pa == -1)
				T.r = i;
		}
	//dk,��ӵ�
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
void Assign(PTree &T, int cur_e, TElemType value) { //����û����&,�Ҿ����е�����
	if (TreeEmpty(T))
		return;
	if (T.n > cur_e && cur_e >= 0) {
		T.nodes[cur_e].data = value;
	}
}


    PTree getNewTree();
    //1*��InitTree ͨ��
	void testInitTree(){
	    PTree T, p;
	    InitTree(T);
	    printf("Tree null? %d(1:Yes 0:No) Tree Root %c Tree deep %d\n",
			TreeEmpty(T), Root(T), TreeDepth(T));
	}
	//2*��Destroy
	//�����޷�����ȥ����
	void testDestroy(){
	   printf("���ݽṹ�޷����٣� ");
	}

	//3*��CreateTree,���޸Ĺ��ˣ����ǵ�����CreateTree����������ִ�й���Ӧ����͸���ģ����ǲ�Ӧ��ȥ�����������ҰѲ���д����main�����С� ͨ��
	void testCreateTree(){
		PTree createT;
		int num=0;
		printf("�����������Ľ����Ŀ:");
		scanf("%d", &num);
		if(num<=0){
			printf("Ҫ����0");
		}else{
			PTNode *nodes=(PTNode *)malloc(sizeof(PTNode)*num);
			for (int i = 0; i < num; i++) {
				printf("������������:");
				getchar();
				scanf("%c", &nodes[i].data);
				printf("������˫��:");		
				scanf_s("%d", &nodes[i].parent);
			}
			CreateTree(createT,nodes,num);
			printf("���ĸ��ǣ� %c  \n��������ǣ� %d\n",
				Root(createT), TreeDepth(createT));
			printf("�����������Ϊ��");
			TraverseTree(createT,vi);
		}
	}
	 ////4*��ClearTree ͨ��
	void testClearTree(){
		  PTree clearTree=getNewTree();
		  printf("ԭ������:\n");
		  TraverseTree(clearTree,vi);
		  ClearTree(clearTree);
		  printf("��պ����Ϊ��:\n");
		  TraverseTree(clearTree,vi);
	}
	  //5*��TreeEmpty ͨ��
	void testTreeEmpty(){
		PTree EmptyTree=getNewTree();
		if(TreeEmpty(EmptyTree)){
			printf("����\n");
		}
		else{
			printf("���ǿ���\n");
		}
		/*
		ClearTree(EmptyTree);
		if(TreeEmpty(EmptyTree)){
			printf("����\n");
		}
		else{
			printf("���ǿ���\n");
		}*/
	}
	  //6*��TreeDepth    ͨ��
	void testTreeDepth(){
		   PTree depthT=getNewTree();
		   InitTree(depthT);
		   TraverseTree(depthT,vi);
		   printf("���������%d\n",TreeDepth(depthT));
	}

	  //7����Root----�޸ķ���ֵӦ���ǽڵ㣨���� ͨ��
	  //printf("���ĸ���%c\n",Root(getNewTree()));

	  //8����Value��T��cur_e�� ͨ��
	  //printf("���Ľڵ��ֵ��%c\n",Value(getNewTree(),0));

	  //9����Assign��T��cur_e,value��ͨ��
	void testAssign(){
		  TElemType ae;
		  PTree aT=getNewTree();
		  printf("����Ϊ:\n");
		  TraverseTree(aT,vi);
		  int cur_e;
		  printf("������Ҫ�ı�Ľ���±꣺");
		  getchar();
		  scanf("%d",&cur_e);
		  printf("\n");
		  printf("������ı��Ľ���ֵ��");
		   getchar();
		  scanf("%c%*c",&ae);
		  printf("\n");
		  Assign(aT,cur_e,ae);
		  printf("�޸ĺ����Ϊ:\n");
		  TraverseTree(aT,vi);
	}
		  //10����Parent��T��cur_e��ͨ��
	void testParent(){
		 PTree pT=getNewTree();
		 TraverseTree(pT,vi);
		 PTNode* parentN=Parent(pT,2);
		 if(parentN!=NULL)
		 printf("�ý���˫�׽����:%c\n",parentN->data);
	}
	  //11����LeftChild��T��cur_e�� ,ͨ��
	 void testLeftChild(){
		  PTree lT=getNewTree();
		  TraverseTree(lT,vi);
		  int cur_e=2;
		  PTNode * lchidPN=LeftChild(lT,cur_e);
		  if(lchidPN!=NULL)
			printf("�Ľ��������ǣ� %c",lchidPN->data);
		  else
			  printf("%cû������",lT.nodes[cur_e]);
	}

	  //12����RightSibling��T��cur_e��,�޸�---cur_eӦ���ǽڵ�����PTNode�����ص����Ͳ���˵������������
	 void testRightSibling(){
		  PTree rT=getNewTree();
		  TraverseTree(rT,vi);
		  int cur_e=2;
		  int *p=RightSibling(rT,rT.nodes[cur_e]);
		  if(p==NULL)
			  printf("%c û���Һ���",rT.nodes[cur_e]);
		   printf("%c���Һ����ǣ�",rT.nodes[cur_e]);
		  for(;*p!=NULL;p++){  
			  printf("�ý����Һ����ǣ� %c",rT.nodes[*p].data);	
		  }
	 }

	   //13�� InsertChild��&T��&P��i,c�� ͨ��
	void testInsertChild(){
		   PTree tree1=getNewTree();
		   PTree tree2=getNewTree();
		   printf("Ceng BianLi Tree:\n");
		   TraverseTree(tree1,vi);
		   printf("\n");
		   TraverseTree(tree2,vi);
		   InsertChild(tree1,'b',1,tree2);
		   printf("�����Ľ��\n");
		   TraverseTree(tree1,vi);
	 }

	   //14��DeleteChild��&T��&P��i�� �˷���������������ʵ��

	   //15TraverseTree   ͨ��
	int testTraverseTree(){
		   PTree ttree=getNewTree();
		   printf("Ceng BianLi Tree:\n");
		   TraverseTree(ttree,vi);
		   return 0;
	 }
int main() { /* ������*/
	int select=0;
	do{
      printf("select 1 �������T InitTree(T)\n");
      printf("select 2 ������T DestroyTree��T��\n");
      printf("select 3 ��definition������T creatTree(T)\n");
      printf("select 4 ����T��Ϊ���� ClearTree(T)\n");
      printf("select 5 �ж����Ƿ�Ϊ�� TreeEmpty(T)\n");
      printf("select 6 ��������� TreeDepth��T��\n");
      printf("select 7 ���ĸ� Root(T)\n");
      printf("select 8 ����ĳ���ڵ��ֵ Value(T)\n");
      printf("select 9 ������ĳ���ڵ㸳ֵ Assign��T��\n");
      printf("select 10 ����ĳ���ڵ��˫�� Parent(T)\n");
      printf("select 11 ����ĳ���������� LeftChild(T)\n");
      printf("select 12 ���ؽ������ֵ� RightSibling��T��\n");
      printf("select 13 �������� InsertChild(T)\n");
      printf("select 14 ɾ������ Value(T)\n");
      printf("select 15 �Խ����ú��� Value(T)\n");
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
		 case 7: printf("���ĸ���%c\n",Root(getNewTree()));
			   break;
		 case 8: printf("���Ľڵ��ֵ��%c\n",Value(getNewTree(),0));
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
		 case 14: printf("�˷���������������ʵ�֣���");
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
