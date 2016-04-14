#include<stdio.h>
#include <conio.h>
#include<windows.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#define LEN 20
#define N 100
#define OK 1
#define ERROR 0
#define MAXQSIZE 200
//有向图的十字链表存储表示

typedef char InfoType;       //用该类型来存储弧信息
typedef char VertexType;

typedef struct ArcBox{        //用十字链表实现的弧
    int tailvex,headvex;      //弧的尾顶点和头顶点的位置
    ArcBox *hlink,*tlink;     //分别为弧头相同和弧尾相同的链域
    InfoType *info;           //该弧的相关信息的指针
}ArcBox;

typedef struct VexNode{       //该类型存储顶点的信息
    VertexType data[LEN];          //存储顶点信息
    ArcBox *firstin,*firstout;//分别指向该顶点第一条入弧和出弧
}VexNode;

typedef struct Graph{         //该类型表示十字链表实现的有向图
    VexNode xlist[N];         //xlist[i]表示顶点i的表头向量
    int vexnum,arcnum;        //有向图的当前顶点和弧数
}Graph;

void setUI()
{
    //跟换字体颜色
    char com[20]={0};
    sprintf(com,"color 1%d",3);
    system(com);
    printf("**********************************************\n");
    printf("* 输入数字执行相应的操作:                    *\n");
    printf("* 1:创建有向图;                              *\n");
    printf("* 2:销毁图的操作;                            *\n");
    printf("* 3:查找顶点u在图中的位置;                   *\n");
    printf("* 4:增添新顶点;                              *\n");
    printf("* 5:删除顶点及其相关的弧;                    *\n");
    printf("* 6:增添新的弧;                              *\n");
    printf("* 7:删除弧操作;                              *\n");
    printf("* 8:対图进行深度优先搜索;                    *\n");
    printf("* 9:対图进行广度优先搜索;                    *\n");
    printf("* 0:所有操作结束。                           *\n");
    printf("**********************************************\n\n");
}


//Graph G;  //这里的变量要用全局的，否则在某些编译器下运行会出错

void output(Graph &G){
    int i;
    ArcBox *p;
    printf("所创建的有向图共有%d个顶点，%d条弧:\n",G.vexnum,G.arcnum);
    for (i = 0; i < G.vexnum; ++i){
        printf("顶点%s的：入度:",G.xlist[i].data);
        p = G.xlist[i].firstin;
        while (p){
            printf("%s",G.xlist[p->tailvex].data);
            if (p->info) printf("(弧的信息为%s) ",p->info);
            else printf(" ");
            p = p->hlink;
        }
        printf("出度:");
        p = G.xlist[i].firstout;
        while (p){
            printf("%s",G.xlist[p->headvex].data);
            if (p->info) printf("(弧的信息为%s) ",p->info);
            else printf(" ");
            p = p->tlink;
        }
        printf("\n");
    }
}

//返回图中与顶点u信息相同的顶点的位置，若不存在返回-1
int LocateVex(Graph &G,VertexType *u){
    int i;
    for (i = 0; i < G.vexnum; ++i)    //该循环找出与顶点u信息相同的顶点
        if (!strcmp(G.xlist[i].data,u)) return i;
    return -1;                        //若找不到返回-1
}

typedef int Status;      //该类型只有两种值：OK(表示正确)和ERROR(表示错误)

