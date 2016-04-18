
#include"tree.h"


void main(){  
	//system("color 8f");
	BSTree T,T1,T2,T3,T4;
	int input,search;
    int taller=0;
	int shorter=0;
	char a[30];
	int x=0,y=0;
    T=T1=T2=T4=NULL;
	
	printf("**************************平衡二叉树****************************\n");
	printf("*1.创建  2.显示二叉树  3.查找  4.插入  5.删除  6.合并两棵二叉树*\n");
	printf("*7.分裂平衡二叉树                                        0.退出*\n");
	printf("╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬\n");
	while(1){ 
		// system("cls"); 
        printf("请输入您所需的操作功能:\t");
        scanf("%d",&input);getchar();   
		switch(input)
		{
		   case 1:
			   { printf("输入关键字:");
                    //scanf("%s",a);
				  gets(a);	
			     if(strlen(a)>0)
					{
						showCreatBST(T,a);
					    printf("创建成功！\n");
					    //getch();
					}
					else
					{ 
						printf("未输入任何字符！请重新选择操作！\n");
                        //getch();
					}
			    
			   }break;
		   case 2:
			    paintAVL(T,NULL);
				break;
		   case 3:
			   printf("请输入你要查找的关键字:");
               scanf("%c",&search); getchar();
               if(SearchBST(T,search)){ printf("该二叉树中存在关键字%c，查找成功!\n",search);getch();paintAVL(T,search);}
               else printf("查找失败!\n");
               break;
		   case 4:
               printf("请输入你要插入的关键字:");
               scanf("%c",&search); getchar();
               InsertAVL(T,search,taller);
			   paintAVL(T,search); break;
		   case 5:
			   printf("请输入你要删除的关键字:");
			   scanf("%c",&search); getchar();
			   DeleteAVL(T,search,shorter);
			   paintAVL(T,NULL);break;

		   case 6:
			   printf("(6)请输入您所需的操作功能:\n");
			   printf("\t1.输入第一棵二叉树  2.输入第二棵二叉树  3.查看第一棵二叉树\n ");
			   printf("\t4.查看第二棵二叉树  5.查看 6.合并二叉树\n\t0.返回上一级菜单\n");
			   while(true){
				   printf("\t请输入您所需的操作功能:\t");
				   scanf("%d",&input);getchar();  
				   switch(input){
				      case 1:{
						  printf("\t请输入第一棵二叉树:\n");
						  CreatBST(T1);
						  if(T1)
							 printf("\t第一棵树创建成功!\n\n");
						  else
							 printf("\t第一棵树创建失败\n");}break;
					  case 2:{
						  printf("\t请输入第二棵二叉树:\n");
						  CreatBST(T2);
						  if(T1)
							 printf("\t第二棵树创建成功!\n\n");
						  else
							 printf("\t第二棵树创建失败\n");}break;
					  case 3:paintAVL(T1,NULL);break;	
					  case 4:paintAVL(T2,NULL);break;
                      case 5:paint2AVL(T1,T2,NULL);break;
					  case 6:CombineAVL(T1,T2);paintAVL(T1,NULL);break;
					  case 0:break;
					  default:printf("输入错误，");break;
				   }
				   if(input==0){input=9;break;}
			   }break;   
		   
		   case 7:
			   char div;
			   
			   TElemType lower[30],higher[30];
			   printf("(7)请输入您所需的操作功能:\n");
			   printf("\t1.创建二叉树  2.查看二叉树  3.输入或更改分支点  4.开始分裂二叉树\n");
			   printf("\t5.查看分裂后的第一棵二叉树  6.查看分裂后的第二棵二叉树 7.查看\n\t0.返回上一级菜单\n");
			   while(true){ 
				   printf("\t请输入您所需的操作功能:\t");
				   scanf("%d",&input);getchar();  
				   switch(input){
					  case 1:printf("\t创建二叉树\n");CreatBST(T);break;
					  case 2:paintAVL(T,NULL);break;	
					  case 3:printf("\t请输入或更改分支点:");scanf("%c",&div);getchar();break;
					  case 4:
						  printf("\t开始分裂二叉树....\n");
						  for(x=0;x<30;x++){lower[x]='\0';higher[x]='\0';}
						  x=0;
						  devide(T,lower,higher,x,y,div);
                         // for(int m=0;m<30;m++){lower[x]='\0';higher[x]='\0';}
						  // for(x=0;higher[x];x++);higher[x]='\0';
						  //puts(lower);
						 // puts(higher);
						  getch();
						  CreatBST(T3,lower);
						  CreatBST(T4,higher);
						  break;
					  case 5:paintAVL(T3,NULL);break;	
					  case 6:paintAVL(T4,NULL);break;
					  case 7:paint2AVL(T3,T4,div);break;
					  case 0:break;
					  default:printf("输入错误,");break;
				   }
				   if(input==0){input=9;break;}
			   }   

		   case 8:
			   {
				   	printf("**************************平衡二叉树****************************\n");
	                printf("*1.创建  2.显示二叉树  3.查找  4.插入  5.删除  6.合并两棵二叉树*\n");
	                printf("*7.分裂平衡二叉树                                        0.退出*\n");
	                printf("╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬\n");
			   };break;
		   case 0:break;
		   default:printf("输入错误,");break;
		}
		if(input == 0) break;
		printf("按任意键继续...\n"); 
		getch();
	}
	printf("bye bye!\n");
	getch();
  
}
