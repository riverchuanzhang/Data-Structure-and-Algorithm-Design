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
//����ͼ��ʮ�������洢��ʾ

typedef char InfoType;       //�ø��������洢����Ϣ
typedef char VertexType;

typedef struct ArcBox{        //��ʮ������ʵ�ֵĻ�
    int tailvex,headvex;      //����β�����ͷ�����λ��
    ArcBox *hlink,*tlink;     //�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ������
    InfoType *info;           //�û��������Ϣ��ָ��
}ArcBox;

typedef struct VexNode{       //�����ʹ洢�������Ϣ
    VertexType data[LEN];          //�洢������Ϣ
    ArcBox *firstin,*firstout;//�ֱ�ָ��ö����һ���뻡�ͳ���
}VexNode;

typedef struct Graph{         //�����ͱ�ʾʮ������ʵ�ֵ�����ͼ
    VexNode xlist[N];         //xlist[i]��ʾ����i�ı�ͷ����
    int vexnum,arcnum;        //����ͼ�ĵ�ǰ����ͻ���
}Graph;

void setUI()
{
    //����������ɫ
    char com[20]={0};
    sprintf(com,"color 1%d",3);
    system(com);
    printf("**********************************************\n");
    printf("* ��������ִ����Ӧ�Ĳ���:                    *\n");
    printf("* 1:��������ͼ;                              *\n");
    printf("* 2:����ͼ�Ĳ���;                            *\n");
    printf("* 3:���Ҷ���u��ͼ�е�λ��;                   *\n");
    printf("* 4:�����¶���;                              *\n");
    printf("* 5:ɾ�����㼰����صĻ�;                    *\n");
    printf("* 6:�����µĻ�;                              *\n");
    printf("* 7:ɾ��������;                              *\n");
    printf("* 8:��ͼ���������������;                    *\n");
    printf("* 9:��ͼ���й����������;                    *\n");
    printf("* 0:���в���������                           *\n");
    printf("**********************************************\n\n");
}


//Graph G;  //����ı���Ҫ��ȫ�ֵģ�������ĳЩ�����������л����

void output(Graph &G){
    int i;
    ArcBox *p;
    printf("������������ͼ����%d�����㣬%d����:\n",G.vexnum,G.arcnum);
    for (i = 0; i < G.vexnum; ++i){
        printf("����%s�ģ����:",G.xlist[i].data);
        p = G.xlist[i].firstin;
        while (p){
            printf("%s",G.xlist[p->tailvex].data);
            if (p->info) printf("(������ϢΪ%s) ",p->info);
            else printf(" ");
            p = p->hlink;
        }
        printf("����:");
        p = G.xlist[i].firstout;
        while (p){
            printf("%s",G.xlist[p->headvex].data);
            if (p->info) printf("(������ϢΪ%s) ",p->info);
            else printf(" ");
            p = p->tlink;
        }
        printf("\n");
    }
}

//����ͼ���붥��u��Ϣ��ͬ�Ķ����λ�ã��������ڷ���-1
int LocateVex(Graph &G,VertexType *u){
    int i;
    for (i = 0; i < G.vexnum; ++i)    //��ѭ���ҳ��붥��u��Ϣ��ͬ�Ķ���
        if (!strcmp(G.xlist[i].data,u)) return i;
    return -1;                        //���Ҳ�������-1
}

typedef int Status;      //������ֻ������ֵ��OK(��ʾ��ȷ)��ERROR(��ʾ����)

