#include"head.h"

Status Visit(TElemType e){
	printf("%c ",e);
	return OK;
}

Status InitBiTree(BiTree &T){
	T=(BiTree)malloc(sizeof(BiTNode));
	if(T) return OK;
	else return ERROR;
}

Status CreateBiTree(BiTree &T, int definition){
	char ch;
	ch=getchar();
	switch(definition){
		case 1://����
		if (ch==' ')T=NULL;
		else{
			T=(BiTree)malloc(sizeof(BiTNode));
			T->data=ch;
			CreateBiTree(T->lchild,definition);
			CreateBiTree(T->rchild,definition);
		}
		return OK;break;
		case 2://����
		if (ch==' ') T=NULL;
		else{
			T=(BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild,definition);
			T->data=ch;
			CreateBiTree(T->rchild,definition);
		}
		return OK;break;
		case 3://����
		if (ch==' ') {T=NULL;}
		else{
			T=(BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild,definition);
			CreateBiTree(T->rchild,definition);
			T->data=ch;
		}
		return OK;break;
		default:return ERROR;
	}
}

Status BinTreeDel(BiTree &T){
	if(T){
		BinTreeDel(T->lchild);
		BinTreeDel(T->rchild);
		free(T);
	}
	return OK;
}

Status ClearBiTree(BiTree &T){
	BinTreeDel(T);
	T =NULL;
	return OK;
}

Status DestroyBiTree(BiTree &T){
	if(ClearBiTree(T)) return OK;
	else return ERROR;
}

Status BiTreeEmpty(BiTree T){
	if(T==NULL) return TRUE;
	else return FALSE;
}

int BiTreeDepth(BiTree T){
	int del,der;
	if(!T)
	return ERROR;
	else{
		del=BiTreeDepth(T->lchild);
		der=BiTreeDepth(T->rchild);
		if(del>der)return(del+1);
		else return(der+1);
	}
}

TElemType Root(BiTree T){
	if(T) return T->data;
	else return ' ';
}

TElemType Value(BiTree &T,BiTree e){
	return e->data;
}

Status Assign(BiTree &T,TElemType e,TElemType v){
	if(T->data==e){
		T->data=v;
		return OK;
	}else{
		if(T->lchild)
			if(Assign(T->lchild,e,v))
				return OK;
		if(T->rchild)
			if(Assign(T->rchild,e,v))
				return OK;
		return ERROR;
	}
}

Status Get(BiTree T,TElemType e,BiTNode &p){
	if(T&&T->data==e){
		p=*T;
		printf("a_%c",p.data);
		return OK;
	}else{
		if(T->lchild)
		if(Get(T->lchild,e,p))return OK;
		if(T->rchild)
		   if(Get(T->rchild,e,p))return OK;
		p.data=NULL;
		return ERROR;
	}
}

Status Parent(BiTree T,TElemType e,TElemType &parent){
	if((T->lchild&&T->lchild->data==e)||(T->rchild&&T->rchild->data==e)){
		parent=T->data;
		return OK;
	}else{
		if(T->lchild)
		if(Parent(T->lchild,e,parent))return OK;
		if(T->rchild)
		   if(Parent(T->rchild,e,parent))return OK;
		parent=NULL;
		return ERROR;
	}
}

Status LeftChild(BiTree T,TElemType e,TElemType &lchild){
	if(T->data==e){
		if(T->lchild) lchild=T->lchild->data;
		else lchild=NULL;
		return OK;
	}else{
		if(T->lchild)
			if(LeftChild(T->lchild,e,lchild))
				return OK;
		if(T->rchild)
			if(LeftChild(T->rchild,e,lchild))
				return OK;
		return ERROR;
	}
}

Status RightChild(BiTree T,TElemType e,TElemType &rchild){
	if(T->data==e){
		if(T->rchild) rchild=T->rchild->data;
		else rchild=NULL;
		return OK;
	}else{
		if(T->lchild)
			if(RightChild(T->lchild,e,rchild))
				return OK;
		if(T->rchild)
			if(RightChild(T->rchild,e,rchild))
				return OK;
		return ERROR;
	}
}

Status LeftSibling(BiTree T,TElemType e,TElemType &lsibling){
	if(T->rchild&&T->rchild->data==e){
		if(T->lchild)lsibling=T->lchild->data;
		else lsibling=NULL;
		return OK;
	}else{
		if(T->lchild)
			if(LeftSibling(T->lchild,e,lsibling))
				return OK;
		if(T->rchild)
			if(LeftSibling(T->rchild,e,lsibling))
				return OK;
		lsibling=NULL;
		return ERROR;
	}
}

