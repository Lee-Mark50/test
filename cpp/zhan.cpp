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
}//��ʼ��ջ��ָ�� 
bool Pop(SqStack &S,EleType &x){
	if(S.top==-1)
	return false;
	x=S.data[S.top--];
	return true;
}//��ջ 
bool Push(SqStack &S,EleType &x){
	if(s.top==MaxSize-1)//ע���Ǽ�һ 
	return false;
	x=s.data[++S.top];
	return true;
}//��ջ 
void testStack(){
	InitStack(); 
} 