//����ʮ������ʵ�ֵ�����ͼ�������������Ϣ
Status CreateGraph(Graph &G){
    int IncInfo;
    VertexType v1[LEN],v2[LEN];
    char s[LEN];
    int i,j,k;
    ArcBox *p;

    system("CLS");
    setUI();
    printf("��������Ҫ������ͼ�Ķ������n(0<n<=100):");
    scanf("%d",&G.vexnum);
    if (G.vexnum > N || G.vexnum < 0){
        printf("��������ݳ�����Χ��");
        return ERROR;
    }
    system("CLS");
    setUI();
    printf("�����������ͼ�Ļ���:");
    scanf("%d%*c",&G.arcnum);
    if (G.arcnum > N*N || G.arcnum < 0){
        printf("��������ݳ�����Χ��");
        return ERROR;
    }
    system("CLS");
    setUI();
    printf("�����㴴���Ļ��Ƿ����������Ϣ(��������1����������0):");
    scanf("%d",&IncInfo);

    system("CLS");
    setUI();
    printf("������%d�������Ԫ��ֵ(ÿ��ֻ����һ��ֵ):\n",G.vexnum);
    for (i = 0; i < G.vexnum; ++i){
        scanf("%s",&G.xlist[i].data);
        G.xlist[i].firstin = G.xlist[i].firstout = NULL;//������ָ���ʼ��
    }

    system("CLS");
    setUI();
    printf("������%d����(�����ʽ:��β ��ͷ<�س���>):\n",G.arcnum);
    for (k = 0; k < G.arcnum; ++k){
        //scanf("%s",&v1);
        //scanf("%s",&v2);
        scanf("%s%s%*c",v1,v2);
        i = LocateVex(G,v1);         //ȷ��v1��ͼG�е�λ��
        j = LocateVex(G,v2);         //ȷ��v2��ͼG�е�λ��
        p = (ArcBox*)malloc(sizeof(ArcBox));//���ɵ��������Ŀռ�
        //����5��ʵ��ʮ�������Ĳ������
        p->tailvex = i;
        p->headvex = j;
        p->hlink = G.xlist[j].firstin;
        p->tlink = G.xlist[i].firstout;
        G.xlist[j].firstin = G.xlist[i].firstout = p;
        //*****************************
        if (IncInfo){       //��������������Ϣ����������������
            printf("�������������Ϣ:");
            scanf("%s",s);
            p->info = (InfoType*)malloc((strlen(s)+1)*sizeof(InfoType));
            strcpy(p->info,s);
        }else p->info = NULL;
    }
    system("CLS");
    setUI();
    output(G);
    printf("ͼ�Ĵ�������ɡ�\n");
    return OK;
}

//��������ͼG,���ͷ�ͼG�йص��ڴ棬�����ڴ�й¶
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
    printf("ͼG�����١�\n");
}

//����v��ֵ
VertexType* GetVex(Graph &G,int v){
    return G.xlist[v].data;
}

//������v���и�ֵ���ɹ�����OK�����򷵻�ERROR
Status PutVex(Graph &G,VertexType *v,VertexType *value){
    int i = LocateVex(G,v);
    if (i < 0) return ERROR;
    strcpy(G.xlist[i].data,value);
    return OK;
}

//���ض���v�ĵ�һ���ڽӶ������ţ�������v�������ڽӶ����򷵻�-1
int FirstAdjVex(Graph &G,VertexType *v){
    int i = LocateVex(G,v);;
    ArcBox *p = G.xlist[i].firstout;
    if (p) return p->headvex;
    else return -1;
}

//���ض���v����һ���ڽӶ������ţ���w�Ƕ���v�����һ���ڽӵ��򷵻�-1
int NextAdjVex(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    ArcBox *p;
    i = LocateVex(G,v);      //i�Ƕ���v�����
    j = LocateVex(G,w);      //j�Ƕ���w�����
    p = G.xlist[i].firstout; //pָ�򶥵�v�ĵ�1������
    //ǰ��������w��v���ڽӶ���
    while (p && p->headvex!=j) p = p->tlink;//֪��pָ�򶥵�w��Ϊ��
    if (p) p = p->tlink;     //��w����v�����һ���ڽӶ��㣬�����w����һ���ڽӶ���
    if (p) return p->headvex;//������һ���������
    else return -1;          //����w��v�����һ������
}

