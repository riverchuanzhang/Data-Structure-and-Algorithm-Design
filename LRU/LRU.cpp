#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define random(x) (rand()%x)
 
#define mSIZE 4    //物理块数目
#define pSIZE 60   //进程数目（页面）
 
static int memery[mSIZE] = {0};   //初始化物理块数组
static int process[pSIZE] = {0};  //初始化页面串
static int order[pSIZE] = {0};    //初始化指令串
static int address[pSIZE] ={0};   //指令的页内地址

void FIFO();
void build();             //生成一个随机数序列 
void LRU();               //最近最久未使用(LRU)置换算法
void frame();
void init();

void frame(){

		printf("***************请求调页存储管理方式的模拟-1******************\n\n");
		printf("请选择所需功能：*0、进行LRU算法\n");
		printf("                *1、进行FIFO算法\n");
		printf("请选择0或1: \n\n");
		printf("                                     制作者：张大川");
		printf("***************************************************\n");

}

void build(){              
     int i;
	 srand((int)time(0));
	 printf("产生%d内的随机数指令：\n",pSIZE);
	 for(i = 0; i < pSIZE; i++){      //产生320条（1-320）指令串,用random函数，存入order数组
		 order[i] = random(pSIZE);
		 printf("%d  ",order[i]);
	 }
	 printf("\n");
	 printf("产生%d内的随机数指令所在的页面：\n",pSIZE);
     for(i=0; i<pSIZE; i++){
              process[i] = order[i]/10+1;//将产生的320条指令串的页号存入process数组中
			  address[i] = order[i]%10; //将产生的320条指令串的页内号存入address数组中
              printf("%d   ",process[i]);
     }
	 printf("\n");
	 printf("产生%d内的随机数指令所在的页面内地址：\n",pSIZE); //打印随机数的页内地址
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
	float count = 0; //记下缺页次数
	int c[pSIZE] = {0}; //是否存在内存的标志
    printf("-----物理块--------下一个页面号----------\n");
	for( i = 0; i<mSIZE; i++){   //产生320条（0-320）之间的条指令随机数
		memery[i] = 0;
	}
	for( i = 0; i<mSIZE; i++){   //把前四条指令串的页号调入内存的空闲空间里

		printf("指令已经进入内存，所在的地址是：第%d页 第%d条\n",process[i],address[i]);
		memery[i] = process[i] ;
		for ( j= 0;j<mSIZE; j++){ //每次把内存中的指令串打印出来

			printf(" %d ",memery[j]);		
		}
		printf("           %d ",process[i+1]);	
		printf("\n");
	}

	k = mSIZE;
	for(j=mSIZE;j<pSIZE;j++){

		for(i=0;i<mSIZE;i++)
			 if(process[j]==memery[i]){ //如果内存中存在下一个被调入指令的页号，则把c[j] = 1;
			 c[j] = 1;
			 break;
		     }
		if(c[j] == 1){ // 如果内存中存在下一个被调入的指令的页号，则打印内存中的页号。
			   printf("指令在内存中，所在的地址是：第%d页 第%d条\n",process[j],address[j]);
			   for(i=0;i<mSIZE;i++)
					 printf("%d  ",memery[i]);	
				  
		printf("           %d ",process[j+1]);
//		printf("\n");
		
//		printf("\n");	
			 
		}
		if(c[j] == 0){ 
			printf("---缺页  "); //如果内存中缺页，则根据fifo算法，把最先进来的页面替换。
			printf("指令所在页面缺失，调入指令所在页置换掉其中一页，指令所在的地址是：第%d页 第%d条\n",process[j],address[j]);
			memery[k%mSIZE]=process[j];
			k++;
			count++;
			for(i=0;i<mSIZE;i++)
				printf("%d  ",memery[i]);
			printf("           %d ",process[j+1]);
        }
		printf("\n");
	}
    printf("页面换算次数为：%.0f\n",count);
	float w;
	w=count/(pSIZE-mSIZE);
	printf("缺页率为：      %.4f%%\n",w*100);

}


