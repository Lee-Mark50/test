#include <iostream>
#include<malloc.h>
using namespace std;

typedef struct LinkedNode{
    int data;
    LinkedNode *next;
}LinkedNode, *LinkedStack;

//初始化链栈
void InitLinkedStack(LinkedStack &S){
    S = (LinkedNode *)malloc(sizeof(LinkedNode));
    S->next = NULL;
}

//判断是否栈空
bool StackEmpty(LinkedStack S){
    return S->next == NULL ? true : false;//判断，若为空返回1；不为空返回0 
}

//入栈
void Push(LinkedStack &S, int e){
    LinkedNode *p = (LinkedNode *)malloc(sizeof(LinkedNode));
    p->data = e;
    p->next = S;
    S = p;
}

//出栈
bool Pop(LinkedStack &S, int &e){
    if(S->next == NULL)
        return false;
    e = S->data;
    LinkedNode *p = S;
    S = S->next;
    free(p);
    return true;
}

//读栈顶元素
bool GetElem(LinkedStack S, int &e){
    if(S->next == NULL)
        return false;
    e = S->data;
    return true;
}
//销毁栈
void DestroyStack(LinkedStack &S){
    if(S->next != NULL){
        LinkedNode *s = S;
        S = S->next;
        free(s);
    }
}


int main(){
    LinkedStack S;
    InitLinkedStack(S);
    
    int num,i; 
    cout<<"输入需转换的十进制数";
    cin>>num;
    cout<<"输入需转换的进制 ";
    cin>>i;
    int l;
	for(l=num%i;l>i;l=num/l){
		
		Push(S,l);//将取余的数压栈
		//将需转换数更换
        
	}
	while(l==0){
		GetElem(S,l);
        Pop(S, l);
        cout << l<<endl;
	    }
    
    DestroyStack(S);
}
