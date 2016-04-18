#include"header_file.h"


name NameList[HASH_LENGTH];    //全局变量NAME             

hash HashList[HASH_LENGTH]; 


void main()
{
	system("color 2e");	
	char ch5;
    while(ch5!='N'&&ch5!='n')  
	{
		char ch1,ch2,ch3,ch4;
     	printf("************************************************************************\n");	
    	printf("\t☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n\n\n" );
        printf("                请选择是系统自动初始化数据还是手动输入数据?\n\n");
	    printf("              1.系统自动初始化；     2.手动输入数据\n");
       printf("************************************************************************\n");
        fflush(stdin);
           char ch6;
        ch6=getchar();
	    if(ch6=='1')
	       InitNameList(); 
	    else if(ch6=='2')
           Man_InitNameList();
	    else
		{
			printf("输入错误!");
			getch();
			exit(1);
		}
		
		printf("************************************************************************\n");	
    	printf("\t☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n\n\n" );
	    printf("\t\t   构建哈希表时采用何种方式处理冲突？\n\n");
	    printf("\t1. 伪随机探测再散列\t\t    2. 线性探测再散列\n\n");
        printf("************************************************************************\n");
        fflush(stdin);
	    ch4=getchar();
		if(ch4=='1')
          CreateHashList_2 (); 
		if(ch4=='2')
		  CreateHashList_1();
        fflush(stdin);
      	ch3='y';
	    while(ch3!='N'&&ch3!='n')
		{
			printf("************************************************************************\n");	
	        printf("\t☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n" );
	        printf("\n");
	        printf("\t\t\t      哈希表已经构建\n");
        	printf("\t\t\t  欢迎进入哈希表查询界面\n");
	        printf("\n");
	        printf("\t\t1. 显示哈希表\t\t\t2. 查找哈希表\n");
	        printf("\n");	
	        printf("\t\t3、退出\n");
	        printf("\n");
	        printf("************************************************************************\n");	
		    fflush(stdin);
	        ch1=getchar();
		    switch(ch1)
			{
			  case '3':exit(1);
			  case '1':DisplayHashList(); printf("\n"); ;break;
		      case '2':	while(ch2!='N'&&ch2!='n')
						{ fflush(stdin);
			              if(ch4=='1')
				             FindHashList_1();
			              else
                             FindHashList_2();
			              printf("\n");fflush(stdin);
                          printf("是否继续查找哈希表操作？(Y/N)\n");
                          ch2=getchar();
						} ;break;
              default:printf("输入错误!");
			}
		    printf("是否继续显示哈希表或者查询哈希表操作？(Y/N)\n");
		    fflush(stdin);
		    ch3=getchar();
		}
		printf("是否再次构建哈希表？(Y/N)\n");
		fflush(stdin);	
        ch5=getchar();
        if(ch5=='N'||ch5=='n')printf("感谢您的使用！");
	}
}



