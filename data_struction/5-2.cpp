#include<iostream>
#include<math.h>

using namespace std;
#define Maxsize 10


struct Btree{
    char data;
    struct Btree *lchild, *rchild;
};

struct Squeue{
    Btree *arr;
    int front, rear;
};

struct Stack
{
    Btree* *arr;//存的是指针
    int len;
    int top;
};


void Q2(Btree *T,Squeue *S,int maxsize){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    struct Btree *p = T;
    struct Btree *r = (struct Btree *)malloc(sizeof(struct Stack));
    

    Stack *createStack(int);
    bool empty(Stack *);
    bool PushS(Stack *,Btree *);
    Btree *top(Stack *);
    bool pop(Stack *);

    s = createStack(maxsize);

    bool deQueueS(Squeue *,Btree *,int);
    bool isEmpty(Squeue *);
    bool enQueueS(Squeue *,Btree *,int);

    enQueueS(S,p,maxsize);


    while(!isEmpty(S)){
        deQueueS(S,r,maxsize);
        PushS(s,r);
        if(r->lchild) enQueueS(S,r->lchild,maxsize);
        if(r->rchild) enQueueS(S,r->rchild,maxsize);
    }
    while(!empty(s)){
        r=top(s);
        pop(s);
    }
}


void Q3(Btree T){//理解啦

    //
    if(!T)
    return 0;

    Btree Squeue[maxsize],p;
    //单队列，队列设置前front，后rear变量，均为-1，指当前队列为空；
    int front=-1,rear=-1;
    //一个指针，last为零，指向队列再根结点遍历完后，根节点出队列，last就是队列下一个元素，含义是指向下一层第一个结点
    //level为高度

    int level=0,last=0;
    //首先将根结点放入队列，rear++，此时rear>front，队不为空，进入循环
    squeue[++rear]=T;
    //根只有一个，出队，后front指针指向第二个，表示接下来从队列第二个开始进
    while(rear>front){
        //该根结点有左右孩子结点？若有，rear++，并入队
        if(p.lchild) squeue[++rear]=p.lchild;
        if(p.rchild) squeue[++rear]=p.rchild;

        //判断，若此时last=front，即指向下一层第一个结点恰好是本层所有结点都出队列，即front也是指向下一个下层开始的第一个要出栈位置（你懂意思）
        if(front==last){
            level++;
            last=rear;
        }
        //层数++————因为此时这层遍历完了，且队列非空，就将rear赋给last，将目前还未出队列的第一个元素让last来指向，符合原设
        //继续循环......
    }

}

int main(){
    Q2();
}