//��ͼG�������¶���v
void InsertVex(Graph &G,VertexType *v){
    strcpy(G.xlist[G.vexnum].data , v);
    G.xlist[G.vexnum].firstin = G.xlist[G.vexnum].firstout = NULL;
    ++G.vexnum;               //ͼG�Ķ�������1
}

//ɾ��ͼG�ж���v������صĻ������ͷ��ڴ�
Status DeleteVex(Graph &G,VertexType *v){
    int j,k;
    ArcBox *p,*q;

    k = LocateVex(G,v);
    if (k < 0 || k >= G.vexnum) return ERROR;//������v����ͼG���򷵻�ERROR
    for (j = 0; j < G.vexnum; ++j) if (j != k){//���ҳ�k����Ķ���
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
    //ɾ���붥��v�йصĳ���
    p = G.xlist[k].firstout;
    while (p){
        q = p->tlink;
        if (p->info) free(p->info);
        free(p);
        --G.arcnum;
        p = q;
    }
    //ɾ������v���뻡
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
    //ɾ���붥��v�йص��뻡
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

//��ͼG��������<v,w>
int InsertArc(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    int IncInfo;
    char s[LEN];
    ArcBox *p;

    i = LocateVex(G,v);  //��β�����
    j = LocateVex(G,w);  //��ͷ�����
    if (i<0 || j<0) return 0;
    p = (ArcBox*)malloc(sizeof(ArcBox));//���ɵ��������Ŀռ�
    //����5��ʵ��ʮ�������Ĳ������
    p->tailvex = i;
    p->headvex = j;
    p->hlink = G.xlist[j].firstin;
    p->tlink = G.xlist[i].firstout;
    G.xlist[j].firstin = G.xlist[i].firstout = p;
    //*****************************
    ++G.arcnum;          //������1
    printf("���Ƿ����������Ϣ��(��������1����������0)");
    scanf("%d",&IncInfo);
    if (IncInfo){
        printf("������û�����Ϣ��");
        scanf("%s",s);
        p->info = (InfoType *)malloc((strlen(s)*sizeof(InfoType)));
        strcpy(p->info,s);
    }else p->info = NULL;
    return 1;
}

//��ͼG��ɾ����<v,w>
Status DeleteArc(Graph &G,VertexType *v,VertexType *w){
    int i,j;
    ArcBox *p1,*p2;

    i = LocateVex(G,v);      //��β�����
    j = LocateVex(G,w);      //��ͷ�����
    if (i<0 || j<0 || i == j) return ERROR;    //��v��w����ͼG���򷵻�ERROR
    //���²���ʵ�֣��ڽ��v�ĳ����в���<v,w>��ɾȥ
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

    //���²���ʵ�֣��ڽ��w���뻡�в���<v,w>��ɾȥ
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
    if (p2->info) free(p2->info);  //��ջ������Ϣ
    free(p2);                      //��ջ����
    --G.arcnum;                    //������1
    return OK;
}

//****************������DFS��ģ��**************************

int visited[N];  //visited[i]Ϊ1��ʾ����i�����ʹ���Ϊ0��ʾ��û������

void visit(VertexType *x){ printf("%s ",x); }//�������ʵĺ���

void dfs(Graph &G,int i){
    ArcBox *p;
    visited[i] = 1;           //��Ƕ���i�ѱ�����
    visit(G.xlist[i].data);   //���ʶ���i
    //����3��ʵ�֣�������i�ĳ�������������ȷ���
    p = G.xlist[i].firstout;
    while (p && visited[ p->headvex ]) p = p->tlink;
    if (p && !visited[ p->headvex ]) dfs(G,p->headvex);
}

void DFSTraverse(Graph &G){
    int i;
    //��ʼ��visited���飬��ʾ��û�����ʹ�
    for (i = 0; i < G.vexnum; ++i) visited[i] = 0;
    //������i֮ǰû�����ʹ����������������������
    for (i = 0; i < G.vexnum; ++i) if (!visited[i]) dfs(G,i);
    printf("\n");
}

//****************������DFS��ģ��**************************

//*****************������BFS��ģ��*************************

typedef int QElemType;

typedef struct SqQueue{//���е�˳�򴢴�ṹ
    QElemType *base;   //��̬����洢�ռ�
    int front;         //ͷָ�룬ָ�����ͷԪ��
    int rear;          //βָ�룬ָ�����βԪ�ص���һ��λ��
}SqQueue;

//����һ���ն���Q
Status InitQueue(SqQueue &Q){
    //�����з���ռ�
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;  //��ͷ��β��ʼ��
    return OK;
}

//������QΪ�գ�����1�����򷵻�0
int QueueEmpty(SqQueue Q){
    if (Q.front == Q.rear) return 1;
    else return 0;
}

//��Ԫ��e���뵽��β
Status EnQueue(SqQueue &Q,QElemType e){
    if ((Q.rear + 1)%MAXQSIZE == Q.front) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%MAXQSIZE;
    return OK;
}

//ɾ����ͷԪ�أ�����e������ֵ
Status DeQueue(SqQueue &Q,QElemType &e){
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

//��ͼG���й����������
void BFSTraverse(Graph &G){
    int v,u,w;
    VertexType u1[LEN],w1[LEN];
    SqQueue Q;

    for (v = 0; v < G.vexnum; ++v) visited[v] = 0;   //����ѯ�Ƿ񱻷��ʵ�������г�ʼ��
    InitQueue(Q);                                    //��������
    for (v = 0; v < G.vexnum; ++v) if (!visited[v]){ //��vδ�����ʣ����������
        visited[v] = 1;                              //���v�ѱ�����
        visit(G.xlist[v].data);                      //��visit()�������ʶ���v
        EnQueue(Q,v);                                //��v�����β
        //�����ѭ��ʵ��ͼ�Ĺ����������
        //�����зǿգ����ͷ��β���б�����ÿ��ɾ������ȡ��ͷ����
        //���뵱ǰ�������ڵ�δ�����ʵĶ�������β��ֱ������Ϊ��
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

//*****************������BFS��ģ��*************************



int main(){
    int d,i;
    Graph G;
    VertexType vs[LEN],vs2[LEN];

    setUI();
    printf("*����������Ҫִ�еĲ��������:");
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
            printf("��������Ҫ��ѯ�Ķ���:");
            scanf("%s",vs);
            i = LocateVex(G,vs);

            if (i >= 0) printf("%s���ڵ�λ��Ϊ:%d\n",vs,i+1);
            else printf("ͼ�в�����������㡣\n");
        }else if (d == 4){
            system("CLS");
            setUI();
            printf("��������Ҫ�������¶���:");
            scanf("%s",vs);
            InsertVex(G,vs);
            printf("������ɡ�\n");
        }else if (d == 5){
            system("CLS");
            setUI();
            printf("��������Ҫɾ���Ķ���:");
            scanf("%s",vs);
            DeleteVex(G,vs);
            printf("ɾ����ɡ�\n");
        }else if (d == 6){
            system("CLS");
            setUI();
            printf("��������Ҫ�����Ļ�:(��ʽ:ͷ���� β����<�س���>\n");
            scanf("%s%s%*c",vs,vs2);
            InsertArc(G,vs,vs2);
            printf("������ɡ�\n");
        }else if (d == 7){
            system("CLS");
            setUI();
            printf("��������Ҫɾ���Ļ�:(��ʽ:ͷ���� β����<�س���>):\n");
            scanf("%s%s%*c",vs,vs2);
            DeleteArc(G,vs,vs2);
            printf("ɾ����ɡ�\n");
        }else if (d == 8){
            system("CLS");
            setUI();
            printf("������������������:");
            DFSTraverse(G);
        }else if (d == 9){
            system("CLS");
            setUI();
            printf("������������������:");
            BFSTraverse(G);
        }
        printf("\n�����������Ҫִ�еĲ������:");
    }
    return 0;
}