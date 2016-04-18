/*此头文件存放二叉树的结构定义，及其用AVL算法实现的操作，演示方法等*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include"conio.h"
#include<graphics.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define null NULL//#define NULL 0
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)>(b)) 
#define LH +1     //左高
#define EH 0      //等高
#define RH -1     //右高
typedef char TElemType;// 元素类型
typedef int Status;

//平衡二叉树的二叉链表构造

typedef struct BSTNode
{
    TElemType data;
    int bf; //结点的平衡因子                     
    struct BSTNode *lchild,*rchild;//左、右孩子指针
}BSTNode,*BSTree;

//函数声明　
void paintAVL(BSTree T,TElemType elem);//初始化一张图片并画出一棵二叉树，可标记结点。
void paint2AVL(BSTree T1,BSTree T2,TElemType elem);//初始化一张图片并画出两科二叉树，可标记结点。
void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
void paintSBTTree(BSTree T,int x,int y,int r,int h,int w);//用于
void showCreatBST(BSTree &T,char s[]);//逐步显示平衡二叉树的创建过程

void R_Rotate(BSTree &p);    //对以*p为根的二叉排序树作右旋处理
void L_Rotate(BSTree &p);    //对以*p为根的二叉排序树作左旋处理
void LeftBalance(BSTree &T); //对以指针Ｔ所指结点为根的二叉树作左平衡旋转处理
void RightBalance(BSTree &T);//对以指针Ｔ所指结点为根的二叉树作右平衡旋转处理
bool InsertAVL(BSTree &T,TElemType e,int &taller);//插入结点e
bool SearchBST(BSTree &T,TElemType key);//查找元素key是否在树Ｔ中
void PrintBST(BSTree T,int m);//按树状打印输出二叉树的元素
void CreatBST(BSTree &T);    //创建平衡二叉树
void CreatBST(BSTree &T,TElemType s[30]);    //创建平衡二叉树
void LeftBalance_div(BSTree &p,int &shorter);//删除结点时左平衡旋转处理
void RightBalance_div(BSTree &p,int &shorter);//删除结点时右平衡旋转处理
void Delete(BSTree q,BSTree &r,int &shorter);//删除结点
int DeleteAVL(BSTree &p,TElemType x,int &shorter);//平衡二叉树的删除操作
int compare(TElemType a,TElemType b);//a>b时返回1，a=b时返回0，a<b时返回-1
bool CombineAVL(BSTree &T1,BSTree& T2);//连接二叉树T2到T1中
void Devide_T(BSTree &T,BSTree &T1,TElemType key);////分裂二叉树，T1为小,T为大
int Search_min(BSTree T,BSTree &p,TElemType key0);
void DeleteNode(BSTree &T,TElemType e); //删除结点函数




//创建时显示,若要显示指针则输入c，若不要指针则c为NULL；
void paintAVL(BSTree T,TElemType c)
{
	
	void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
	int x,y,w,r,h;//(x,y)为圆心，w为子树间距
	
	initgraph(640,480);
	
    x=getmaxx()/2;	y=50; w=180;
	r=15;h=60;
   
	setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("平衡二叉树演示：");
    if(T)
	  paintWithMark(T,x,y,r,h,w,c);
	  //paintWithMark(T,x,y,r,h,w,c);
	else
	{
		moveto(x,y);
	    outtext("该树为空!");
	}
	getch();
	closegraph();
}
//显示棵树，T1，T2。可带箭头指示，用法如上。
void paint2AVL(BSTree T1,BSTree T2,TElemType c)
{
	
	void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
	int x,y,w,r,h;//(x,y)为圆心，w为子树间距
	
	initgraph(640,480);
	
    x=getmaxx()/2;	y=100; w=100;
	r=10;h=50;

    setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("平衡二叉树演示（拆分或合并）：");
	line(x,100,x,400);
    
	setcolor(WHITE);           /*插入字符char*/
    moveto(x/2-45,y-5);
	outtext("T1:");
	moveto(x+x/2-45,y-5);
	outtext("T2:");
	if(T1)
	  paintWithMark(T1,x/2,y,r,h,w,c);
	else
	 {
       moveto(x/2,y);
	   outtext("该树为空!");
	 }
	if(T2)
	  paintWithMark(T2,x+x/2,y,r,h,w,c);
	else
     {
       moveto(x+x/2,y);
	   outtext("该树为空!");
	 }

	getch();
	closegraph();
}

