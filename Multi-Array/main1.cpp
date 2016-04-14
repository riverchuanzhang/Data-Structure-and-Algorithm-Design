#include<stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include "store.h"
#include "function.h"

void main(){
	int i,j,k,flag;
	NArray A,B;
	NArrayType a,b;
	i = 0;
	j = 0;//标志是否创建成功的
	k = 1;
	flag = 1;
	while(k){
		open1();
		printf("请输入你的选择： ");
		scanf("%d",&i);
		switch(i){
			case 1:{
				InitNArray(A,a);//创建多维数组
				j = 1;
				break;
				   }
			case 2:{
				if(j){
					CreatNArray(a,1);//前提要先创建成功，初始化多维数组的值 	
					break;
				}else {
					printf("你还没有创建数组，按任意键返回，创建数组：\n");
					getch();
					break;
				}	
				   }
			case 3:{//前提要创建成功，对多维数组进行多种赋值````` 
				if(j){
					if(flag){
						printf("请先创建，初始化多维数组B\n,按任意键继续\n");
						getch();
						InitNArray(B,b);
						CreatNArray(b,0);
						flag = 0;
					}
				
					Assign(A,a,B,b);
					break;
				}else {
					printf("你还没有创建数组，按任意键返回，创建数组：\n");
					getch();
					break;
				}
				   }
			case 4:{
				if(j){//前提要创建成功，确定多维数组的大小 
					size(A,a);
					break;
				}else {
					printf("你还没有创建数组，按任意键返回，创建数组：\n");
					getch();
					break;	
				}
				   }
			case 5:{
				if(j){//前提要创建成功，对多维数组指定元素输出(定位)
					output(A,a);
					break;
				}else{
					printf("你还没有创建数组，按任意键返回，创建数组：\n");
					getch();
					break;
				}
				   }
			case 6:{
				help();//帮助
				break;
				   }
			case 7:{
				system("cls");//清屏
				break;
				   }
			case 8:{
				   k=0;
				   break;//退出
				   }
			default:                                        
				  printf("\n对不起!你的输入结果不正确!请重新输入!\n");              
			}

	 }
}