#include<iostream>
using namespace std;

struct tree_Node{//���������洢������ڵ� 
	public:
		tree_Node lchild;
		tree_Node rchild;
		int data;
		void tree_Node(int data){
			this->data=data;
		}
};
//����һ�ö�����
 
public static TreeNode createBinaryTree(LinkedList<Integer> list){
        tree_Node node = null;
        if(list == null || list.isEmpty()){
            return null;
        }
        Integer data = list.removeFirst();
        if(data!=null){
            node = new tree_Node(data);//�������������洢����ջ�� 
            node.leftChild = createBinaryTree(list);//���� 
            node.rightChild = createBinaryTree(list);//�Һ��� 
        }
        return node;
    }
//��ʼ����������

void ride_tree(){
	if(tree_Node.lchild==NULL||tree_Node.rchild==NULL){
		return NULL;
	}
	if(tree_Node.rchild!=NULL&&tree_Node.lchild!=NULL){
		cout<<tree_Node.data;
		ride_tree();
	}
	
} 
//��Ҳ��֪��Ҫ��ɶ�� 