Status RightSibling(BiTree T,TElemType e,TElemType &rsibling){
	if(T->lchild&&T->lchild->data==e){
		if(T->rchild)rsibling=T->rchild->data;
		else rsibling=NULL;
		return OK;
	}else{
		if(T->lchild)
			if(RightSibling(T->lchild,e,rsibling))
				return OK;
		if(T->rchild)
			if(RightSibling(T->rchild,e,rsibling))
				return OK;
		return ERROR;
	}
}

Status InsertChild(BiTree &T,TElemType e,int LR,TElemType v){
	BiTree p;
	if(T->data==e){
		if(LR==1) {
			InitBiTree(p);
			p->data=v;
			p->rchild=T->lchild;
			p->lchild=NULL;
			T->lchild=p;
		}
		if(LR==2) {
			InitBiTree(p);
			p->data=v;
			p->rchild=T->rchild;
			p->lchild=NULL;
			T->rchild=p;
		}
	return OK;
	}else{
		if(T->lchild)
			if(InsertChild(T->lchild,e,LR,v))
				return OK;
			if(T->rchild)
				if(InsertChild(T->rchild,e,LR,v))
					return OK;
		return ERROR;
	}
}



Status DeleteChild(BiTree T,BiTNode *p,int LR){
	if(p){
     if(LR==0) DestroyBiTree((BiTree)(p->lchild));/* ɾ�������� */
     else DestroyBiTree((BiTree)(p->rchild));/* ɾ�������� */  
     return TRUE;
   }
   return FALSE; 	
}

/*�������������*/
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}else return OK;
}

/*�������������*/
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
					if(InOrderTraverse(T->rchild,Visit))return OK;
	return ERROR;
	}else return OK;
}

/*�������������*/
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data))
					return OK;
	return ERROR;
	}else return OK;
}

/*��α���������*/
Status LevelTraverse(BiTree T,Status (*Visit)(TElemType)){
	BiTree p,Queue[MaxSize];
	int front,rear;
	front = rear=0;
	if(T !=NULL){
		rear =(rear+1)%MaxSize;
		Queue[rear] =T;
	}
	while (front!=rear){
		front =(front+1)%MaxSize;
		p =Queue[front];
		Visit(p->data);
		if(p->lchild !=NULL){
			rear = (rear+1)%MaxSize;
			Queue[rear] = p->lchild;
		}
		if(p->rchild !=NULL){
			rear = (rear+1)%MaxSize;
			Queue[rear] = p->rchild;
		}
	}
	return OK;
}


