#include"header_file.h"
void   DisplayHashList()       
{	
 float average=0;
    for( int i=0;i<HASH_LENGTH;i++)
        average+=HashList[i].Search_Length; 
    average/=Name_Number;
    printf("\n�ù�ϣ���ƽ�����ҳ���Ϊ��ASL(30)=%f \n\n",average); 
printf("************************************************************************\n");

    printf("\n��ϣ���ַ   �ؼ���\t   H(key)   ���ҳ��� \t ����\t        ѧ��\n"); //��ʾ�ĸ�ʽ
    for(i=0; i<HASH_LENGTH; i++)

	{  
		printf("%d ",i);   
	
        printf("\t\t%d ",HashList[i].key); 
      
		printf("\t\t%d ",HashList[i].key%Random_Number); 
        
        printf("\t%d ",HashList[i].Search_Length); 
       
		if(HashList[i].key%Random_Number!=0)
		{	
			printf("\t %s ",HashList[i].spell); 
	
         printf("\t%s ",HashList[i].student_number);}
        printf("\n");
	}
   printf("************************************************************************\n");  
   
}