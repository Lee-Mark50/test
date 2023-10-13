#include<iostream>
using namespace std;

void cutfindsort(int A[],int n){
	int temp; 
    for(int deep=n/2;deep>=1;){//对当前元素和当前加上步长的元素之间进行比较
        for(int i=deep+1;i<=n;i++){
            if(A[i]>A[i+deep]){
                temp=A[i];
                A[i]=A[deep+i];
                A[deep+1]=temp;

            }
            else   deep=deep/2;
        }
    }
    for(int i=0;i<=n;i++){
    	cout<<A[i]<<"	";
	}
}
//void fastsort(int A[],int low,int high){
//	int poilt=A[0];
//	if(low<high)
//		//int p=divide(A,low+1,high);
//		//fastsort(A);
//		//fastsort(A); 
//	else if(low>=high)
//		cout<<"结束排序"<<endl;
//}
int divide(int A[],int low,int high){
	int flagnum=A[0];
	int length=high;
	while(low!=high){
		while(A[low]<=flagnum){
			A[low]=A[low-1]; 
			++low;
		}
		while(A[high]>=flagnum){
			A[high]=A[high+1];
			--high;
		}
	}
	for(int i=0;i<length;i++){
		cout<<A[i]<<"	";
	}
}
void turn(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main(){
	int A[]={7,1,2,3,4,5,6};
	divide(A,1,7);
} 
