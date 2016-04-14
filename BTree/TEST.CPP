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
		case 1://先序
		if (ch==' ')T=NULL;
		else{
			T=(BiTree)malloc(sizeof(BiTNode));
			T->data=ch;
			CreateBiTree(T->lchild,definition);
			CreateBiTree(T->rchild,definition);
		}
		return OK;break;
		case 2://中序
		if (ch==' ') T=NULL;
		else{
			T=(BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild,definition);
			T->data=ch;
			CreateBiTree(T->rchild,definition);
		}
		return OK;break;
		case 3://后序
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
     if(LR==0) DestroyBiTree((BiTree)(p->lchild));/* 删除左子树 */
     else DestroyBiTree((BiTree)(p->rchild));/* 删除右子树 */  
     return TRUE;
   }
   return FALSE; 	
}

/*先序遍历二叉树*/
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}else return OK;
}

/*中序遍历二叉树*/
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
					if(InOrderTraverse(T->rchild,Visit))return OK;
	return ERROR;
	}else return OK;
}

/*后序遍历二叉树*/
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType)){
	if(T){
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data))
					return OK;
	return ERROR;
	}else return OK;
}

/*层次遍历二叉树*/
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
	int flag=0,tag=0;//tag标记是否二叉树为空，0表示空
	char flag2,flag3;
	printf("初始化二叉树(每个结点值为char类型，空格表示该结点的左孩子或右孩子为空，例如:\n");
	printf("	 a\n	/\\\n	b c \n	/\\\n     null d\n要形成以上的二叉树要输入:ab空格d空格空格c空格空格回车\n");
	InitBiTree(T);
	printf("初始化二叉树OK!\n");
	
	while(1){
		printf("\n请选择操作(1.先序创建,2.中序创建,3.后序创建,4.清空二叉树,5.先序遍历,6.中序遍历,7.后序遍历,8.层次遍历,9.其他操作):\n");
		scanf("%d",&flag);
		getchar();//接收回车键
		if(tag==0&&flag!=1&&flag!=2&&flag!=3&&flag!=9){
		    printf("请先创建二叉树，再进行二叉树的遍历\n");
		    continue;
		}
		if(flag==1){
			tag=1;
			printf("先序创建二叉树:\n");
			CreateBiTree(T,1);
			printf("先序创建二叉树ok!\n");
		}else if(flag==2){
			tag=1;
			printf("中序构造二叉树:\n");
			CreateBiTree(T,2);
			printf("中序创建二叉树ok!\n");	
		}else if(flag==3){
			tag=1;
			printf("后序构造二叉树:\n");
			CreateBiTree(T,3);
			printf("后序创建二叉树ok!\n");
		}else if(flag==4){
			printf("判断二叉树是否为空，若不为空则清空二叉树:\n");
			if(!BiTreeEmpty(T)){
				  printf("判断二叉树不为空,故清空二叉树\n");
				  ClearBiTree(T);
				  printf("清空二叉树成功!\n");
			}else{
				printf("二叉树为空，无需清空二叉树:\n");
			}
			tag=0;
		}else if(flag==5){
			tag=1;
			printf("先序遍历二叉树:");
			PreOrderTraverse(T,Visit);
			printf("\n二叉树的深度是:%d\n",BiTreeDepth(T));
		}else if(flag==6){
			tag=1;
			printf("中序遍历二叉树:");//先序遍历二叉树
			InOrderTraverse(T,Visit);
			printf("\n二叉树的深度是:%d\n",BiTreeDepth(T));
		}else if(flag==7){
			tag=1;
			printf("后序遍历二叉树:");
			PostOrderTraverse(T,Visit);
			printf("\n二叉树的深度是:%d\n",BiTreeDepth(T));
		}else if(flag==8){
			tag=1;
			printf("\n层次遍历二叉树:");
			LevelTraverse(T,Visit);
			printf("\n二叉树的深度是:%d\n",BiTreeDepth(T));
		}else{
			break;
		}
	}
	

	
	while(1){
		printf("\n请选择以下操作(1为显示根节点的data值,2为改变节点的data值,3为演示查找左右孩子和左右兄弟、双亲,4删除根节点的左子树,5删除根节点的右子树，6销毁二叉树,7为退出操作):\n");
		scanf("%d",&flag);
		getchar();//接收回车键
		if(flag==1){
			if(BiTreeEmpty(T)){
				  printf("二叉树为空!\n");
				  tag=0;
			}else{
				tag=1;
				printf("二叉树的根节点的data值是:%c\n",Root(T));
			}
		}else if(flag==2){
			tag=1;
			printf("\n请输入要改变根节点的原data值:");
			scanf("%c",&flag2);
			getchar();//接收回车键
			printf("\n请输入要改变根节点的新data值:");
			scanf("%c",&flag3);
			getchar();//接收回车键
			Assign(T,flag2,flag3);
			printf("\n二叉树的原data值为%c的结点的data值变成了%c\n",flag2,flag3);
			printf("先序遍历二叉树:\n");
			PreOrderTraverse(T,Visit);
			printf("\n");
		}else if(flag==3){
			tag=1;
			printf("\n请输入要演示的节点的data值:");
			scanf("%c",&flag2);
			getchar();//接收回车键
			Parent(T,flag2,e);
			if(e==NULL)printf("节点值为%c的结点没有双亲\n",flag2);
			else printf("节点值为%c的双亲的data值是:%c\n",flag2,e);
			LeftChild(T,flag2,e);
			if(e==NULL)printf("节点值为%c的结点没有左孩子\n",flag2);
			else printf("节点值为%c的左孩子的data值是:%c\n",flag2,e);
			RightChild(T,flag2,e);
			if(e==NULL)printf("节点值为%c的结点没有右孩子\n",flag2);
			else printf("节点值为%c的右孩子的data值是:%c\n",flag2,e);
			LeftSibling(T,flag2,e);
			if(e==NULL)printf("节点值为%c的结点没有左兄弟\n",flag2);
			else printf("节点值为%c的左兄弟的data值是:%c\n",flag2,e);
			RightSibling(T,flag2,e);
			if(e==NULL)printf("节点值为%c的结点没有右兄弟\n",flag2);
			else printf("节点值为%c的右兄弟的data值是:%c\n",flag2,e);
		}else if(flag==4){
			tag=1;
			/*printf("\n请输入要删除左子树的节点的data值:");
			scanf("%c",&flag2);
			getchar();//接收回车键
			//查找相应的结点
			Get(T,flag2,*p);
			if(p->data==NULL){
				printf("该二叉树没有相对应的结点\n");
				continue;
			}else{*/
				printf("删除根节点的左子树\n");
				DeleteChild(T,T,0);
				printf("先序遍历");
				PreOrderTraverse(T,Visit);
				printf("\n");
			//}
		}else if(flag==5){
			tag=1;
			/*printf("\n请输入要删除右子树的节点的data值:");
			scanf("%c",&flag2);
			getchar();//接收回车键
			//查找相应的结点
			Get(T,flag2,*p);
			if(p->data==NULL){
				printf("该二叉树没有相对应的结点\n");
				continue;
			}else{*/
				printf("删除根节点的右子树\n");
				DeleteChild(T,T,1);
				printf("先序遍历");
				PreOrderTraverse(T,Visit);
				printf("\n");
			//}
		}else if(flag==6){
			printf("\n销毁二叉树:\n");
			DestroyBiTree(T);
			if(BiTreeEmpty(T))printf("再次判断出判断二叉树为空，证明已经销毁了二叉树\n");	
		}else{
			break;
		}
	}
}