void main(){
	BiTree T;
	BiTNode *p;
	TElemType e;	
	int flag=0,tag=0;//tag����Ƿ������Ϊ�գ�0��ʾ��
	char flag2,flag3;
	printf("��ʼ��������(ÿ�����ֵΪchar���ͣ��ո��ʾ�ý������ӻ��Һ���Ϊ�գ�����:\n");
	printf("	 a\n	/\\\n	b c \n	/\\\n     null d\nҪ�γ����ϵĶ�����Ҫ����:ab�ո�d�ո�ո�c�ո�ո�س�\n");
	InitBiTree(T);
	printf("��ʼ��������OK!\n");
	
	while(1){
		printf("\n��ѡ�����(1.���򴴽�,2.���򴴽�,3.���򴴽�,4.��ն�����,5.�������,6.�������,7.�������,8.��α���,9.��������):\n");
		scanf("%d",&flag);
		getchar();//���ջس���
		if(tag==0&&flag!=1&&flag!=2&&flag!=3&&flag!=9){
		    printf("���ȴ������������ٽ��ж������ı���\n");
		    continue;
		}
		if(flag==1){
			tag=1;
			printf("���򴴽�������:\n");
			CreateBiTree(T,1);
			printf("���򴴽�������ok!\n");
		}else if(flag==2){
			tag=1;
			printf("�����������:\n");
			CreateBiTree(T,2);
			printf("���򴴽�������ok!\n");	
		}else if(flag==3){
			tag=1;
			printf("�����������:\n");
			CreateBiTree(T,3);
			printf("���򴴽�������ok!\n");
		}else if(flag==4){
			printf("�ж϶������Ƿ�Ϊ�գ�����Ϊ������ն�����:\n");
			if(!BiTreeEmpty(T)){
				  printf("�ж϶�������Ϊ��,����ն�����\n");
				  ClearBiTree(T);
				  printf("��ն������ɹ�!\n");
			}else{
				printf("������Ϊ�գ�������ն�����:\n");
			}
			tag=0;
		}else if(flag==5){
			tag=1;
			printf("�������������:");
			PreOrderTraverse(T,Visit);
			printf("\n�������������:%d\n",BiTreeDepth(T));
		}else if(flag==6){
			tag=1;
			printf("�������������:");//�������������
			InOrderTraverse(T,Visit);
			printf("\n�������������:%d\n",BiTreeDepth(T));
		}else if(flag==7){
			tag=1;
			printf("�������������:");
			PostOrderTraverse(T,Visit);
			printf("\n�������������:%d\n",BiTreeDepth(T));
		}else if(flag==8){
			tag=1;
			printf("\n��α���������:");
			LevelTraverse(T,Visit);
			printf("\n�������������:%d\n",BiTreeDepth(T));
		}else{
			break;
		}
	}
	

	
	while(1){
		printf("\n��ѡ�����²���(1Ϊ��ʾ���ڵ��dataֵ,2Ϊ�ı�ڵ��dataֵ,3Ϊ��ʾ�������Һ��Ӻ������ֵܡ�˫��,4ɾ�����ڵ��������,5ɾ�����ڵ����������6���ٶ�����,7Ϊ�˳�����):\n");
		scanf("%d",&flag);
		getchar();//���ջس���
		if(flag==1){
			if(BiTreeEmpty(T)){
				  printf("������Ϊ��!\n");
				  tag=0;
			}else{
				tag=1;
				printf("�������ĸ��ڵ��dataֵ��:%c\n",Root(T));
			}
		}else if(flag==2){
			tag=1;
			printf("\n������Ҫ�ı���ڵ��ԭdataֵ:");
			scanf("%c",&flag2);
			getchar();//���ջس���
			printf("\n������Ҫ�ı���ڵ����dataֵ:");
			scanf("%c",&flag3);
			getchar();//���ջس���
			Assign(T,flag2,flag3);
			printf("\n��������ԭdataֵΪ%c�Ľ���dataֵ�����%c\n",flag2,flag3);
			printf("�������������:\n");
			PreOrderTraverse(T,Visit);
			printf("\n");
		}else if(flag==3){
			tag=1;
			printf("\n������Ҫ��ʾ�Ľڵ��dataֵ:");
			scanf("%c",&flag2);
			getchar();//���ջس���
			Parent(T,flag2,e);
			if(e==NULL)printf("�ڵ�ֵΪ%c�Ľ��û��˫��\n",flag2);
			else printf("�ڵ�ֵΪ%c��˫�׵�dataֵ��:%c\n",flag2,e);
			LeftChild(T,flag2,e);
			if(e==NULL)printf("�ڵ�ֵΪ%c�Ľ��û������\n",flag2);
			else printf("�ڵ�ֵΪ%c�����ӵ�dataֵ��:%c\n",flag2,e);
			RightChild(T,flag2,e);
			if(e==NULL)printf("�ڵ�ֵΪ%c�Ľ��û���Һ���\n",flag2);
			else printf("�ڵ�ֵΪ%c���Һ��ӵ�dataֵ��:%c\n",flag2,e);
			LeftSibling(T,flag2,e);
			if(e==NULL)printf("�ڵ�ֵΪ%c�Ľ��û�����ֵ�\n",flag2);
			else printf("�ڵ�ֵΪ%c�����ֵܵ�dataֵ��:%c\n",flag2,e);
			RightSibling(T,flag2,e);
			if(e==NULL)printf("�ڵ�ֵΪ%c�Ľ��û�����ֵ�\n",flag2);
			else printf("�ڵ�ֵΪ%c�����ֵܵ�dataֵ��:%c\n",flag2,e);
		}else if(flag==4){
			tag=1;
			/*printf("\n������Ҫɾ���������Ľڵ��dataֵ:");
			scanf("%c",&flag2);
			getchar();//���ջس���
			//������Ӧ�Ľ��
			Get(T,flag2,*p);
			if(p->data==NULL){
				printf("�ö�����û�����Ӧ�Ľ��\n");
				continue;
			}else{*/
				printf("ɾ�����ڵ��������\n");
				DeleteChild(T,T,0);
				printf("�������");
				PreOrderTraverse(T,Visit);
				printf("\n");
			//}
		}else if(flag==5){
			tag=1;
			/*printf("\n������Ҫɾ���������Ľڵ��dataֵ:");
			scanf("%c",&flag2);
			getchar();//���ջس���
			//������Ӧ�Ľ��
			Get(T,flag2,*p);
			if(p->data==NULL){
				printf("�ö�����û�����Ӧ�Ľ��\n");
				continue;
			}else{*/
				printf("ɾ�����ڵ��������\n");
				DeleteChild(T,T,1);
				printf("�������");
				PreOrderTraverse(T,Visit);
				printf("\n");
			//}
		}else if(flag==6){
			printf("\n���ٶ�����:\n");
			DestroyBiTree(T);
			if(BiTreeEmpty(T))printf("�ٴ��жϳ��ж϶�����Ϊ�գ�֤���Ѿ������˶�����\n");	
		}else{
			break;
		}
	}
}