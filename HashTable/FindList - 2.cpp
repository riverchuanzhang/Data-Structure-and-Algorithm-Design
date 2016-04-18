#include"header_file.h"
void  FindHashList_2() //哈希表查找    
{	char name[20]={0}; 

   int s=0,a,sum=1,adress,d;
    printf("请输入名字对应的拼音:(如输入hejiner)  " );     
    scanf("%s",name); 
    for(a=0;a<20;a++)   
        s+=name[a]; //求出姓名的拼音所对应的整数(关键字)
    adress=s%Random_Number; 
	
    d=adress;
	if (HashList[adress].key==0) 
         printf("查无此项！请检查是否输入错误。");
       else
    if(HashList[adress].key==s)          
       printf("\n 名字:%s  学号:%s 关键字:%d   查找长度: 1",HashList[d].spell,HashList[d].student_number,s); 
     
    else
	{   int flag=0;

       while(flag==0)

		{  int i=1; 
                   d=(adress+i)%HASH_LENGTH;       //线性探测再散列法处理冲突                     
                sum=sum+1;
                    i++;
            if(HashList[d].key==0)
			{  printf("查无此项 ！请检查是否输入错误。");  
               flag=1;     
			}
            if(HashList[d].key==s)
			{  printf("\n 名字:%s 学号:%s  关键字:%d  查找长度:%d",HashList[d].spell,HashList[d].student_number,s,sum); 
               flag=1;  
			}
		} 
	}  
}