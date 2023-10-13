#include<iostream>
using namespace std;
void sort(int A[]){
	int length=0;
	for(int i=0;;i++){
		if(A[i]!=-1){
		length++;
		}
		else break;
	}
	for(int i=0;i<length;i++){
		for(int l=length-1;l>=i;l--){
			if(A[l]<A[l-1]){
				int temp=A[l-1];
				A[l-1]=A[l];
				A[l]=temp;
			}
		}cout<<A[i]<<"	";
	}
}
int main(){
	int A[]={1,23,66,4,2,213,2,22,9,-1};
	sort(A);
}
