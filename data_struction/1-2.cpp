#include<iostream>
using namespace std;

#define Maxsize 100
typedef struct{
    int data[Maxsize];
    int length;
} Sqlist;

// 注：线性表都是递增有序的！
// 所以地下有很多东西算法就是所以然

int Del_min(Sqlist &L){
    //由顺序表删除具有·最小值·的元素（唯一），并由函数返回被删元素的值；
    //空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
    int min=0;
    int tag=0;
    if(L.length=0){
        return false;
    }
    for(int i=1;i<L.length;i++){
        if(L.data[i-1]<L.data[i]) 
        min=L.data[i-1];
        tag=i-1;
    }
    L.data[tag]=L.data[L.length-1];
    return min;
}

void Change_Sqlist(Sqlist &L){
    //顺序表逆置元素，要求空间复杂度O{1}
    int space;
    for(int i=0;i<L.length;i++){
        space = L.data[i];
        L.data[i]=L.data[L.length-i];
        L.data[L.length-i]=space;
        /*
        if(i=L.data[L.length/2])
        return true;
        */
    }
}

void Del_Element(Sqlist &L,int x){
    int l=0,k;
    for(int i;i<L.length;i++){
        if(L.data[i]!=x)
        //L.listdelete(Sqlist &L,int i,int x)?可否直接调list的函数？
        L.data[k]=L.data[i];
        k++;
    }
    //
    L.length=k;
}

bool Del_lenElement(Sqlist &L,int s,int t){
    //有序线性表删除给定值s-t(s<t)之间的所有元素；
    //若s和t不合理或顺序表为空，则显示出错信息并退出运行
    if(s>t||L.length<0)
        return false;
    int k;
    for(int i=0;t+i<L.length;i++){
        L.data[s]=L.data[t+i];
        k=t+i;
    }
    L.length=k;
    return true;
}

void a06(){

}

bool a07_merge(Sqlist A,Sqlist B,Sqlist &C){
    //将两个表合为一个新表[没真懂]
    if(A.length+B.length>C.length){
        return false;
    }
    int i=0,j=0,k=0;
    while(i<A.length&&j<B.length){
        if(A.data[i]<B.data[j])
            C.data[k++]=A.data[i++];
        else
            C.data[k++]=B.data[j++];
    }
    // 还剩一个没比较完的表
    while(i<A.length){
        C.data[k++]=A.data[i++];
    }
    while(j<B.length){
        C.data[k++]=B.data[j++];
    }
    C.length=k;
    return true;
}

void SearchExchangeInsert(int A[],int x){
    int t,n;
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==x) break;
        else if(A[mid]<x) low=mid+1;
        else high=mid+1;
    }
    if(A[mid]==x && mid!=n-1){
        t=A[mid];A[mid]=A[mid+1];A[mid+1]=t;
    }
    if(low>high){
        for(int i=n-1;i>high;i--){ A[i+1]=A[i];
        A[i+1]=x;
        }
    }

}

int main(){
    Sqlist L;
    int size=5;
    //L.data[]={12,3,};
    L.length=5;
/*
产生一定范围随机数的通用表示公式 
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a; 
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1; 
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。 
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。 
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。

#define random(x) ((rand()% (20 - 10))) + 10
srand((unsigned)time(NULL));
random(10)
    调用

for(int a=0;a<10;a++){
    int aa=(rand()%(100-10+1)+10);
    int b=(rand()%(10-0+1)+0);
    cout<<aa<<'+'<<b<<'='<<'?'<<endl;
    int s;
    cin>>s;
    if(s==aa+b){
        cout<<"yes,you are right!"<<endl;
    }
    else cout<<"wrong,actually answer is"<<'\n'<<aa+b<<endl;
    }
*/
    
}