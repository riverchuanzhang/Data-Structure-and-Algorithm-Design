#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MaxSize 100
typedef int Status;
typedef char TElemType;

typedef struct BiTNode{
TElemType data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//visit����
Status visit(TElemType e);


//��definiton���������T
//definition����1��ʱ���ʾ������������
//definition����2��ʱ���ʾ������������
//definition����3��ʱ���ʾ������������
Status CreateBiTree(BiTree &T, int definition);
 
//��������T��Ϊ����
//��ʼ������������T���ڡ�
Status InitBiTree(BiTree &T);

//  ��ʼ������������T���ڡ�    
//  �����������TΪ�ն��������򷵻�TRUE�����򷵻�FALSE�� 
Status BiTreeEmpty(BiTree T);

//  ��ʼ������������T���ڡ�    
//  �������������T����ȡ� 
int BiTreeDepth(BiTree T);


//  ��ʼ������������T���ڡ�    
//  �������������T�ĸ���
TElemType Root(BiTree T);

//  ��ʼ������������T���ڣ�e��T��ĳ����㡣   
//  �������������e��ֵ�� 
TElemType Value(BiTree T,BiTNode e);


//  ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ�ա�    
//  �������������LRΪ0��1������cΪT��p��ָ���������������p��ָ����ԭ��������������Ϊc�������� 
Status InsertChild(BiTree T,BiTNode *p,int LR,BiTree &c);

//  ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1��    
//  �������������LRΪ0��1��ɾ��T��p��ָ���������������
Status DeleteChild(BiTree T,BiTNode *p,int LR);


Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú�����    
//  ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�һ��visit()ʧ�ܣ������ʧ�ܡ� 
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú�����    
//  ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�һ��visit()ʧ�ܣ������ʧ�ܡ� 
Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú�����    
//  �����������α���T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�һ��visit()ʧ�ܣ������ʧ�ܡ� 
Status LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType));

