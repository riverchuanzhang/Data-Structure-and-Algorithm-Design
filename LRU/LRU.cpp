#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define random(x) (rand()%x)
 
#define mSIZE 4    //�������Ŀ
#define pSIZE 60   //������Ŀ��ҳ�棩
 
static int memery[mSIZE] = {0};   //��ʼ�����������
static int process[pSIZE] = {0};  //��ʼ��ҳ�洮
static int order[pSIZE] = {0};    //��ʼ��ָ�
static int address[pSIZE] ={0};   //ָ���ҳ�ڵ�ַ

void FIFO();
void build();             //����һ����������� 
void LRU();               //������δʹ��(LRU)�û��㷨
void frame();
void init();

void frame(){

		printf("***************�����ҳ�洢����ʽ��ģ��-1******************\n\n");
		printf("��ѡ�����蹦�ܣ�*0������LRU�㷨\n");
		printf("                *1������FIFO�㷨\n");
		printf("��ѡ��0��1: \n\n");
		printf("                                     �����ߣ��Ŵ�");
		printf("***************************************************\n");

}

void build(){              
     int i;
	 srand((int)time(0));
	 printf("����%d�ڵ������ָ�\n",pSIZE);
	 for(i = 0; i < pSIZE; i++){      //����320����1-320��ָ�,��random����������order����
		 order[i] = random(pSIZE);
		 printf("%d  ",order[i]);
	 }
	 printf("\n");
	 printf("����%d�ڵ������ָ�����ڵ�ҳ�棺\n",pSIZE);
     for(i=0; i<pSIZE; i++){
              process[i] = order[i]/10+1;//��������320��ָ���ҳ�Ŵ���process������
			  address[i] = order[i]%10; //��������320��ָ���ҳ�ںŴ���address������
              printf("%d   ",process[i]);
     }
	 printf("\n");
	 printf("����%d�ڵ������ָ�����ڵ�ҳ���ڵ�ַ��\n",pSIZE); //��ӡ�������ҳ�ڵ�ַ
	 for(i=0; i<pSIZE; i++){
		printf("%d   ",address[i]);
	 }
     printf("\n");
	 printf("\n");
}

