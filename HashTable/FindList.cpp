#include"header_file.h"
void  FindHashList_1() //��ϣ�����    
{	char name[20]={0}; 

   int s=0,a,sum=1,adress,d;
    printf("���������ֶ�Ӧ��ƴ��:(������hejiner)  " );     
    scanf("%s",name); 
    for(a=0;a<20;a++)   
        s+=name[a]; //���������ƴ������Ӧ������(�ؼ���)
    adress=s%Random_Number; 
	
    d=adress;
	if (HashList[adress].key==0) 
         printf("���޴�������Ƿ��������");
       else
    if(HashList[adress].key==s)          
       printf("\n ����:%s ѧ�ţ�%s   �ؼ���:%d   ���ҳ���: 1",HashList[d].spell,HashList[d].student_number,s); 
     
    else
	{   int flag=0;

       while(flag==0)
		{   d=(d+s%10+1)%Random_Number;       //α���̽����ɢ�з������ͻ                     
            sum=sum+1;
            if(HashList[d].key==0)
			{  printf("���޴��� �������Ƿ��������");  
               flag=1;     
			}
            if(HashList[d].key==s)
			{  printf("\n ����:%s ѧ�ţ�%s �ؼ���:%d  ���ҳ���:%d",HashList[d].spell,HashList[d].student_number,s,sum); 
               flag=1;  
			}
		} 
	}  
}