//带指示箭头的paintWithMark
void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c)
{ 
	//int h=60,r=10;
	if(T)
	{  
		setcolor(RED);
        circle(x,y,r); 
        setfillstyle(SOLID_FILL,RED);/*纯色填充*/
        floodfill(x,y,RED);
	    
		setcolor(WHITE);           /*插入字符char*/
        moveto(x-5,y-8);
		char a[2]={T->data,'\0'};
        outtext(a);
        
		setcolor(WHITE);
		//Sleep(500);
		if(T->lchild)
		{
			line(x,y+r,x-w/2,y+h);
		    paintWithMark(T->lchild,x-w/2,y+h+r,r,h,w/2,c);
		}
		
		if(T->rchild)
		{
			line(x,y+r,x+w/2,y+h);
		    paintWithMark(T->rchild,x+w/2,y+h+r,r,h,w/2,c);
	
		}
		//Sleep(500);
		 if(T->data==c)           //箭头
		{ 
			setcolor(YELLOW);
			line(x,y-r,x+r/2,y-2*r);
			line(x,y-r,x-r/2,y-2*r);
			line(x+r/2,y-2*r,x-r/2,y-2*r);
			 setfillstyle(SOLID_FILL,YELLOW);
			floodfill(x,y-r-2,YELLOW);
			setcolor(WHITE);
		}
	}

}
//按树状打印输出二叉树的元素,m表示结点所在层次,初次调用时m=o
void PrintBST(BSTree T,int m)
{
    int i;
    if(T->rchild) PrintBST(T->rchild,m+1);
    for(i = 1; i<=m; i++)  
        printf("     ");//打印 i 个空格以表示出层次
    printf("%d\n",T->data);//打印 T 元素,换行 
    if(T->lchild) 
        PrintBST(T->lchild,m+1);
   
}

//对以*p为根的二叉排序树作右旋处理
void R_Rotate(BSTree &p) 
{
    BSTree lc;             
    lc = p->lchild;         //lc指向的*p左子树根结点
    p->lchild = lc->rchild; //rc的右子树挂接为*p的左子树
    lc->rchild = p; p = lc; //p指向新的结点
}

//对以*p为根的二叉排序树作左旋处理
void L_Rotate(BSTree &p) 
{
    BSTree rc;             
    rc = p->rchild;         //rc指向的*p右子树根结点
    p->rchild = rc->lchild; //rc的左子树挂接为*p的右子树
    rc->lchild = p; p = rc; //p指向新的结点
}

//对以指针Ｔ所指结点为根的二叉树作左平衡旋转处理
void LeftBalance(BSTree &T)
{
    BSTree lc,rd;
    lc = T->lchild;          //lc指向*T的左子树根结点
    switch(lc->bf)           //检查*T的左子树的平衡度，并作相应平衡处理
    {
    case LH:                 //新结点插入在*T的左孩子的左子树上，要作单右旋处理
        T->bf = lc->bf = EH;
        R_Rotate(T);  break;
    case RH:                 //新结点插入在*T的左孩子的右子树上，要作双旋处理
        rd = lc->rchild;     //rd指向*T的左孩子的右子树根
        switch(rd->bf)       //修改*T及其左孩子的平衡因子
        {
        case LH:T->bf = RH; lc->bf = EH; break;
        case EH:T->bf = lc->bf = EH; break;
        case RH:T->bf = EH; lc->bf = LH; break;
        }
        rd->bf = EH;
        L_Rotate(T->lchild); //对*T的左子树作左旋平衡处理
        R_Rotate(T);         //对*T作右旋平衡处理
    }
}

