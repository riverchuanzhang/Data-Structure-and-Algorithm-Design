/*��ͷ�ļ���Ŷ������Ľṹ���壬������AVL�㷨ʵ�ֵĲ�������ʾ������*/
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
#define LH +1     //���
#define EH 0      //�ȸ�
#define RH -1     //�Ҹ�
typedef char TElemType;// Ԫ������
typedef int Status;

//ƽ��������Ķ���������

typedef struct BSTNode
{
    TElemType data;
    int bf; //����ƽ������                     
    struct BSTNode *lchild,*rchild;//���Һ���ָ��
}BSTNode,*BSTree;

//����������
void paintAVL(BSTree T,TElemType elem);//��ʼ��һ��ͼƬ������һ�ö��������ɱ�ǽ�㡣
void paint2AVL(BSTree T1,BSTree T2,TElemType elem);//��ʼ��һ��ͼƬ���������ƶ��������ɱ�ǽ�㡣
void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
void paintSBTTree(BSTree T,int x,int y,int r,int h,int w);//����
void showCreatBST(BSTree &T,char s[]);//����ʾƽ��������Ĵ�������

void R_Rotate(BSTree &p);    //����*pΪ���Ķ�������������������
void L_Rotate(BSTree &p);    //����*pΪ���Ķ�������������������
void LeftBalance(BSTree &T); //����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
void RightBalance(BSTree &T);//����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
bool InsertAVL(BSTree &T,TElemType e,int &taller);//������e
bool SearchBST(BSTree &T,TElemType key);//����Ԫ��key�Ƿ���������
void PrintBST(BSTree T,int m);//����״��ӡ�����������Ԫ��
void CreatBST(BSTree &T);    //����ƽ�������
void CreatBST(BSTree &T,TElemType s[30]);    //����ƽ�������
void LeftBalance_div(BSTree &p,int &shorter);//ɾ�����ʱ��ƽ����ת����
void RightBalance_div(BSTree &p,int &shorter);//ɾ�����ʱ��ƽ����ת����
void Delete(BSTree q,BSTree &r,int &shorter);//ɾ�����
int DeleteAVL(BSTree &p,TElemType x,int &shorter);//ƽ���������ɾ������
int compare(TElemType a,TElemType b);//a>bʱ����1��a=bʱ����0��a<bʱ����-1
bool CombineAVL(BSTree &T1,BSTree& T2);//���Ӷ�����T2��T1��
void Devide_T(BSTree &T,BSTree &T1,TElemType key);////���Ѷ�������T1ΪС,TΪ��
int Search_min(BSTree T,BSTree &p,TElemType key0);
void DeleteNode(BSTree &T,TElemType e); //ɾ����㺯��




//����ʱ��ʾ,��Ҫ��ʾָ��������c������Ҫָ����cΪNULL��
void paintAVL(BSTree T,TElemType c)
{
	
	void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
	int x,y,w,r,h;//(x,y)ΪԲ�ģ�wΪ�������
	
	initgraph(640,480);
	
    x=getmaxx()/2;	y=50; w=180;
	r=15;h=60;
   
	setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("ƽ���������ʾ��");
    if(T)
	  paintWithMark(T,x,y,r,h,w,c);
	  //paintWithMark(T,x,y,r,h,w,c);
	else
	{
		moveto(x,y);
	    outtext("����Ϊ��!");
	}
	getch();
	closegraph();
}
//��ʾ������T1��T2���ɴ���ͷָʾ���÷����ϡ�
void paint2AVL(BSTree T1,BSTree T2,TElemType c)
{
	
	void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c);
	int x,y,w,r,h;//(x,y)ΪԲ�ģ�wΪ�������
	
	initgraph(640,480);
	
    x=getmaxx()/2;	y=100; w=100;
	r=10;h=50;

    setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("ƽ���������ʾ����ֻ�ϲ�����");
	line(x,100,x,400);
    
	setcolor(WHITE);           /*�����ַ�char*/
    moveto(x/2-45,y-5);
	outtext("T1:");
	moveto(x+x/2-45,y-5);
	outtext("T2:");
	if(T1)
	  paintWithMark(T1,x/2,y,r,h,w,c);
	else
	 {
       moveto(x/2,y);
	   outtext("����Ϊ��!");
	 }
	if(T2)
	  paintWithMark(T2,x+x/2,y,r,h,w,c);
	else
     {
       moveto(x+x/2,y);
	   outtext("����Ϊ��!");
	 }

	getch();
	closegraph();
}

