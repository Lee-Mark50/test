//
#include<iostream>

// struct Btree{
//     char arr;
//     struct Btree *lchild,*rchild;
// };

struct Queue{
    int front,rear;
    Btree *arr;
};

//二叉树层次遍历非递归算法 review
void levelOrder(Btree T){

    InitQueue(Q);
    Btree *p;
    InQueue(Q,T);//根结点入队
    while(!Empty(Q)){
        Dequeue(Q,p);
        if(p->lchild!==NULL){
            Enqueue(Q,p->lchild);
        }
        if(p->rchild!==NULL){
            Enqueue(Q,p->rchild);
        }
    }

}

//判断是否为二叉搜索树（2022）
//先写算法设计思路：遍历全树，若左结点大于所有左结点，小于所有右节点，即返回true

typedef int ElementType;//这里使用为了程序可读性，一旦需要修改为double，只需在此修改
typedef struct TNode *Position;
typedef Position BTree;
struct TNode{
    ElementType Data;
    BTree left;
    BTree right;
};

void judgeBST(Btree T){
    Btree Q=T;
    while(!ISEmpty(Q)){//从根向结点遍历
        if(p>p->lchild)
    }
}



Position searchBst(ElementType X, BTree BST){
    if(!BST) return NULL;
    if(X > BST->Data)
        return searchBst(X,BST->left);
    if(X < BST->Data)
        return searchBst(X,BST->right);
    if(X == BST->Data)
    return BST;
}//递归方式实现，效率低，可以优化为循环【尾递归用循环方式实现】，非递归函数执行效率高


Position SearchBst(ElementType X,BTree BST){
    if(!BST) return NULL;
    while(BST){
        if(X>BST->Data){
            BST=BST->right;
        }
        if(X<BST->Data){
            BST=BST->left;
        }
        else{
            return BST;
        }
    }
}


Position FindMaxorMin(BTree BST){
    while(BST){
        if(!BST) return NULL;
        else if(!BST->left) return BST;
        else BST == BST->left;
    }
    if(!BST) return NULL;
        else if(BST->left) return BST;
        else return FindMaxorMin(BST->left);

    if(!BST) return NULL;
        else if(BST->right) return BST;
        else return FindMaxorMin(BST->right);
}