//对以指针Ｔ所指结点为根的二叉树作右平衡旋转处理
void RightBalance(BSTree &T)
{
    BSTree rc,ld;
    rc = T->rchild;         //rc指向*T的左子树根结点
    switch(rc->bf)          //检查*T的右子树的平衡度，并作相应平衡处理
    {
    case RH:                //新结点插入在*T的右孩子的右子树上，要作单左旋处理
        T->bf = rc->bf =EH;
        L_Rotate(T); break;
    case LH:                //新结点插入在*T的右孩子的左子树上，要作双旋处理
        ld = rc->lchild;    //ld指向*T的右孩子的左子树根
        switch(ld->bf)      //修改*T及其右孩子的平衡因子
        {
        case LH: T->bf = EH; rc->bf = RH; break;
        case EH: T->bf = rc->bf =EH; break;
        case RH: T->bf = LH; rc->bf = EH; break;
        }
        ld->bf = EH;
        R_Rotate(T->rchild);//对*T的右子树作左旋平衡处理
        L_Rotate(T);        //对*T作左旋平衡处理
    }
}

//插入结点e,若Ｔ中存在和e相同关键字的结点，则插入一个数据元素为e的新结点，并返回１，否则返回０
bool InsertAVL(BSTree &T,TElemType e,int &taller)
{
	//	printf("eeeee=%d,==%c",e,e);
    if(!T)//插入新结点，树“长高”，置taller为true
    {
        T = (BSTree)malloc(sizeof(BSTNode)); 
        T->data = e;
        T->lchild = T->rchild =NULL;
        T->bf = EH; taller = 1;
    }
    else
    {   int res=compare(e,T->data);
//	printf("e=%d,T->data=%d",e,T->data);
        if(res==0)                 //树中已存在和有相同关键字的结点
        { taller = 0;
		  printf("\t已存在相同关键字的结点%c\n",T->data); 
		return 0; }//则不再插入
        if(res==-1)                 //应继续在*T的左子树中进行搜索
        {
            if(!InsertAVL(T->lchild,e,taller)) return 0;//未插入
            if(taller)                    //已插入到*T的左子树中且左子树“长高”
                switch(T->bf)             //检查*T的平衡度
        	{
                  case LH:                //原本左子树比右子树高，需要作左平衡处理
                      LeftBalance(T); taller = 0; break;
                  case EH:                //原本左子树、右子等高，现因左子树增高而使树增高
                      T->bf = LH; taller = 1; break;
                  case RH:                //原本右子树比左子树高，现左、右子树等高
                      T->bf = EH; taller = 0; break;
            }//switch(T->bf)
        }//if
        else                              //应继续在*T的右子树中进行搜索
        {
            if(!InsertAVL(T->rchild,e,taller)) return 0;//未插入
            if(taller)                    //已插入到*T的右子树中且右子树“长高”
                switch(T->bf)             //检查*T的平衡度
        	{
                   case LH:               //原本左子树比右子树高，现左、右子树等高
                       T->bf = EH; taller = 0; break;
                   case EH:               //原本左子树、右子等高，现因右子树增高而使树增高
                       T->bf = RH; taller = true; break;
                   case RH:               //原本右子树比左子树高，需要作右平衡处理
                       RightBalance(T); taller = 0; break;
            }//switch(T->bf)
        }//else
    }//else
    return 1;
}//InsertAVL

