//实现单链表并定义 
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
//或者判断方式为下 
bool Empty(LinkList L){
	if(L->next!=NULL){
		return false;
	}
	else return true;
}
//在单链表中插入 
void Inset(LinkList &L,int i,int e){//将数字e插入第i和第i-1个结点之间 
	if(i<1){
	cout<<"不存在i<1的形式"; 
	}
	LNode *p;//指针p指向当前结点 
	int j=0;//当前指针p指向的是第i个结点 
	p=L;//L指向头结点 //头指针 
	while(p!=NULL&&j<i-1)//当链表非空且循环找到第i-1个结点
	{
		p=p->next;
		j++; 
	} 
	if(p==NULL) cout<<"该表是空表了";
	LNode *s=(LNode *)malloc(sizeof(LNode));//申请s的空间 
	
	s->data=e;
	s->next=p->next;
	p->next=s;
	
	cout<<"插入成功！"; 
} 

bool ListDelete(LinkList &L,int i,int &e){
	if(i<1){
	cout<<"不存在i<1的形式"; 
	}
	LNode *p;//指针p指向当前结点 
	int j=0;//当前指针p指向的是第i个结点 
	p=L;//L指向头结点 //头指针 
	while(p!=NULL&&j<i-1)//当链表非空且循环找到第i-1个结点
	{
		p=p->next;
		j++; 
	} 
	if(p==NULL) cout<<"该表是空表了";
	if(p->next==NULL)cout<<"该表的下一个结点为空";
	LNode *q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	cout<<"释放成功！"; 
} 







int main(){
	LinkList L;
	
	if(InitList(L)==true){
		cout<<"创设成功且表为空"<<endl;
	}
	else
	cout<<"创设失败且表为非空";
	
	Inset(L,2,10);//为什么会输出“该表是空表” ？？？
}

