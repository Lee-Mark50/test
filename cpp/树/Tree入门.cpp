#include<iostream>
using namespace std;

typedef struct tree{
	int data;
	struct tree *lchild,*rchild;
	bool Isempty;
}tree,TreeNode; 
void midview(TreeNode atree){
	//ÖÐÐò±éÀú
	while(!atree->Isempty){
		PreOrder(atree->lchild);
		visit(atree);
		PreOrder(atree->rchild);
	}
}
int main(){
	TreeNode atree=new TreeNode; 
}
