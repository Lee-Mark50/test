//tree in all
//任意一棵非空树要满足：1）有且仅有一个特定的称为根的结点 2）当n>1时，其余结点可分为m>0个互不相交的有限集，其中每个集合本身又是一棵属于根的子树 
//基本术语和概念解释： 1）考虑结点k；祖先和孩子结点关系  2)结点的度【树中一个结点的孩子个数】 3）树的度【树中结点最大度数】 4）结点的深度高度和层次【根结点算第一层。几层高度即为几】 5)有序树和无序树【结点的各子树从左到右次序】 6）路径和路径长度【由这两个结点之间所经过的结点序列构成，路径长度是路径上经过边个数】
//孩子结点和叶子结点含义——自上到下，树结构为根节点->子节点->叶子结点；    
//叶子结点：自己下面不再连接有节点的节点（即末端），称为叶子节点（又称为终端结点）

#include<iostream>
#include<math.h>
using namespace std;

//5.2.3.5

#define MaxSize 10

typedef int ElemType;

typedef struct{
    ElemType data;
    bool isEmpty;
}TreeNode;

void InitTree(TreeNode T[]){//结点初始化
    for(int i=0;i<MaxSize;i++){
        T[i].isEmpty=true;
    }
}

void InputData(TreeNode T[]){
    int j=3;
    for(int i=1;i<MaxSize;i++){
        T[i].data=j;
        T[i].isEmpty=false;
        j+=2;
    }
}

bool OutlChild(TreeNode T[],int i,ElemType &e){
    if(i>=MaxSize) //超出树的范围结点
        return false;
    if(T[2*i].isEmpty==true || 2*i>MaxSize) //叶子结点
        return false;
    else{
        e=T[2*i].data;
    }
    return true;
}

bool OutrChild(TreeNode T[],int i,ElemType &e){
    if(i>=MaxSize) //超出树的范围结点
        return false;
    if(T[2*i+1].isEmpty==true || 2*i+1>MaxSize) //叶子结点
        return false;
    else{
        e=T[2*i+1].data;
    }
    return true;
}

bool OutFather(TreeNode T[],int i,ElemType &e){
    if(i>MaxSize)
    return false;
    if(i/2>=MaxSize || T[i/2].isEmpty==true)
    return false;
    else{
        return e=T[i/2].data;
    }
}

int TreeNodefloor(TreeNode T[],int i){
    int m=2,n;
    double a=floor(log(i)/log(m))+1;
    if(i>=MaxSize)
        return -1;
    else
        return a;
}

bool IsLeaf(TreeNode T[],int i){
    if(2*i>MaxSize-1)
        return true;
    else 
        return false;
}

int NearFatherPoint(TreeNode T[],int i,int j){ //判断ij两个结点最近的根结点并返回值
    if(i>MaxSize || j>MaxSize)
        return -1;
    while(i!=j){
        if(i>j) i=i/2;
        else j=j/2;
    }
    return T[i].data;
}





int main(){

}