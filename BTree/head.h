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

//visit函数
Status visit(TElemType e);


//按definiton构造二叉树T
//definition等于1的时候表示先序建立二叉树
//definition等于2的时候表示中序建立二叉树
//definition等于3的时候表示后序建立二叉树
Status CreateBiTree(BiTree &T, int definition);
 
//将二叉树T清为空树
//初始条件：二叉树T存在。
Status InitBiTree(BiTree &T);

//  初始条件：二叉树T存在。    
//  操作结果：若T为空二叉树，则返回TRUE，否则返回FALSE。 
Status BiTreeEmpty(BiTree T);

//  初始条件：二叉树T存在。    
//  操作结果：返回T的深度。 
int BiTreeDepth(BiTree T);


//  初始条件：二叉树T存在。    
//  操作结果：返回T的根。
TElemType Root(BiTree T);

//  初始条件：二叉树T存在，e是T中某个结点。   
//  操作结果：返回e的值。 
TElemType Value(BiTree T,BiTNode e);


//  初始条件：二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空。    
//  操作结果：根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树 
Status InsertChild(BiTree T,BiTNode *p,int LR,BiTree &c);

//  初始条件：二叉树T存在，p指向T中某个结点，LR为0或1。    
//  操作结果：根据LR为0或1，删除T中p所指结点的左或右子树。
Status DeleteChild(BiTree T,BiTNode *p,int LR);


Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  初始条件：二叉树T存在，Visit是对结点操作的应用函数。    
//  操作结果：中序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit()失败，则操作失败。 
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  初始条件：二叉树T存在，Visit是对结点操作的应用函数。    
//  操作结果：后序遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit()失败，则操作失败。 
Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType));

//  初始条件：二叉树T存在，Visit是对结点操作的应用函数。    
//  操作结果：层次遍历T，对每个结点调用函数Visit一次且仅一次。一旦visit()失败，则操作失败。 
Status LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType));