//构建十字链表实现的有向图，并输入相关信息
Status CreateGraph(Graph &G){
    int IncInfo;
    VertexType v1[LEN],v2[LEN];
    char s[LEN];
    int i,j,k;
    ArcBox *p;

    system("CLS");
    setUI();
    printf("请输入你要创建的图的顶点个数n(0<n<=100):");
    scanf("%d",&G.vexnum);
    if (G.vexnum > N || G.vexnum < 0){
        printf("输入的数据超出范围！");
        return ERROR;
    }
    system("CLS");
    setUI();
    printf("请输入该有向图的弧数:");
    scanf("%d%*c",&G.arcnum);
    if (G.arcnum > N*N || G.arcnum < 0){
        printf("输入的数据超出范围！");
        return ERROR;
    }
    system("CLS");
    setUI();
    printf("请问你创建的弧是否包含其他信息(是则输入1，否则输入0):");
    scanf("%d",&IncInfo);

    system("CLS");
    setUI();
    printf("请输入%d个顶点的元素值(每行只输入一个值):\n",G.vexnum);
    for (i = 0; i < G.vexnum; ++i){
        scanf("%s",&G.xlist[i].data);
        G.xlist[i].firstin = G.xlist[i].firstout = NULL;//対链表指针初始化
    }

    system("CLS");
    setUI();
    printf("请输入%d条弧(输入格式:弧尾 弧头<回车键>):\n",G.arcnum);
    for (k = 0; k < G.arcnum; ++k){
        //scanf("%s",&v1);
        //scanf("%s",&v2);
        scanf("%s%s%*c",v1,v2);
        i = LocateVex(G,v1);         //确定v1在图G中的位置
        j = LocateVex(G,v2);         //确定v2在图G中的位置
        p = (ArcBox*)malloc(sizeof(ArcBox));//生成单个弧结点的空间
        //以下5行实现十字链表的插入操作
        p->tailvex = i;
        p->headvex = j;
        p->hlink = G.xlist[j].firstin;
        p->tlink = G.xlist[i].firstout;
        G.xlist[j].firstin = G.xlist[i].firstout = p;
        //*****************************
        if (IncInfo){       //若弧含有其他信息，则另外另外输入
            printf("请输入另外的信息:");
            scanf("%s",s);
            p->info = (InfoType*)malloc((strlen(s)+1)*sizeof(InfoType));
            strcpy(p->info,s);
        }else p->info = NULL;
    }
    system("CLS");
    setUI();
    output(G);
    printf("图的创建已完成。\n");
    return OK;
}

