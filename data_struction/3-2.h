#include<iostream>
using namespace std;

//队列 Queue
#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;

//基本操作
// void InitQueue(SqQueue &Q);
// void QueueEmpty(SqQueue Q);
// void EnQueue(SqQueue &Q,int &x);
// void DeQueue(SqQueue &Q,int &x);
// void GetHead(SqQueue Q,int &x);

//循环队列
void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}
bool IsEmpty(SqQueue Q){
    if(Q.front==Q.rear) return true;
    else return false;
}
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%Maxsize==Q.front) return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    return true;
}
bool DeQueue(SqQueue &Q,int &x){
    if(Q.rear==Q.front) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%Maxsize;
    return true;
}

//队列链式存储结构如下：
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}*LinkQueue;

void InitQueue_link(LinkQueue &Q){
    Q->front=Q->rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next=NULL;
}
bool IsEmpty_link(LinkQueue Q){
    if(Q->front==Q->rear) return true;
    else return false;
}
void EnQueue_link(LinkQueue &Q,int x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
}
bool DeQueue_link(LinkQueue &Q,int &x){
    if(Q->front==Q->rear) return false;
    LinkNode *p=Q->front->next;
    x=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return true;
}
//注：问题——为甚有的是-> 有的是.？
//结构体用.    结构体指针用->,功能随大致相等，但仍有区别
//https://www.zhihu.com/question/49164544

//申明完队列后，由于队列仍然遵循先进先出原则，且循环队列操作仍如上，所以应用和相关算法如下进行封装。

void queue1(SqQueue Q){
    //Q为队列，S为空栈，实现元素逆置
    
}