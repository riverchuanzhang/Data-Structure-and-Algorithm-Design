#include"header_file.h"
#include<string.h>

                 

void  Man_InitNameList() //������ʼ��          

{    
   
   int i;
  
   char *h;
   
   for(i=0;i<=29;i++)
   { 
	    
	   NameList[i].spell=(char *)malloc(30*sizeof(char));
	   printf("NameList[%d].spell=",i);
	   
	   scanf("%s", NameList[i].spell);
       
	   
       printf("NameList[%d].student_number=",i);
	   NameList[i].student_number=(char *)malloc(30*sizeof(char));
	   fflush(stdin);
       scanf("%s",NameList[i].student_number);
       
   }
  
   
   
  printf("�������!!�������������\n");
   getch();
  int r,sum;
 

for (i=0;i<Name_Number;i++)

{

   sum=0;

   h=NameList[i].spell;
   
  for (r=0;*(h+r)!='\0';r++)//ÿ�����ֵ���ĸ��ӵĺ���Ϊ�ؼ�ֵ


   sum=*(h+r)+sum;
   
  

  NameList[i].key=sum;

}
printf("�ֶ��������ݳɹ���\n");

}