//销毁有向图G,并释放图G有关的内存，避免内存泄露
void DestroyGraph(Graph &G){
    int i;
    ArcBox *p,*q;

    for (i = 0; i < G.vexnum; ++i){
        for (p = G.xlist[i].firstout; p; ){
            q = p;
            p = p->tlink;
            if (q->info) free(q->info);
            free(q);
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    system("CLS");
    setUI();
    printf("图G已销毁。\n");
}

//返回v的值
VertexType* GetVex(Graph &G,int v){
    return G.xlist[v].data;
}

//対顶点v进行赋值，成功返回OK，否则返回ERROR
Status PutVex(Graph &G,VertexType *v,VertexType *value){
    int i = LocateVex(G,v);
    if (i < 0) return ERROR;
    strcpy(G.xlist[i].data,value);
    return OK;
}

//返回顶点v的第一个邻接顶点的序号，若顶点v不存在邻接顶点则返回-1
int FirstAdjVex(Graph &G,VertexType *v){
    int i = LocateVex(G,v);;
    ArcBox *p = G.xlist[i].firstout;
    if (p) return p->headvex;
    else return -1;
}

//返回顶点v的下一个邻接顶点的序号，若w是顶点v的最后一个邻接点则返回-1
int NextAdjVex(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    ArcBox *p;
    i = LocateVex(G,v);      //i是顶点v的序号
    j = LocateVex(G,w);      //j是顶点w的序号
    p = G.xlist[i].firstout; //p指向顶点v的第1个出弧
    //前提条件：w是v的邻接顶点
    while (p && p->headvex!=j) p = p->tlink;//知道p指向顶点w或为空
    if (p) p = p->tlink;     //若w不是v的最后一个邻接顶点，相对于w的下一个邻接顶点
    if (p) return p->headvex;//返回下一个结点的序号
    else return -1;          //返回w是v的最后一个顶点
}

//在图G中增添新顶点v
void InsertVex(Graph &G,VertexType *v){
    strcpy(G.xlist[G.vexnum].data , v);
    G.xlist[G.vexnum].firstin = G.xlist[G.vexnum].firstout = NULL;
    ++G.vexnum;               //图G的顶点数加1
}

//删除图G中顶点v及其相关的弧，并释放内存
Status DeleteVex(Graph &G,VertexType *v){
    int j,k;
    ArcBox *p,*q;

    k = LocateVex(G,v);
    if (k < 0 || k >= G.vexnum) return ERROR;//若顶点v不在图G中则返回ERROR
    for (j = 0; j < G.vexnum; ++j) if (j != k){//查找除k以外的顶点
        p = G.xlist[j].firstin;
        while (p){
            if (p->tailvex == k && p == G.xlist[j].firstin){
                G.xlist[j].firstin = p->hlink;
                break;
            }else if (p->tailvex != k){
                q = p;
                p = p->hlink;
            }else{
                q->hlink = p->hlink;
                break;
            }
        }
    }
    //删除与顶点v有关的出弧
    p = G.xlist[k].firstout;
    while (p){
        q = p->tlink;
        if (p->info) free(p->info);
        free(p);
        --G.arcnum;
        p = q;
    }
    //删除顶点v的入弧
    for (j = 0; j < G.vexnum; ++j) if (j != k){
        p = G.xlist[j].firstout;
        while (p){
            if (p->headvex == k && p == G.xlist[j].firstout){
                G.xlist[j].firstout = p->tlink;
                break;
            }else if (p->headvex != k){
                q = p;
                p = p->tlink;
            }else{
                q->tlink = p->tlink;
                break;
            }
        }
    }
    //删除与顶点v有关的入弧
    p = G.xlist[k].firstin;
    while (p){
        q = p->hlink;
        if (p->info) free(p->info);
        free(p);
        --G.arcnum;
        p = q;
    }
    for (j = k+1; j < G.vexnum; ++j) G.xlist[j-1] = G.xlist[j];
    --G.vexnum;
    for (j = 0; j < G.vexnum; ++j){
        p = G.xlist[j].firstout;
        while (p){
            if (p->tailvex > k) --p->tailvex;
            if (p->headvex > k) --p->headvex;
            p = p->tlink;
        }
    }
    return OK;
}

//在图G中增添弧<v,w>
int InsertArc(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    int IncInfo;
    char s[LEN];
    ArcBox *p;

    i = LocateVex(G,v);  //弧尾的序号
    j = LocateVex(G,w);  //弧头的序号
    if (i<0 || j<0) return 0;
    p = (ArcBox*)malloc(sizeof(ArcBox));//生成单个弧结点的空间
    //以下5行实现十字链表的插入操作
    p->tailvex = i;
    p->headvex = j;
    p->hlink = G.xlist[j].firstin;
    p->tlink = G.xlist[i].firstout;
    G.xlist[j].firstin = G.xlist[i].firstout = p;
    //*****************************
    ++G.arcnum;          //弧数加1
    printf("弧是否包含其他信息：(是则输入1，否则输入0)");
    scanf("%d",&IncInfo);
    if (IncInfo){
        printf("请输入该弧的信息：");
        scanf("%s",s);
        p->info = (InfoType *)malloc((strlen(s)*sizeof(InfoType)));
        strcpy(p->info,s);
    }else p->info = NULL;
    return 1;
}

//在图G中删除弧<v,w>
Status DeleteArc(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    ArcBox *p1,*p2;

    i = LocateVex(G,v);      //弧尾的序号
    j = LocateVex(G,w);      //弧头的序号
    if (i<0 || j<0 || i == j) return ERROR;    //若v或w不在图G中则返回ERROR
    //以下部分实现：在结点v的出弧中查找<v,w>并删去
    p2 = G.xlist[i].firstout;
    if (p2 && p2->headvex == j) G.xlist[i].firstout = p2->tlink;
    else{
        while (p2 && p2->headvex != j){
            p1 = p2;
            p2 = p2->tlink;
        }
        if (p2) p1->tlink = p2->tlink;
    }
    //********************************

    //以下部分实现：在结点w的入弧中查找<v,w>并删去
    p2 = G.xlist[j].firstin;
    if (p2 && p2->tailvex == i) G.xlist[j].firstin = p2->hlink;
    else{
        while (p2 && p2->tailvex != i){
            p1 = p2;
            p2 = p2->hlink;
        }
        if (p2) p1->hlink = p2->hlink;
    }
    //********************************
    if (p2->info) free(p2->info);  //清空弧结点信息
    free(p2);                      //清空弧结点
    --G.arcnum;                    //狐数减1
    return OK;
}

//****************以下是DFS的模块**************************

int visited[N];  //visited[i]为1表示顶点i被访问过，为0表示还没被访问

void visit(VertexType *x){ printf("%s ",x); }//用来访问的函数

void dfs(Graph &G,int i){
    ArcBox *p;
    visited[i] = 1;           //标记顶点i已被访问
    visit(G.xlist[i].data);   //访问顶点i
    //以下3行实现：対顶点i的出弧进行深度优先访问
    p = G.xlist[i].firstout;
    while (p && visited[ p->headvex ]) p = p->tlink;
    if (p && !visited[ p->headvex ]) dfs(G,p->headvex);
}

void DFSTraverse(Graph &G){
    int i;
    //初始化visited数组，表示都没被访问过
    for (i = 0; i < G.vexnum; ++i) visited[i] = 0;
    //若顶点i之前没被访问过，则对其进行深度优先搜索
    for (i = 0; i < G.vexnum; ++i) if (!visited[i]) dfs(G,i);
    printf("\n");
}

//****************以上是DFS的模块**************************

//*****************以下是BFS的模块*************************

typedef int QElemType;

typedef struct SqQueue{//队列的顺序储存结构
    QElemType *base;   //动态分配存储空间
    int front;         //头指针，指向队列头元素
    int rear;          //尾指针，指向队列尾元素的下一个位置
}SqQueue;

//创建一个空队列Q
Status InitQueue(SqQueue &Q){
    //给队列分配空间
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;  //队头队尾初始化
    return OK;
}

//若队列Q为空，返回1，否则返回0
int QueueEmpty(SqQueue Q){
    if (Q.front == Q.rear) return 1;
    else return 0;
}

//把元素e插入到队尾
Status EnQueue(SqQueue &Q,QElemType e){
    if ((Q.rear + 1)%MAXQSIZE == Q.front) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%MAXQSIZE;
    return OK;
}

//删除队头元素，并用e返回其值
Status DeQueue(SqQueue &Q,QElemType &e){
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

//対图G进行广度优先搜索
void BFSTraverse(Graph &G){
    int v,u,w;
    VertexType u1[LEN],w1[LEN];
    SqQueue Q;

    for (v = 0; v < G.vexnum; ++v) visited[v] = 0;   //対查询是否被访问的数组进行初始化
    InitQueue(Q);                                    //创建队列
    for (v = 0; v < G.vexnum; ++v) if (!visited[v]){ //若v未被访问，则进行搜索
        visited[v] = 1;                              //标记v已被访问
        visit(G.xlist[v].data);                      //用visit()函数访问顶点v
        EnQueue(Q,v);                                //将v插进队尾
        //下面的循环实现图的广度优先搜索
        //若队列非空，则从头到尾进行遍历，每次删除并提取队头顶点
        //将与当前顶点相邻的未被访问的顶点加入队尾，直至队列为空
        while (!QueueEmpty(Q)){
            DeQueue(Q,u);
            strcpy(u1,GetVex(G,u));
            w = FirstAdjVex(G,u1);
            while (w >= 0){
                if (!visited[w]){
                    visited[w] = 1;
                    visit(G.xlist[w].data);
                    EnQueue(Q,w);
                }
                strcpy(w1,GetVex(G,w));
                w = NextAdjVex(G,u1,w1);
            }
        }
    }
    printf("\n");
}

//*****************以上是BFS的模块*************************



int main(){
    int d,i;
    Graph G;
    VertexType vs[LEN],vs2[LEN];

    setUI();
    printf("*请输入你所要执行的操作的序号:");
    while (~scanf("%d",&d)){
        if (d == 0){
            if (G.arcnum || G.vexnum) DestroyGraph(G);
            break;
        }else if (d == 1){
            CreateGraph(G);
        }else if (d == 2){
            DestroyGraph(G);
        }else if (d == 3){
            system("CLS");
            setUI();
            printf("请输入你要查询的顶点:");
            scanf("%s",vs);
            i = LocateVex(G,vs);

            if (i >= 0) printf("%s所在的位置为:%d\n",vs,i+1);
            else printf("图中不存在这个顶点。\n");
        }else if (d == 4){
            system("CLS");
            setUI();
            printf("请输入你要增添的新顶点:");
            scanf("%s",vs);
            InsertVex(G,vs);
            printf("增添完成。\n");
        }else if (d == 5){
            system("CLS");
            setUI();
            printf("请输入你要删除的顶点:");
            scanf("%s",vs);
            DeleteVex(G,vs);
            printf("删除完成。\n");
        }else if (d == 6){
            system("CLS");
            setUI();
            printf("请输入所要增添的弧:(格式:头顶点 尾顶点<回车键>\n");
            scanf("%s%s%*c",vs,vs2);
            InsertArc(G,vs,vs2);
            printf("增添完成。\n");
        }else if (d == 7){
            system("CLS");
            setUI();
            printf("请输入所要删除的弧:(格式:头顶点 尾顶点<回车键>):\n");
            scanf("%s%s%*c",vs,vs2);
            DeleteArc(G,vs,vs2);
            printf("删除完成。\n");
        }else if (d == 8){
            system("CLS");
            setUI();
            printf("深度优先搜索遍历结果:");
            DFSTraverse(G);
        }else if (d == 9){
            system("CLS");
            setUI();
            printf("广度优先搜索遍历结果:");
            BFSTraverse(G);
        }
        printf("\n请继续输入所要执行的操作序号:");
    }
    return 0;
}
