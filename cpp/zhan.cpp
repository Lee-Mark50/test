#include<iostream>
#include<molloc.h>
using namespace std;
#define MaxSize 10;
typedef  struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

void Initstack(SqStack &S){
	S.top=-1;
}//初始化栈顶指针 
bool Pop(SqStack &S,EleType &x){
	if(S.top==-1)
	return false;
	x=S.data[S.top--];
	return true;
}//出栈 
bool Push(SqStack &S,EleType &x){
	if(s.top==MaxSize-1)//注意是减一 
	return false;
	x=s.data[++S.top];
	return true;
}//入栈 
void testStack(){
	InitStack(); 
} 
