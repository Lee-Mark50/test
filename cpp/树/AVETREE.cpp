//������������10��6��1��4��5��11��12��13�� 8�� 9������һ��ƽ���������Ҫ��д���������̡�
//
//3��B-���Ĳ�����ɾ���������������ݣ�80��195��ɾ�����ݣ�260��
#include<iostream>
#include<malloc.h>
using namespace std;
//typedef struct tree{
//	int data;
//	int *ls,*rs;
//};
typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode//�������ڵ�ṹ��
{
	ElementType Data;//�ڵ�����
	AVLTree Left;
	AVLTree Right;
	int Height;//�ڵ��
};
int MAX(int HL, int HR)
{
	return HL > HR ? HL : HR;
}
//void singleChangeTree(AVLTree A)//����½ڵ���ж����ڶ�������ƽ���� 
//{
//	for(int i:A){//���������� 
//		if(A->Left!=A->Right)//�����ǰ��������ƽ�⡪��������ң��������� 
//			{
//				AVLTree B=A->Left;
//				A->Left=B->Right;
//				B->right=A;
//			}			//�������ҵ�����ƽ�� 
//		A->Height=MAX(A->Left.Height,A->Right.Height)+1;
//		B->Height=MAX(B->Left.Height,A->Height)+1;	
//	}
//}
int GetHeight(AVLTree A) {//��ȡ���߶� 
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
	//ֻ��Ҫ����A��B�Ľڵ�ĸ߶�
	A->Height = MAX(GetHeight(A->Left), GetHeight(A->Right)) + 1;//����A�ڵ������
	B->Height = MAX(GetHeight(B->Right), A->Height) + 1;//����B�ڵ������
	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	//ֻ��Ҫ����A��B�Ľڵ�ĸ߶�
	A->Height = MAX(GetHeight(A->Left), GetHeight(A->Right)) + 1;//����A�ڵ������
	B->Height = MAX(GetHeight(B->Right), A->Height) + 1;//����B�ڵ������
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

	if (AT == NULL)//�������ڵ�Ϊ�գ��������ｨ��һ���ڵ㣬�൱�ڰ����ݲ��뵽�������ϣ�������Ҫ���ľ����жϺ͵���
	{
		AT = (AVLTree)malloc(sizeof(struct AVLNode));
		AT->Data = Data;
		AT->Left = AT->Right = NULL;//��ָ���ÿ�
		AT->Height = 1;//�ǵ���1
	}
	else if (Data < AT->Data)//���Ҫ��������ݵ�ֵС�ڵ�ǰ�ڵ��ֵ���Ͳ��뵽�ýڵ��������
	{//�ݹ����������Ȼ������ݲ��뵽���������棬��ʱ�����Ѿ��ܵ��������ײ��ˣ�Ȼ���ٴӵײ�һ��һ������Ϸ����ж�ƽ�����ӣ����ֲ�ƽ�������Ҫ����
		AT->Left = VALTreeInsert(AT->Left, Data);//�������������ݹ������ȥ
		if ((GetHeight(AT->Left) - GetHeight(AT->Right)) == 2)//��Ϊ�����ýڵ���������в������ݣ�����ýڵ����˷�������Ľڵ㣬��ýڵ��ƽ������ֻ����2����������-2
		{
			if (Data < AT->Left->Data)//���Ҫ���������С�ڸýڵ���������ĵ�һ���ڵ�����ݣ����ʾ�����ݲ��뵽�˸ýڵ�������������ȥ�ˣ�����Ҫ���ľ�������
				AT = SingleLeftRotation(AT);//����
			else//������ǲ��뵽�ýڵ���������ĵ�һ���ڵ���ұ�ȥ�ˣ�����Ҫ��������-��˫��
				AT = DoubleLeftRightRotation(AT);//����˫��
		}
	}
	else if (Data > AT->Data)//���Ҫ��������ݵ�ֵ���ڵ�ǰ�ڵ��ֵ,�Ͳ��뵽�ýڵ��������
	{
		AT->Right = VALTreeInsert(AT->Right, Data);
		if ((GetHeight(AT->Left) - GetHeight(AT->Right)) == -2)//��Ϊ�����ýڵ���������в������ݣ��������ڵ����˷�������Ľڵ�,��ýڵ��ƽ������ֻ����-2����������-2
		{
			if (Data > AT->Right->Data)//���Ҫ��������ݴ��ڸýڵ���������ĵ�һ���ڵ�����ݣ����ʾ�����ݲ��뵽�ĸýڵ�����������ұ�ȥ�ˣ�����Ҫ�������ҵ���
				AT = SingleRightRotation(AT);//�ҵ���
			else//��������ݾ��ǲ��뵽�˸ýڵ����������һ���ڵ�����ȥ�ˣ�����Ҫ��������-��˫��
				AT = DoubleRightLeftRotaion(AT);//����˫��
		}
	}
	else//���Ҫ��������ݵ�ֵ���ڵ�ǰ�ڵ��ֵ���������ֵ�Ѵ��ڣ������в������
		printf("��ֵ�Ѵ���\n");
	AT->Height = MAX(GetHeight(AT->Left), GetHeight(AT->Right)) + 1;//����ڵ㣬����������֮��Ҫ�������ĸ߶ȣ������˼�1
	return AT;
}

//AVLTree (AVLTree A,int data){//��д 
//	if(A==NULL){//���û�н�㣬�����½ڵ� 
//		
//	}
//}
void MidBroading(AVLTree AT){
	if (AT != NULL)
	{
		MidBroading(AT->Left);//�����ڵ�
		printf("%d ", AT->Data);//����ڵ��ֵ
		MidBroading(AT->Right);//����ҽڵ�
	}
}
void tree() {

	//��ʼ�������������
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
