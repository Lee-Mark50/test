#include <iostream>
#include<malloc.h>
using namespace std;

typedef struct LinkedNode{
    int data;
    LinkedNode *next;
}LinkedNode, *LinkedStack;

//��ʼ����ջ
void InitLinkedStack(LinkedStack &S){
    S = (LinkedNode *)malloc(sizeof(LinkedNode));
    S->next = NULL;
}

//�ж��Ƿ�ջ��
bool StackEmpty(LinkedStack S){
    return S->next == NULL ? true : false;//�жϣ���Ϊ�շ���1����Ϊ�շ���0 
}

//��ջ
void Push(LinkedStack &S, int e){
    LinkedNode *p = (LinkedNode *)malloc(sizeof(LinkedNode));
    p->data = e;
    p->next = S;
    S = p;
}

//��ջ
bool Pop(LinkedStack &S, int &e){
    if(S->next == NULL)
        return false;
    e = S->data;
    LinkedNode *p = S;
    S = S->next;
    free(p);
    return true;
}

//��ջ��Ԫ��
bool GetElem(LinkedStack S, int &e){
    if(S->next == NULL)
        return false;
    e = S->data;
    return true;
}
//����ջ
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
    cout<<"������ת����ʮ������";
    cin>>num;
    cout<<"������ת���Ľ��� ";
    cin>>i;
    int l;
	for(l=num%i;l>i;l=num/l){
		
		Push(S,l);//��ȡ�����ѹջ
		//����ת��������
        
	}
	while(l==0){
		GetElem(S,l);
        Pop(S, l);
        cout << l<<endl;
	    }
    
    DestroyStack(S);
}
