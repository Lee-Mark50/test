//������
#include<iostream>
using namespace std;
typedef struct{
	struct tree *lchild,*rchild;
	int data;
}tree; 
//���������� 
typedef struct{
	elementtype data;
	struct claytreeNode *lchild,*rchild;
	int ltag,rtag;
}claytreeNode;
claytreeNode returntree(claytreeNode T){
	if(T->ltag==0){
		return T=T->lchild;
	}
	else if(T->rtag==0){
		return T=T->rchild;
	}
} 
void Broadclaytree(claytreeNode tree1){ 
	while(tree1->lchild!=NULL||tree1->rchild!=NULL){
	if(tree1->ltag==1||tree1->rtag==1){//���Һ����޺����ǰ�� 
		//����ǰ�� 
		Broadclaytree(returntree tree1);
	}
	else if(tree1->ltag==0){//�����к����ǰ��
		Broadclaytree(tree1->lchild); 
	}
	else if(tree1->rtag==0){//�Һ����к����ǰ�� 
		Broadclaytree(tree1->rchild); 
	}
	}
}
int main(){
	
}