//查找元素key是否在树Ｔ中
bool SearchBST(BSTree &T,TElemType key)
{	
	
    if(!T) return false;
	else{
		int res=compare(key,T->data);
		if(res==0) return true;
		else if(res==-1) return SearchBST(T->lchild,key);
		else return SearchBST(T->rchild,key);
	}

}
//创建平衡二叉树
void CreatBST(BSTree &T)
{
    //char e,m;
	char s[40];
	int i=0;
    int taller=0;
    T = NULL;
    printf("\t请输入关键字:");
	scanf("%s",s);
    while(*(s+i)!='*'&&*(s+i)!='\0')
    {	
		//printf("dddd==%c ",e); 
        InsertAVL(T,*(s+i),taller);
        //printf("\n请输入关键字:");
        //scanf("%c",&e);getchar();
		taller=false;
		i++;
    }
   // m=0;
    if(!T) printf("\t这是一棵空树.\n");
	

}
//删除结点时左平衡旋转处理
void LeftBalance_div(BSTree &p,int &shorter)
{
	BSTree  p1,p2;
	if(p->bf==1) //p结点的左子树高，删除结点后p的bf减1,树变矮
	{ p->bf=0; shorter=1; }
	else if(p->bf==0)//p结点左、右子树等高，删除结点后p的bf减1,树高不变
	{ p->bf=-1; shorter=0; }
	else  //p结点的右子树高
	{
		p1=p->rchild;//p1指向p的右子树
		if(p1->bf==0)//p1结点左、右子树等高,删除结点后p的bf为-2,进行左旋处理，树高不变
		{
			L_Rotate(p);
			p1->bf=1; p->bf=-1; shorter=0;
        }
		else if(p1->bf==-1)//p1的右子树高，左旋处理后，树变矮
        {
			L_Rotate(p);
            p1->bf=p->bf=0; shorter=1;
        }
		else //p1的左子树高,进行双旋处理(先右旋后左旋)，树变矮
        {
			p2=p1->lchild;
			p1->lchild=p2->rchild; p2->rchild=p1; p->rchild=p2->lchild; p2->lchild=p;
			if(p2->bf==0)
			{ p->bf=0; p1->bf=0; }
			else if(p2->bf==-1)
			{ p->bf=1;p1->bf=0; }
			else 
			{ p->bf=0;p1->bf=-1; }
            p2->bf=0; p=p2; shorter=1;
		}
  }

}

//删除结点时右平衡旋转处理
void RightBalance_div(BSTree &p,int &shorter)
{
	BSTree  p1,p2;
	if(p->bf==-1)
	{ p->bf=0; shorter=1; }
    else if(p->bf==0)
	{ p->bf=1; shorter=0; }
    else
    { 
		p1=p->lchild;
        if(p1->bf==0)
        {
			R_Rotate(p);
            p1->bf=-1; p->bf=1; shorter=0;
		}
        else if(p1->bf==1)
        {
			R_Rotate(p);
            p1->bf=p->bf=0; shorter=1;
        }
        else
        {
            p2=p1->rchild;
            p1->rchild=p2->lchild; p2->lchild=p1; p->lchild=p2->rchild; p2->rchild=p;
            if(p2->bf==0)
            { p->bf=0; p1->bf=0; }
            else if(p2->bf==1)
            { p->bf=-1; p1->bf=0; }
            else 
            { p->bf=0; p1->bf=1; }
            p2->bf=0; p=p2; shorter=1;
		}
	}
}
//删除结点
void Delete(BSTree q,BSTree  &r,int &shorter)
{
	if(r->rchild==NULL)
    {
		q->data=r->data; q=r;
        r=r->lchild; free(q);
        shorter=1;
	}
    else 
    { 
		Delete(q,r->rchild,shorter);
        if(shorter==1) 
			RightBalance_div(r,shorter);
	}
}

//平衡二叉树的删除操作
int DeleteAVL(BSTree &p,TElemType x,int &shorter)
{
	int k;
    BSTree q;
    if(p==NULL)  { printf("不存在要删除的关键字!!\n"); return 0;}
    else if(x<p->data)//在p的左子树中进行删除
    { 
		k=DeleteAVL(p->lchild,x,shorter);
        if(shorter==1)
			LeftBalance_div(p,shorter);
		return k;
	}
	else if(x>p->data)//在p的右子树中进行删除
    {
		k=DeleteAVL(p->rchild,x,shorter);
		if(shorter==1)
			RightBalance_div(p,shorter);
		return k;
	}
	else
	{
		q=p;
		if(p->rchild==NULL) //右子树空则只需重接它的左子树
		{ p=p->lchild; free(q); shorter=1; }
        else if(p->lchild==NULL)//左子树空则只需重接它的右子树
		{ p=p->rchild; free(q); shorter=1; }
        else//左右子树均不空
        {
			Delete(q,q->lchild,shorter);
			if(shorter==1)
				LeftBalance_div(p,shorter);
			p=q; 
		}
       return 1;
	}
}