void FIFO(){	

	int i,j;
	int k;
//	int flag = 0;
	float count = 0; //����ȱҳ����
	int c[pSIZE] = {0}; //�Ƿ�����ڴ�ı�־
    printf("-----�����--------��һ��ҳ���----------\n");
	for( i = 0; i<mSIZE; i++){   //����320����0-320��֮�����ָ�������
		memery[i] = 0;
	}
	for( i = 0; i<mSIZE; i++){   //��ǰ����ָ���ҳ�ŵ����ڴ�Ŀ��пռ���

		printf("ָ���Ѿ������ڴ棬���ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[i],address[i]);
		memery[i] = process[i] ;
		for ( j= 0;j<mSIZE; j++){ //ÿ�ΰ��ڴ��е�ָ���ӡ����

			printf(" %d ",memery[j]);		
		}
		printf("           %d ",process[i+1]);	
		printf("\n");
	}

	k = mSIZE;
	for(j=mSIZE;j<pSIZE;j++){

		for(i=0;i<mSIZE;i++)
			 if(process[j]==memery[i]){ //����ڴ��д�����һ��������ָ���ҳ�ţ����c[j] = 1;
			 c[j] = 1;
			 break;
		     }
		if(c[j] == 1){ // ����ڴ��д�����һ���������ָ���ҳ�ţ����ӡ�ڴ��е�ҳ�š�
			   printf("ָ�����ڴ��У����ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[j],address[j]);
			   for(i=0;i<mSIZE;i++)
					 printf("%d  ",memery[i]);	
				  
		printf("           %d ",process[j+1]);
//		printf("\n");
		
//		printf("\n");	
			 
		}
		if(c[j] == 0){ 
			printf("---ȱҳ  "); //����ڴ���ȱҳ�������fifo�㷨�������Ƚ�����ҳ���滻��
			printf("ָ������ҳ��ȱʧ������ָ������ҳ�û�������һҳ��ָ�����ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[j],address[j]);
			memery[k%mSIZE]=process[j];
			k++;
			count++;
			for(i=0;i<mSIZE;i++)
				printf("%d  ",memery[i]);
			printf("           %d ",process[j+1]);
        }
		printf("\n");
	}
    printf("ҳ�滻�����Ϊ��%.0f\n",count);
	float w;
	w=count/(pSIZE-mSIZE);
	printf("ȱҳ��Ϊ��      %.4f%%\n",w*100);

}


void LRU(){                    //LRU����

     int flag[mSIZE] = {0};    //��������ж���ʱ���־����ʼ��Ϊ0��
     int i = 0, j = 0;         //��������
     int m = -1, n = -1;       //m�տ�ţ�n��ͬ���̿�ţ�������ڣ�
     int max = -1,maxflag = 0; //��־�����ʱ��ֵ
     float count = 0;            //������������ȱҳ����
     int x=0;
	 for(i = 0; i<mSIZE ; i++){      //�Ȱ��ڴ�ռ���Ϊ0����ʾ�ڴ����
		 memery[i] = 0;
	 }
     printf("-----�����--------��һ��ҳ���----------\n");
     for(i = 0; i<pSIZE; i++){
          
           for(j=0; j<mSIZE; j++){      //�ҵ�һ�����е�����飨�����ڣ�
            
                    if(memery[j] == 0){
                           m = j;      //��һ�����������Ŵ���m
                           break;      //�ҵ���������ÿ��ֻ��Ҫ�ҵ���һ��
                    }
           }
           
           for(j = 0; j < mSIZE; j++){   //�����½�ҳ�����ͬ������飨�����ڣ�
            
                 if(memery[j] == process[i]){
                     n = j;             //�ҵ���Ѹ������Ŵ���n

                 }
           }
           
           for(j = 0; j < mSIZE;j++){        //��ʱ���־flag����������
            
                 if(flag[j]>maxflag){
                       maxflag = flag[j];
                       max = j;                //��ʱmaxΪ���ֵ
                 } 
           }   
           
           if(n == -1){               //������в���������ҳ����ͬҳ���
             
                if(m != -1){          //����һ����������� 
                
                     memery[m] = process[i];  //װ��������
					 printf("ָ������ҳ��ȱʧ������ָ������ҳ�û�������һҳ��ָ�����ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[j],address[j]);
                     flag[m] = 0;                //ʱ���־0
                     for(j = 0;j <= m; j++){
                                        
                           flag[j]++;            //ʱ���־ȫ����һ
                     }
                     m = -1;     //�ÿ���������Ѿ�ʹ�ã�����Ϊ��                
                }
                else{             //�����ڿ�������� 
					 printf("---ȱҳ  ");
				     printf("ָ�����ڴ��У����ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[i],address[i]);
                     memery[max] = process[i];     //��ҳ���滻�ڴ��� flagֵ��󣨼�������δʹ�ã��������
                     flag[max] = 0;                //���滻��ҳ��flagֵ��־Ϊ0
                     for(j = 0;j < mSIZE; j++){
                     
                           flag[j]++;             //ʱ���־ȫ����һ         
                     }
                     max = -1;                    //���ʱ���־�ָ���ʼֵ����һ�����²���
                     maxflag = 0;
                     count++;                         //��������־�滻����
                     x=1;                 //ȱҳ��־��������ʾ
                }
           }
           else{                         //������д�������ҳ����ͬ��ҳ��� 
            
                 memery[n] = process[i];
				 printf("ָ�����ڴ��У����ڵĵ�ַ�ǣ���%dҳ ��%d��\n",process[j],address[j]);
                 flag[n] = 0;
                 if(m != -1){       //�����ڿ�������� 
                 
                      flag[m] = 0;  //ʱ���־0
                 }
                 for(j = 0;j < mSIZE; j++){
                 
                       flag[j]++;   //ʱ���־ȫ����һ
                 }
                 max = -1;           //���б�־�ָ���ʼֵ����һ�����²���
                 maxflag = 0;
                 n = -1;
           } 
			
           for(j = 0 ;j < mSIZE; j++){     //��ʾ�ôι������ڴ�������ڵ�����
           
                 printf(" %d ",memery[j]);		 
           }
		   printf("           %d ",process[i+1]);
		   if(x==1){
				x=0;
		   }
           printf("\n");
     } 
     printf("ҳ�滻�����Ϊ��%.0f\n",count);
	 float w;
	 w=count/(pSIZE-mSIZE);
	 printf("ȱҳ��Ϊ��      %.4f%%\n",w*100);
}

void init(){
	frame();
	int a=0;
	int m;
	printf("���������ѡ��"); 
	scanf("%d",&m);
	printf("�������û��㷨���д���\n");//���д���
	scanf("%d",&a);
	switch(m){
	
	case 0:
		for(int i = 0; i<a; i++){
			
			printf("��������������£�\n");
			build();    //����320����1-320��֮�����ָ�������
			LRU();      //LRU�㷨
			printf("��������ĸ��������");
			getchar();
			getchar();
		}
        getchar();
		break;
	case 1:
		for(int i = 0; i<a; i++){
			
			printf("��������������£�\n");
			build();   //����320����0-320��֮�����ָ�������
			FIFO();    //FIFO�㷨
			printf("��������ĸ��������");
			getchar();
			getchar();
		}
		getchar();
		break;
	}
}

void main(){

	init(); //��ʼ��
}

