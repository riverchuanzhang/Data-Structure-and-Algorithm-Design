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
	j = 0;//��־�Ƿ񴴽��ɹ���
	k = 1;
	flag = 1;
	while(k){
		open1();
		printf("���������ѡ�� ");
		scanf("%d",&i);
		switch(i){
			case 1:{
				InitNArray(A,a);//������ά����
				j = 1;
				break;
				   }
			case 2:{
				if(j){
					CreatNArray(a,1);//ǰ��Ҫ�ȴ����ɹ�����ʼ����ά�����ֵ 	
					break;
				}else {
					printf("�㻹û�д������飬����������أ��������飺\n");
					getch();
					break;
				}	
				   }
			case 3:{//ǰ��Ҫ�����ɹ����Զ�ά������ж��ָ�ֵ````` 
				if(j){
					if(flag){
						printf("���ȴ�������ʼ����ά����B\n,�����������\n");
						getch();
						InitNArray(B,b);
						CreatNArray(b,0);
						flag = 0;
					}
				
					Assign(A,a,B,b);
					break;
				}else {
					printf("�㻹û�д������飬����������أ��������飺\n");
					getch();
					break;
				}
				   }
			case 4:{
				if(j){//ǰ��Ҫ�����ɹ���ȷ����ά����Ĵ�С 
					size(A,a);
					break;
				}else {
					printf("�㻹û�д������飬����������أ��������飺\n");
					getch();
					break;	
				}
				   }
			case 5:{
				if(j){//ǰ��Ҫ�����ɹ����Զ�ά����ָ��Ԫ�����(��λ)
					output(A,a);
					break;
				}else{
					printf("�㻹û�д������飬����������أ��������飺\n");
					getch();
					break;
				}
				   }
			case 6:{
				help();//����
				break;
				   }
			case 7:{
				system("cls");//����
				break;
				   }
			case 8:{
				   k=0;
				   break;//�˳�
				   }
			default:                                        
				  printf("\n�Բ���!�������������ȷ!����������!\n");              
			}

	 }
}