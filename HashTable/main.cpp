#include"header_file.h"


name NameList[HASH_LENGTH];    //ȫ�ֱ���NAME             

hash HashList[HASH_LENGTH]; 


void main()
{
	system("color 2e");	
	char ch5;
    while(ch5!='N'&&ch5!='n')  
	{
		char ch1,ch2,ch3,ch4;
     	printf("************************************************************************\n");	
    	printf("\t�����������������������������\n\n\n" );
        printf("                ��ѡ����ϵͳ�Զ���ʼ�����ݻ����ֶ���������?\n\n");
	    printf("              1.ϵͳ�Զ���ʼ����     2.�ֶ���������\n");
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
			printf("�������!");
			getch();
			exit(1);
		}
		
		printf("************************************************************************\n");	
    	printf("\t�����������������������������\n\n\n" );
	    printf("\t\t   ������ϣ��ʱ���ú��ַ�ʽ�����ͻ��\n\n");
	    printf("\t1. α���̽����ɢ��\t\t    2. ����̽����ɢ��\n\n");
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
	        printf("\t�����������������������������\n" );
	        printf("\n");
	        printf("\t\t\t      ��ϣ���Ѿ�����\n");
        	printf("\t\t\t  ��ӭ�����ϣ���ѯ����\n");
	        printf("\n");
	        printf("\t\t1. ��ʾ��ϣ��\t\t\t2. ���ҹ�ϣ��\n");
	        printf("\n");	
	        printf("\t\t3���˳�\n");
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
                          printf("�Ƿ�������ҹ�ϣ�������(Y/N)\n");
                          ch2=getchar();
						} ;break;
              default:printf("�������!");
			}
		    printf("�Ƿ������ʾ��ϣ����߲�ѯ��ϣ�������(Y/N)\n");
		    fflush(stdin);
		    ch3=getchar();
		}
		printf("�Ƿ��ٴι�����ϣ��(Y/N)\n");
		fflush(stdin);	
        ch5=getchar();
        if(ch5=='N'||ch5=='n')printf("��л����ʹ�ã�");
	}
}



