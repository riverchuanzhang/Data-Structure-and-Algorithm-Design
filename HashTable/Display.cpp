#include"header_file.h"
void   DisplayHashList()       
{	
 float average=0;
    for( int i=0;i<HASH_LENGTH;i++)
        average+=HashList[i].Search_Length; 
    average/=Name_Number;
    printf("\n该哈希表的平均查找长度为：ASL(30)=%f \n\n",average); 
printf("************************************************************************\n");

    printf("\n哈希表地址   关键字\t   H(key)   查找长度 \t 名字\t        学号\n"); //显示的格式
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