int compare(TElemType a,TElemType b){//a>b时返回1，a=b时返回0，a<b时返回-1
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

//连接二叉树T2到T1中
bool CombineAVL(BSTree &T1,BSTree& T2){
 int taller=0;
 if(!T2)return true;
 if(T2->lchild) CombineAVL(T1,T2->lchild);
 if(T2->rchild) CombineAVL(T1,T2->rchild);
 if(!InsertAVL(T1,T2->data,taller)) return false;
 return true;
}



//*****************************************************************
//创建时显示,若要显示指针则输入c，若不要指针则c为NULL；

/*带指示箭头的paintWithMark(带Sleep)
 起始圆心为（x，y）半径为r，父子树间距为h，子树之间距为w
 标志data为 c的结点。

*/
void paintSBTTree(BSTree T,int x,int y,int r,int h,int w)
{ 
	//int h=60,r=10;
	if(T)
	{  
		setcolor(RED);
        circle(x,y,r); 
        setfillstyle(SOLID_FILL,RED);/*纯色填充*/
        floodfill(x,y,RED);	    
		setcolor(WHITE);           /*插入字符char*/
        moveto(x-5,y-8);
		char a[2]={T->data,'\0'};
        outtext(a);        
		setcolor(WHITE);		
		 if(T->lchild)
		{
			line(x,y+r,x-w/2,y+h);
		    paintSBTTree(T->lchild,x-w/2,y+h+r,r,h,w/2);
		}		
		if(T->rchild)
		{
			line(x,y+r,x+w/2,y+h);
		    paintSBTTree(T->rchild,x+w/2,y+h+r,r,h,w/2);
	
		}
	
	}

}


void showCreatBST(BSTree &T,char s[])
{   

    initgraph(640,480);
    int x,y,w,r,h;//(x,y)为圆心，w为子树间距
	x=getmaxx()/2;	y=50; w=180;
	r=15;h=60;
	
    setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("平衡二叉树创建过程演示：(按任意键继续)");
		
	int i=0;
    int taller=0;
    T = NULL;
    
    while(*(s+i)!='*'&&*(s+i)!='\0')
    {	
		
        //InsertAVL(T,*(s+i),taller);
        moveto(25,35);
	    outtext("未插入的节点：");
		moveto(25,55);
	    outtext((s+i));
        
        InsertAVL(T,*(s+i),taller);
	    //Sleep(2000);
		getch();
	    cleardevice();
	    moveto(15,15);
	    outtext("平衡二叉树创建过程演示：(按任意键继续)");
	    paintSBTTree(T,x,y,r,h,w);

		taller=false;
		i++;
    }
	 moveto(25,35);
	 outtext("未插入的节点：无");
	 setcolor(RED);
	 moveto(25,55);
	 outtext("创建完成！");

   // m=0;
    getch();
	closegraph();

}


void devide(BSTree &T,TElemType lower[30],TElemType higher[30],int &i,int &j,TElemType key){
//	printf("data=%c",T->data);
	if(T->data>key) {higher[j]=T->data;j++;}
    else  {lower[i]=T->data;i++;}
	if(T->lchild)devide(T->lchild,lower,higher, i,j,key);
	if(T->rchild)devide(T->rchild,lower,higher, i,j,key);
}


void devide_BSTree(BSTree &T,BSTree &T1,BSTree &T2,TElemType key)
{ int i=0;
   
   if (T!=NULL){
      devide_BSTree(T->lchild,T1,T2,key);
      if(LQ(T->data,key)) InsertAVL(T1,T->data,i) ;
      else   InsertAVL(T2,T->data,i) ;
      devide_BSTree(T->rchild,T1,T2,key);
              }
      }


void CreatBST(BSTree &T,TElemType s[30]){

	int i=0;
    int taller=0;
    T = NULL;

    while(*(s+i)!='*'&&*(s+i)!='\0')
    {	
		//printf("dddd==%c ",e); 
        InsertAVL(T,*(s+i),taller);
        //printf("\n请输入关键字:");
        //scanf("%c",&e);getchar();
		taller=false;
		i++;
    }
    if(!T) printf("\t这是一棵空树.\n");


}