void LRU(){                    //LRU过程

     int flag[mSIZE] = {0};    //在物理块中逗留时间标志，初始化为0，
     int i = 0, j = 0;         //辅助变量
     int m = -1, n = -1;       //m空块号，n相同进程块号（如果存在）
     int max = -1,maxflag = 0; //标志最大逗留时间值
     float count = 0;            //计数器，计算缺页次数
     int x=0;
	 for(i = 0; i<mSIZE ; i++){      //先把内存空间设为0，表示内存空闲
		 memery[i] = 0;
	 }
     printf("-----物理块--------下一个页面号----------\n");
     for(i = 0; i<pSIZE; i++){
          
           for(j=0; j<mSIZE; j++){      //找第一个空闲的物理块（若存在）
            
                    if(memery[j] == 0){
                           m = j;      //第一个空物理块序号存入m
                           break;      //找到则跳出，每次只需要找到第一个
                    }
           }
           
           for(j = 0; j < mSIZE; j++){   //找与新进页面号相同的物理块（若存在）
            
                 if(memery[j] == process[i]){
                     n = j;             //找到则把该物理块号存入n

                 }
           }
           
           for(j = 0; j < mSIZE;j++){        //找时间标志flag最大的物理块号
            
                 if(flag[j]>maxflag){
                       maxflag = flag[j];
                       max = j;                //此时max为最大值
                 } 
           }   
           
           if(n == -1){               //物理块中不存在与新页面相同页面号
             
                if(m != -1){          //存在一个空闲物理块 
                
                     memery[m] = process[i];  //装入空物理块
					 printf("指令所在页面缺失，调入指令所在页置换掉其中一页，指令所在的地址是：第%d页 第%d条\n",process[j],address[j]);
                     flag[m] = 0;                //时间标志0
                     for(j = 0;j <= m; j++){
                                        
                           flag[j]++;            //时间标志全部加一
                     }
                     m = -1;     //该空闲物理块已经使用，不再为空                
                }
                else{             //不存在空闲物理块 
					 printf("---缺页  ");
				     printf("指令在内存中，所在的地址是：第%d页 第%d条\n",process[i],address[i]);
                     memery[max] = process[i];     //新页面替换内存中 flag值最大（即最近最久未使用）的物理块
                     flag[max] = 0;                //新替换的页面flag值标志为0
                     for(j = 0;j < mSIZE; j++){
                     
                           flag[j]++;             //时间标志全部加一         
                     }
                     max = -1;                    //最大时间标志恢复初始值，下一次重新查找
                     maxflag = 0;
                     count++;                         //计数器标志替换次数
                     x=1;                 //缺页标志，方便显示
                }
           }
           else{                         //物理块中存在与新页面相同的页面号 
            
                 memery[n] = process[i];
				 printf("指令在内存中，所在的地址是：第%d页 第%d条\n",process[j],address[j]);
                 flag[n] = 0;
                 if(m != -1){       //若存在空闲物理块 
                 
                      flag[m] = 0;  //时间标志0
                 }
                 for(j = 0;j < mSIZE; j++){
                 
                       flag[j]++;   //时间标志全部加一
                 }
                 max = -1;           //所有标志恢复初始值，下一次重新查找
                 maxflag = 0;
                 n = -1;
           } 
			
           for(j = 0 ;j < mSIZE; j++){     //显示该次过程用内存物理块内的内容
           
                 printf(" %d ",memery[j]);		 
           }
		   printf("           %d ",process[i+1]);
		   if(x==1){
				x=0;
		   }
           printf("\n");
     } 
     printf("页面换算次数为：%.0f\n",count);
	 float w;
	 w=count/(pSIZE-mSIZE);
	 printf("缺页率为：      %.4f%%\n",w*100);
}

void init(){
	frame();
	int a=0;
	int m;
	printf("请输入你的选择："); 
	scanf("%d",&m);
	printf("请输入置换算法运行次数\n");//运行次数
	scanf("%d",&a);
	switch(m){
	
	case 0:
		for(int i = 0; i<a; i++){
			
			printf("产生随机序列如下：\n");
			build();    //产生320条（1-320）之间的条指令随机数
			LRU();      //LRU算法
			printf("按任意字母键继续：");
			getchar();
			getchar();
		}
        getchar();
		break;
	case 1:
		for(int i = 0; i<a; i++){
			
			printf("产生随机序列如下：\n");
			build();   //产生320条（0-320）之间的条指令随机数
			FIFO();    //FIFO算法
			printf("按任意字母键继续：");
			getchar();
			getchar();
		}
		getchar();
		break;
	}
}

void main(){

	init(); //初始化
}

