#include<iostream>
using namespace std;


struct Btree{
    char data;
    struct Btree *lchild;
    struct Btree *rchild;
};

struct Stack{
    char* arr;
    int len;
    int top;
};


void InOrder(Btree *T,Stack *S){//中序遍历非递归出栈算法
    Btree *p=T;
    bool empty(Stack *);
    bool pushS(Stack *,Btree *);
    Btree *top(Stack *);
    bool pop(Stack *);

    while(!empty(S)||p){
        if(p){
            pushS(S,p);//入栈
            p=p->lchild;
        }
        else{
            p=top(S);
            pop(S);//出栈
            p=p->rchild;
        }
    }
}