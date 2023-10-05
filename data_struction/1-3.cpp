#include<iostream>
#include<stack>
using namespace std;

/*
#define random(x) ((rand()%(100-0))+0)

int main(){
    int i=0;
    while(i<100)
    cout<<random(10)<<'\t';
}
*/

//stack list and numns

/*1-栈的基本操作
InitStack();
StartEmpty();
Push();
Pop();
GetTop();
DestroyStack();
*/
# define MaxSize 50
# define rate 10
typedef struct{
    int top;
    int data[MaxSize];
}Stack;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}LinkNode;

typedef LinkNode* LiStack;//栈类型定义

void InitStack(Stack &S){
    S.top=-1;
}
bool StartEmpty(Stack S){
    if(S.top=-1)
        return true;
    else
        return false;
}
bool Push(Stack &S,int newdata){
    if(!StartEmpty(S)||S.top<MaxSize-1){
        S.data[++S.top]=newdata;
        return true;
    }
    else
        return false;
}
bool Pop(Stack &S,int olddata){
    if(S.top=-1){//这里无需多其他判定
        return false;
    }
    else
        //此时先出栈再减一
        olddata=S.data[S.top--];
        //为突出顺序也可以这里写S.top--
        return true;
}
bool GetTop(){//这玩意除了&和S.top--外其他均与pop操作一样

}
bool DestroyStack(Stack &S){
    
}

//----------------------------------------------------------------------------------------------------
bool algorithm1(){
    //判断序列是否合法
    string a1 ="IOOIOOII";
    int in=0,out=0; 

    //1，先进再出
    if(a1[0]=='O') return false;
    for(int i=0;i<a1.length();i++){
        if(a1[i]=='I') in++;
        else if(a1[i]=='O') out++;
        //2,出的小于等于进的
        if(in<out) return false;
    }
    //3,终态为空
    if(in==out){
    cout<<in<<'\n'<<out<<endl;
    return true;
    }
    else return false;
}


bool algorithm2(LinkNode L,int n){
    //判断单链表全部n个字符是否中心对称
    int i;
    char s[n/2];//字符栈
    LinkNode *p=L.next;//工作指针p，指向待处理的当前元素
    for(i-0;i<n/2;i++){
        s[i]=p->data;
        p=p->next;
    }
    i--;
    if(n%2==1)
        p=p->next;
    while (p!=NULL&&s[i]==p->data){
        i--;
        p=p->next;
    }
    if(i==-1)//空栈
        return 1;//链表中心对称
    else
        return 0;//链表不中心对称
}

//设有两个栈s1s2都采用顺序栈模式，并共享一个存储区[0，···，maxsize-1]
//为了尽量利用空间，减少溢出的可能，可采用栈顶相向的方式，设计s2有关入栈出栈方法

#define maxsize 100
#define elemtp int
typedef struct{
    elemtp stack[maxsize];
    int top[2];
}stk;
stk s;

int push(int i,elemtp x){
    if(i<0||i>1){
        printf("栈号输出不对");
        exit(0);
    }
    if(s.top[1]-s.top[0]==1){
        printf("栈已满\n");
    }
    switch(i){
        case 0:s.stack[++s.top[0]]=x; return 1;break;
        case 1:s.stack[--s.top[1]]=x; return 0;
    }
}

elemtp pop(int i){
    if(i<0||i>1){
        printf("栈号输入错误\n");
        exit(0);
    }
    switch(i){
        case 0:
            if(s.top[0]==-1){
                printf("栈空\n");
                return -1;
            }
            else 
            return s.stack[s.top[0]--];
            break;
        case 1:
            if(s.top[1]==maxsize){
                printf("栈空\n");
                return -1;
            }
            else
                return s.stack[s.top[1]++];
            break;
    }//switch
}


int main(){
    // cout<<algorithm1()<<endl;

}