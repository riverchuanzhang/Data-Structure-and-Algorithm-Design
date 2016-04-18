#ifndef HEAD_FILE_H
#define HEAD_FILE_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define HASH_LENGTH 50                      //哈希表长度         

#define Random_Number 45                           //随机数

#define Name_Number 30      //人数  
                    
 typedef struct      
 {
	char *spell;    //名字的拼音
    int key;       //拼音所对应的整数
    char *student_number;//学号
 }name;
 typedef struct    //哈希表
 {
	char *spell;   //名字的拼音
    int key;      //拼音所对应的整数
    int Search_Length;     //查找长度
    char *student_number;//学号
 }hash;

 extern name NameList[HASH_LENGTH];
 extern hash HashList[HASH_LENGTH];
       //全局变量HASH          
 void  InitNameList();                                
 void  CreateHashList_1 (); 
 void  DisplayHashList() ;
 void  FindHashList_1() ;
 void  FindHashList_2();
 void  CreateHashList_2();
 void  Man_InitNameList();
 #endif
