//二叉树
#include<iostream>
using namespace std;
typedef struct{
	struct tree *lchild,*rchild;
	int data;
}tree; 
//线索二叉树 
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
	if(tree1->ltag==1||tree1->rtag==1){//左，右孩子无后继有前驱 
		//回溯前驱 
		Broadclaytree(returntree tree1);
	}
	else if(tree1->ltag==0){//左孩子有后继无前驱
		Broadclaytree(tree1->lchild); 
	}
	else if(tree1->rtag==0){//右孩子有后继无前驱 
		Broadclaytree(tree1->rchild); 
	}
	}
}
int main(){
	
}
