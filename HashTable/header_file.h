#ifndef HEAD_FILE_H
#define HEAD_FILE_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define HASH_LENGTH 50                      //��ϣ����         

#define Random_Number 45                           //�����

#define Name_Number 30      //����  
                    
 typedef struct      
 {
	char *spell;    //���ֵ�ƴ��
    int key;       //ƴ������Ӧ������
    char *student_number;//ѧ��
 }name;
 typedef struct    //��ϣ��
 {
	char *spell;   //���ֵ�ƴ��
    int key;      //ƴ������Ӧ������
    int Search_Length;     //���ҳ���
    char *student_number;//ѧ��
 }hash;

 extern name NameList[HASH_LENGTH];
 extern hash HashList[HASH_LENGTH];
       //ȫ�ֱ���HASH          
 void  InitNameList();                                
 void  CreateHashList_1 (); 
 void  DisplayHashList() ;
 void  FindHashList_1() ;
 void  FindHashList_2();
 void  CreateHashList_2();
 void  Man_InitNameList();
 #endif