//��ָʾ��ͷ��paintWithMark
void paintWithMark(BSTree T,int x,int y,int r,int h,int w,TElemType c)
{ 
	//int h=60,r=10;
	if(T)
	{  
		setcolor(RED);
        circle(x,y,r); 
        setfillstyle(SOLID_FILL,RED);/*��ɫ���*/
        floodfill(x,y,RED);
	    
		setcolor(WHITE);           /*�����ַ�char*/
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
		 if(T->data==c)           //��ͷ
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
//����״��ӡ�����������Ԫ��,m��ʾ������ڲ��,���ε���ʱm=o
void PrintBST(BSTree T,int m)
{
    int i;
    if(T->rchild) PrintBST(T->rchild,m+1);
    for(i = 1; i<=m; i++)  
        printf("     ");//��ӡ i ���ո��Ա�ʾ�����
    printf("%d\n",T->data);//��ӡ T Ԫ��,���� 
    if(T->lchild) 
        PrintBST(T->lchild,m+1);
   
}

//����*pΪ���Ķ�������������������
void R_Rotate(BSTree &p) 
{
    BSTree lc;             
    lc = p->lchild;         //lcָ���*p�����������
    p->lchild = lc->rchild; //rc���������ҽ�Ϊ*p��������
    lc->rchild = p; p = lc; //pָ���µĽ��
}

//����*pΪ���Ķ�������������������
void L_Rotate(BSTree &p) 
{
    BSTree rc;             
    rc = p->rchild;         //rcָ���*p�����������
    p->rchild = rc->lchild; //rc���������ҽ�Ϊ*p��������
    rc->lchild = p; p = rc; //pָ���µĽ��
}

//����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
void LeftBalance(BSTree &T)
{
    BSTree lc,rd;
    lc = T->lchild;          //lcָ��*T�������������
    switch(lc->bf)           //���*T����������ƽ��ȣ�������Ӧƽ�⴦��
    {
    case LH:                 //�½�������*T�����ӵ��������ϣ�Ҫ������������
        T->bf = lc->bf = EH;
        R_Rotate(T);  break;
    case RH:                 //�½�������*T�����ӵ��������ϣ�Ҫ��˫������
        rd = lc->rchild;     //rdָ��*T�����ӵ���������
        switch(rd->bf)       //�޸�*T�������ӵ�ƽ������
        {
        case LH:T->bf = RH; lc->bf = EH; break;
        case EH:T->bf = lc->bf = EH; break;
        case RH:T->bf = EH; lc->bf = LH; break;
        }
        rd->bf = EH;
        L_Rotate(T->lchild); //��*T��������������ƽ�⴦��
        R_Rotate(T);         //��*T������ƽ�⴦��
    }
}

//����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
void RightBalance(BSTree &T)
{
    BSTree rc,ld;
    rc = T->rchild;         //rcָ��*T�������������
    switch(rc->bf)          //���*T����������ƽ��ȣ�������Ӧƽ�⴦��
    {
    case RH:                //�½�������*T���Һ��ӵ��������ϣ�Ҫ������������
        T->bf = rc->bf =EH;
        L_Rotate(T); break;
    case LH:                //�½�������*T���Һ��ӵ��������ϣ�Ҫ��˫������
        ld = rc->lchild;    //ldָ��*T���Һ��ӵ���������
        switch(ld->bf)      //�޸�*T�����Һ��ӵ�ƽ������
        {
        case LH: T->bf = EH; rc->bf = RH; break;
        case EH: T->bf = rc->bf =EH; break;
        case RH: T->bf = LH; rc->bf = EH; break;
        }
        ld->bf = EH;
        R_Rotate(T->rchild);//��*T��������������ƽ�⴦��
        L_Rotate(T);        //��*T������ƽ�⴦��
    }
}

//������e,�����д��ں�e��ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��Ϊe���½�㣬�����أ������򷵻أ�
bool InsertAVL(BSTree &T,TElemType e,int &taller)
{
	//	printf("eeeee=%d,==%c",e,e);
    if(!T)//�����½�㣬�������ߡ�����tallerΪtrue
    {
        T = (BSTree)malloc(sizeof(BSTNode)); 
        T->data = e;
        T->lchild = T->rchild =NULL;
        T->bf = EH; taller = 1;
    }
    else
    {   int res=compare(e,T->data);
//	printf("e=%d,T->data=%d",e,T->data);
        if(res==0)                 //�����Ѵ��ں�����ͬ�ؼ��ֵĽ��
        { taller = 0;
		  printf("\t�Ѵ�����ͬ�ؼ��ֵĽ��%c\n",T->data); 
		return 0; }//���ٲ���
        if(res==-1)                 //Ӧ������*T���������н�������
        {
            if(!InsertAVL(T->lchild,e,taller)) return 0;//δ����
            if(taller)                    //�Ѳ��뵽*T�����������������������ߡ�
                switch(T->bf)             //���*T��ƽ���
        	{
                  case LH:                //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                      LeftBalance(T); taller = 0; break;
                  case EH:                //ԭ�������������ӵȸߣ��������������߶�ʹ������
                      T->bf = LH; taller = 1; break;
                  case RH:                //ԭ�����������������ߣ������������ȸ�
                      T->bf = EH; taller = 0; break;
            }//switch(T->bf)
        }//if
        else                              //Ӧ������*T���������н�������
        {
            if(!InsertAVL(T->rchild,e,taller)) return 0;//δ����
            if(taller)                    //�Ѳ��뵽*T�����������������������ߡ�
                switch(T->bf)             //���*T��ƽ���
        	{
                   case LH:               //ԭ�����������������ߣ������������ȸ�
                       T->bf = EH; taller = 0; break;
                   case EH:               //ԭ�������������ӵȸߣ��������������߶�ʹ������
                       T->bf = RH; taller = true; break;
                   case RH:               //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                       RightBalance(T); taller = 0; break;
            }//switch(T->bf)
        }//else
    }//else
    return 1;
}//InsertAVL

//����Ԫ��key�Ƿ���������
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
//����ƽ�������
void CreatBST(BSTree &T)
{
    //char e,m;
	char s[40];
	int i=0;
    int taller=0;
    T = NULL;
    printf("\t������ؼ���:");
	scanf("%s",s);
    while(*(s+i)!='*'&&*(s+i)!='\0')
    {	
		//printf("dddd==%c ",e); 
        InsertAVL(T,*(s+i),taller);
        //printf("\n������ؼ���:");
        //scanf("%c",&e);getchar();
		taller=false;
		i++;
    }
   // m=0;
    if(!T) printf("\t����һ�ÿ���.\n");
	

}
//ɾ�����ʱ��ƽ����ת����
void LeftBalance_div(BSTree &p,int &shorter)
{
	BSTree  p1,p2;
	if(p->bf==1) //p�����������ߣ�ɾ������p��bf��1,���䰫
	{ p->bf=0; shorter=1; }
	else if(p->bf==0)//p������������ȸߣ�ɾ������p��bf��1,���߲���
	{ p->bf=-1; shorter=0; }
	else  //p������������
	{
		p1=p->rchild;//p1ָ��p��������
		if(p1->bf==0)//p1������������ȸ�,ɾ������p��bfΪ-2,���������������߲���
		{
			L_Rotate(p);
			p1->bf=1; p->bf=-1; shorter=0;
        }
		else if(p1->bf==-1)//p1���������ߣ�������������䰫
        {
			L_Rotate(p);
            p1->bf=p->bf=0; shorter=1;
        }
		else //p1����������,����˫������(������������)�����䰫
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

//ɾ�����ʱ��ƽ����ת����
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
//ɾ�����
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

//ƽ���������ɾ������
int DeleteAVL(BSTree &p,TElemType x,int &shorter)
{
	int k;
    BSTree q;
    if(p==NULL)  { printf("������Ҫɾ���Ĺؼ���!!\n"); return 0;}
    else if(x<p->data)//��p���������н���ɾ��
    { 
		k=DeleteAVL(p->lchild,x,shorter);
        if(shorter==1)
			LeftBalance_div(p,shorter);
		return k;
	}
	else if(x>p->data)//��p���������н���ɾ��
    {
		k=DeleteAVL(p->rchild,x,shorter);
		if(shorter==1)
			RightBalance_div(p,shorter);
		return k;
	}
	else
	{
		q=p;
		if(p->rchild==NULL) //����������ֻ���ؽ�����������
		{ p=p->lchild; free(q); shorter=1; }
        else if(p->lchild==NULL)//����������ֻ���ؽ�����������
		{ p=p->rchild; free(q); shorter=1; }
        else//��������������
        {
			Delete(q,q->lchild,shorter);
			if(shorter==1)
				LeftBalance_div(p,shorter);
			p=q; 
		}
       return 1;
	}
}

int compare(TElemType a,TElemType b){//a>bʱ����1��a=bʱ����0��a<bʱ����-1
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

//���Ӷ�����T2��T1��
bool CombineAVL(BSTree &T1,BSTree& T2){
 int taller=0;
 if(!T2)return true;
 if(T2->lchild) CombineAVL(T1,T2->lchild);
 if(T2->rchild) CombineAVL(T1,T2->rchild);
 if(!InsertAVL(T1,T2->data,taller)) return false;
 return true;
}



//*****************************************************************
//����ʱ��ʾ,��Ҫ��ʾָ��������c������Ҫָ����cΪNULL��

/*��ָʾ��ͷ��paintWithMark(��Sleep)
 ��ʼԲ��Ϊ��x��y���뾶Ϊr�����������Ϊh������֮���Ϊw
 ��־dataΪ c�Ľ�㡣

*/
void paintSBTTree(BSTree T,int x,int y,int r,int h,int w)
{ 
	//int h=60,r=10;
	if(T)
	{  
		setcolor(RED);
        circle(x,y,r); 
        setfillstyle(SOLID_FILL,RED);/*��ɫ���*/
        floodfill(x,y,RED);	    
		setcolor(WHITE);           /*�����ַ�char*/
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
    int x,y,w,r,h;//(x,y)ΪԲ�ģ�wΪ�������
	x=getmaxx()/2;	y=50; w=180;
	r=15;h=60;
	
    setbkcolor(DARKGRAY);
	cleardevice();
	moveto(15,15);
	outtext("ƽ�����������������ʾ��(�����������)");
		
	int i=0;
    int taller=0;
    T = NULL;
    
    while(*(s+i)!='*'&&*(s+i)!='\0')
    {	
		
        //InsertAVL(T,*(s+i),taller);
        moveto(25,35);
	    outtext("δ����Ľڵ㣺");
		moveto(25,55);
	    outtext((s+i));
        
        InsertAVL(T,*(s+i),taller);
	    //Sleep(2000);
		getch();
	    cleardevice();
	    moveto(15,15);
	    outtext("ƽ�����������������ʾ��(�����������)");
	    paintSBTTree(T,x,y,r,h,w);

		taller=false;
		i++;
    }
	 moveto(25,35);
	 outtext("δ����Ľڵ㣺��");
	 setcolor(RED);
	 moveto(25,55);
	 outtext("������ɣ�");

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
        //printf("\n������ؼ���:");
        //scanf("%c",&e);getchar();
		taller=false;
		i++;
    }
    if(!T) printf("\t����һ�ÿ���.\n");


}
