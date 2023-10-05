#include<iostream>
#include<math.h>

using namespace std;

//数据结构与算法func伪码实现

/*
int	4 个字节	-2147483648 到 2147483647
float	4 个字节	精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字)
double	8 个字节	双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字)
*/

void fun(int n){
    int i = 1;
    while(i <= n){
        i = i*2;
        cout<<i<<endl;
    }
}
void fun1_2_3_05(int A[],int len){
    int t = 0;

    for(int i; i <= len; i++){
        for(int j = 1; j <= i; j++){
            if(A[j] > A[i]){ //颠倒i与j项
                t = A[j];
                A[j] = A[i];
                A[i] = t;
            }
        }
    }
}
int find_diff_list(int A[],int s){
    int reduce = 0;
    for(int i=0;i<s;i++){
        reduce=reduce ^ A[i];
    }
    return reduce;
    /*
        int arrSize = sizeof(arr) / sizeof(arr[0]);
    // fun1_2_3_05(A,10);
    cout<<"输出非重复值："<<find_diff_list(arr,arrSize)<<endl;
    */
}

void fun1_2_3_03(int n){
    int i = 1;
    while(i<n)
        i *= 2;
}//时间复杂度o（log2 n）

void fun1_2_3_04(int n){
    int i = 0;
    while (i*i*i<=n)
    {
        /* code */
        i++;
    }
}

//时间复杂度o(n)

void fun1_2_3_04(){
    int i,j,m,n;
    for ( i = 1; i < n; i++)
    {
        /* code */
        for ( j = 1; j < 2*i; j++)
        {
            /* code */
            m++;
        }
        
    }   
}

int fun1_2_3_08(int n){
    //fact
    if(n<=1) return 1;
    return n*fun1_2_3_08(n-1);
}

void fun1_2_3_09(){

}


//----------------------------------------------------------------------------------

/*
红黑树通过如下的性质定义实现自平衡：
--->
    节点是红色或黑色。
    根是黑色。
    所有叶子都是黑色（叶子是NIL节点）。
    每个红色节点必须有两个黑色的子节点。（从每个叶子到根的所有路径上不能有两个连续的红色节点。）
    从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点（简称黑高）。
template<class K, class V>
struct RBTreeNode
{
	//三叉链
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	//存储的键值对
	pair<K, V> _kv;

	//结点的颜色
	int _col; //红/黑

	//构造函数
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};
enum Colour{
    Red,
    BLACK
};
*/

//----------------------------------------------------------------------------------

/*
    线性表
    -具有相同数据类型的n个数据元素的有限序列

*/
#define Maxsize 10
typedef struct{
    int data[Maxsize];
    int length;
}SqList;

void InitList(SqList &L){
}
int Length(SqList L){
    return L.length;
}

bool ListInsert(SqList &L, int InsertLocal, int NewElements){
    if( InsertLocal<1 || InsertLocal>L.length+1)
    // 插入位置不正确
        return false;
    if(L.length >= Maxsize)
    // 溢出情况
        return false;
    for(int j=L.length;j>=InsertLocal;j++){
        // 移动插入位置后全部元素
        L.data[j] = L.data[j-1];
    }
    L.data[InsertLocal+1]=NewElements;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int DeleteItem, int &Elements){
    if(DeleteItem<1 || DeleteItem>L.length)
        return false;
    for(int j=DeleteItem;j<L.length;j++){
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}

int ListSearch(SqList &L, int ItemNo){
    //搜寻
    int Item;
    if(ItemNo<1 || ItemNo>L.length || ItemNo>Maxsize)
    return false;
    for(int i;i<L.length;i++){
        if(i==ItemNo)
        Item=L.data[i];
        return Item;
    }
}

/*----------------------------------------------------------------------------------
*///列表--栈
typedef struct{
    int top;
    int bottom;

    bool IsEmpty;

}Stack;

void InitStack(Stack &S){
    
}

bool IsEmpty(Stack &S){
    if(S.IsEmpty){
        return true;
    }
    return false;
}

bool InsertStack(Stack &S, int Item){
    if(S.top=S.bottom || S.IsEmpty==0)
        return false;
    // for(int i;i<S.top;i++){
        
    //     Item->S.top;
    //     S.top++;
    //     return true;
    // }
}

bool DestroyStack(Stack &S){
    if(S.IsEmpty)
        return true;
    else 
        return false;
}

int StackLength(Stack S){
    return S.top;
}

int GetTop(Stack S,int &e){
    e = S.top;//用e返回栈顶元素
    return e;
}

void Push(Stack &S,int e){
    S.top++;
    S.bottom = e;
}

void Pop(Stack &S,int &e){
    if(StackLength(S)<=0){
        abort();
    }
    S.top--;
    //没写完，用自带的stack模板写更简单，只需要#include<stack>即可

}

/*
//链式线性表


*/

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));//创建头结点
    L->next=NULL;//初始为空
    scanf("%d",&x);//输出结点值
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        scanf("%d",&x);
    }
    return L;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x;LNode *s;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *r=L;//表尾指针r
    scanf("%d",&x);
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
LNode *SearchElm(LinkList L, int i){ //为何在这里要设计为*函数
    if(i<1)
        return NULL;
    int j=1;
    LNode *p=L->next;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
//----------------------------------------------------------------------------------
//
typedef struct DNode{
    int data;
    struct DNode *prior,*next;//前后趋结点
}DNode,*DLinkList;

DNode *GetNode(DLinkList L,int x){

}
DNode *InsertElm(DLinkList &L,int x){
    if(L->next==NULL&&L->prior==NULL)
        return NULL;
    DNode *a,*p;
    p=GetNode(L,x);//查找结点
    p->next=a->next;//赋值——先将原链中前结点next赋给添加结点的next，就是联通
    p->next->prior=a;//赋值——再往前练到添加结点
    p->prior=a;//再往前连到前结点
    a->next=p;//赋值——前结点连后结点
}
//----------------------------------------------------------------------------------
//map and tree



//----------------------------------------------------------------------------------



int main(){
    //int A[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr[9] = {7, 8, 8, 6 ,7 ,2 ,9 ,2, 6};
    cout<<"press key and hold on"<<endl;
    cout<<fun1_2_3_08(10)<<endl;
}