
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
	
	printf("**************************ƽ�������****************************\n");
	printf("*1.����  2.��ʾ������  3.����  4.����  5.ɾ��  6.�ϲ����ö�����*\n");
	printf("*7.����ƽ�������                                        0.�˳�*\n");
	printf("�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p\n");
	while(1){ 
		// system("cls"); 
        printf("������������Ĳ�������:\t");
        scanf("%d",&input);getchar();   
		switch(input)
		{
		   case 1:
			   { printf("����ؼ���:");
                    //scanf("%s",a);
				  gets(a);	
			     if(strlen(a)>0)
					{
						showCreatBST(T,a);
					    printf("�����ɹ���\n");
					    //getch();
					}
					else
					{ 
						printf("δ�����κ��ַ���������ѡ�������\n");
                        //getch();
					}
			    
			   }break;
		   case 2:
			    paintAVL(T,NULL);
				break;
		   case 3:
			   printf("��������Ҫ���ҵĹؼ���:");
               scanf("%c",&search); getchar();
               if(SearchBST(T,search)){ printf("�ö������д��ڹؼ���%c�����ҳɹ�!\n",search);getch();paintAVL(T,search);}
               else printf("����ʧ��!\n");
               break;
		   case 4:
               printf("��������Ҫ����Ĺؼ���:");
               scanf("%c",&search); getchar();
               InsertAVL(T,search,taller);
			   paintAVL(T,search); break;
		   case 5:
			   printf("��������Ҫɾ���Ĺؼ���:");
			   scanf("%c",&search); getchar();
			   DeleteAVL(T,search,shorter);
			   paintAVL(T,NULL);break;

		   case 6:
			   printf("(6)������������Ĳ�������:\n");
			   printf("\t1.�����һ�ö�����  2.����ڶ��ö�����  3.�鿴��һ�ö�����\n ");
			   printf("\t4.�鿴�ڶ��ö�����  5.�鿴 6.�ϲ�������\n\t0.������һ���˵�\n");
			   while(true){
				   printf("\t������������Ĳ�������:\t");
				   scanf("%d",&input);getchar();  
				   switch(input){
				      case 1:{
						  printf("\t�������һ�ö�����:\n");
						  CreatBST(T1);
						  if(T1)
							 printf("\t��һ���������ɹ�!\n\n");
						  else
							 printf("\t��һ��������ʧ��\n");}break;
					  case 2:{
						  printf("\t������ڶ��ö�����:\n");
						  CreatBST(T2);
						  if(T1)
							 printf("\t�ڶ����������ɹ�!\n\n");
						  else
							 printf("\t�ڶ���������ʧ��\n");}break;
					  case 3:paintAVL(T1,NULL);break;	
					  case 4:paintAVL(T2,NULL);break;
                      case 5:paint2AVL(T1,T2,NULL);break;
					  case 6:CombineAVL(T1,T2);paintAVL(T1,NULL);break;
					  case 0:break;
					  default:printf("�������");break;
				   }
				   if(input==0){input=9;break;}
			   }break;   
		   
		   case 7:
			   char div;
			   
			   TElemType lower[30],higher[30];
			   printf("(7)������������Ĳ�������:\n");
			   printf("\t1.����������  2.�鿴������  3.�������ķ�֧��  4.��ʼ���Ѷ�����\n");
			   printf("\t5.�鿴���Ѻ�ĵ�һ�ö�����  6.�鿴���Ѻ�ĵڶ��ö����� 7.�鿴\n\t0.������һ���˵�\n");
			   while(true){ 
				   printf("\t������������Ĳ�������:\t");
				   scanf("%d",&input);getchar();  
				   switch(input){
					  case 1:printf("\t����������\n");CreatBST(T);break;
					  case 2:paintAVL(T,NULL);break;	
					  case 3:printf("\t���������ķ�֧��:");scanf("%c",&div);getchar();break;
					  case 4:
						  printf("\t��ʼ���Ѷ�����....\n");
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
					  default:printf("�������,");break;
				   }
				   if(input==0){input=9;break;}
			   }   

		   case 8:
			   {
				   	printf("**************************ƽ�������****************************\n");
	                printf("*1.����  2.��ʾ������  3.����  4.����  5.ɾ��  6.�ϲ����ö�����*\n");
	                printf("*7.����ƽ�������                                        0.�˳�*\n");
	                printf("�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p\n");
			   };break;
		   case 0:break;
		   default:printf("�������,");break;
		}
		if(input == 0) break;
		printf("�����������...\n"); 
		getch();
	}
	printf("bye bye!\n");
	getch();
  
}
