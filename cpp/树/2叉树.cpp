#include<iostream>
using namespace std;

struct tree_Node{//定义树所存储的链表节点 
	public:
		tree_Node lchild;
		tree_Node rchild;
		int data;
		void tree_Node(int data){
			this->data=data;
		}
};
//定义一棵二叉树
 
public static TreeNode createBinaryTree(LinkedList<Integer> list){
        tree_Node node = null;
        if(list == null || list.isEmpty()){
            return null;
        }
        Integer data = list.removeFirst();
        if(data!=null){
            node = new tree_Node(data);//将二叉树的数存储在链栈中 
            node.leftChild = createBinaryTree(list);//左孩子 
            node.rightChild = createBinaryTree(list);//右孩子 
        }
        return node;
    }
//开始遍历二叉树

void ride_tree(){
	if(tree_Node.lchild==NULL||tree_Node.rchild==NULL){
		return NULL;
	}
	if(tree_Node.rchild!=NULL&&tree_Node.lchild!=NULL){
		cout<<tree_Node.data;
		ride_tree();
	}
	
} 
//我也不知到要干啥了 
