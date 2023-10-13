//根据输入序列10，6，1，4，5，11，12，13， 8， 9，构造一棵平衡二叉树，要求写出构建过程。
//
//3阶B-树的插入与删除操作，插入数据：80，195，删除数据：260；
#include<iostream>
#include<malloc.h>
using namespace std;
//typedef struct tree{
//	int data;
//	int *ls,*rs;
//};
typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode//二叉树节点结构体
{
	ElementType Data;//节点数据
	AVLTree Left;
	AVLTree Right;
	int Height;//节点高
};
int MAX(int HL, int HR)
{
	return HL > HR ? HL : HR;
}
//void singleChangeTree(AVLTree A)//添加新节点后判断所在二叉树的平衡性 
//{
//	for(int i:A){//遍历二叉树 
//		if(A->Left!=A->Right)//如果当前二叉树不平衡——左大于右，左螺旋法 
//			{
//				AVLTree B=A->Left;
//				A->Left=B->Right;
//				B->right=A;
//			}			//则考虑左右单旋来平衡 
//		A->Height=MAX(A->Left.Height,A->Right.Height)+1;
//		B->Height=MAX(B->Left.Height,A->Height)+1;	
//	}
//}
int GetHeight(AVLTree A) {//获取树高度 
	int a, b, max;
	if (A) {
		a = GetHeight(A->Left);
		b = GetHeight(A->Right);
		max = a > b ? a : b;
		return (max + 1);
	}
	else return 0;
}
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	//只需要更新A，B的节点的高度
	A->Height = MAX(GetHeight(A->Left), GetHeight(A->Right)) + 1;//更新A节点的树高
	B->Height = MAX(GetHeight(B->Right), A->Height) + 1;//更新B节点的树高
	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	//只需要更新A，B的节点的高度
	A->Height = MAX(GetHeight(A->Left), GetHeight(A->Right)) + 1;//更新A节点的树高
	B->Height = MAX(GetHeight(B->Right), A->Height) + 1;//更新B节点的树高
	return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A) {
	A->Left = SingleRightRotation(A->Left);
	A = SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotaion(AVLTree A) {
	A->Right = SingleLeftRotation(A->Right);
	A = SingleRightRotation(A);
}
AVLTree VALTreeInsert(AVLTree AT, ElementType Data) {

	if (AT == NULL)//如果这个节点为空，就在这里建立一个节点，相当于把数据插入到二叉树上，接下来要做的就是判断和调整
	{
		AT = (AVLTree)malloc(sizeof(struct AVLNode));
		AT->Data = Data;
		AT->Left = AT->Right = NULL;//把指针置空
		AT->Height = 1;//记得置1
	}
	else if (Data < AT->Data)//如果要插入的数据的值小于当前节点的值，就插入到该节点的左子树
	{//递归遍历二叉树然后把数据插入到二叉树里面，此时我们已经跑到二叉树底层了，然后再从底层一点一点的往上返回判断平衡因子，发现不平衡问题就要调整
		AT->Left = VALTreeInsert(AT->Left, Data);//接着往左子树递归遍历下去
		if ((GetHeight(AT->Left) - GetHeight(AT->Right)) == 2)//因为是往该节点的左子树中插入数据，如果该节点变成了发现问题的节点，则该节点的平衡因子只能是2，不可能是-2
		{
			if (Data < AT->Left->Data)//如果要插入的数据小于该节点的左子树的第一个节点的数据，则表示该数据插入到了该节点的左子树的左边去了，我们要做的就是左单旋
				AT = SingleLeftRotation(AT);//左单旋
			else//否则就是插入到该节点的左子树的第一个节点的右边去了，我们要做的是左-右双旋
				AT = DoubleLeftRightRotation(AT);//左右双旋
		}
	}
	else if (Data > AT->Data)//如果要插入的数据的值大于当前节点的值,就插入到该节点的右子树
	{
		AT->Right = VALTreeInsert(AT->Right, Data);
		if ((GetHeight(AT->Left) - GetHeight(AT->Right)) == -2)//因为是往该节点的右子树中插入数据，如果这个节点变成了发现问题的节点,则该节点的平衡因子只能是-2，不可能是-2
		{
			if (Data > AT->Right->Data)//如果要插入的数据大于该节点的右子树的第一个节点的数据，则表示该数据插入到的该节点的右子树的右边去了，我们要做的是右单旋
				AT = SingleRightRotation(AT);//右单旋
			else//否则该数据就是插入到了该节点的右子树第一个节点的左边去了，我们要做的是右-左双旋
				AT = DoubleRightLeftRotaion(AT);//右左双旋
		}
	}
	else//如果要插入的数据的值等于当前节点的值，则输出该值已存在，不进行插入操作
		printf("该值已存在\n");
	AT->Height = MAX(GetHeight(AT->Left), GetHeight(AT->Right)) + 1;//插入节点，调整二叉树之后都要更新树的高度，别忘了加1
	return AT;
}

//AVLTree (AVLTree A,int data){//自写 
//	if(A==NULL){//如果没有结点，创建新节点 
//		
//	}
//}
void MidBroading(AVLTree AT){
	if (AT != NULL)
	{
		MidBroading(AT->Left);//输出左节点
		printf("%d ", AT->Data);//输出节点的值
		MidBroading(AT->Right);//输出右节点
	}
}
void tree() {

	//开始构建所求二叉树
	int data;
	AVLTree AT = NULL;
	while (1) {
		cin >> data;
		if (!data) {
			break;
		}
		AT = VALTreeInsert(AT, data);
		MidBroading(AT);
	}	
}
int main() {
	tree();
}
