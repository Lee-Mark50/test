//ʵ�ֵ��������� 
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode LNode;
typedef struct LNode *LinkList;

struct LNode{
	int data;
	struct LNode *next;
}; 

bool InitList(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=NULL;	
	return true;
}
//�����жϷ�ʽΪ�� 
bool Empty(LinkList L){
	if(L->next!=NULL){
		return false;
	}
	else return true;
}
//�ڵ������в��� 
void Inset(LinkList &L,int i,int e){//������e�����i�͵�i-1�����֮�� 
	if(i<1){
	cout<<"������i<1����ʽ"; 
	}
	LNode *p;//ָ��pָ��ǰ��� 
	int j=0;//��ǰָ��pָ����ǵ�i����� 
	p=L;//Lָ��ͷ��� //ͷָ�� 
	while(p!=NULL&&j<i-1)//������ǿ���ѭ���ҵ���i-1�����
	{
		p=p->next;
		j++; 
	} 
	if(p==NULL) cout<<"�ñ��ǿձ���";
	LNode *s=(LNode *)malloc(sizeof(LNode));//����s�Ŀռ� 
	
	s->data=e;
	s->next=p->next;
	p->next=s;
	
	cout<<"����ɹ���"; 
} 

bool ListDelete(LinkList &L,int i,int &e){
	if(i<1){
	cout<<"������i<1����ʽ"; 
	}
	LNode *p;//ָ��pָ��ǰ��� 
	int j=0;//��ǰָ��pָ����ǵ�i����� 
	p=L;//Lָ��ͷ��� //ͷָ�� 
	while(p!=NULL&&j<i-1)//������ǿ���ѭ���ҵ���i-1�����
	{
		p=p->next;
		j++; 
	} 
	if(p==NULL) cout<<"�ñ��ǿձ���";
	if(p->next==NULL)cout<<"�ñ����һ�����Ϊ��";
	LNode *q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	cout<<"�ͷųɹ���"; 
} 







int main(){
	LinkList L;
	
	if(InitList(L)==true){
		cout<<"����ɹ��ұ�Ϊ��"<<endl;
	}
	else
	cout<<"����ʧ���ұ�Ϊ�ǿ�";
	
	Inset(L,2,10);//Ϊʲô��������ñ��ǿձ� ������
}

