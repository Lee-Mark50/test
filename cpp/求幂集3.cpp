//求集合｛1, 2, ..., n｝的幂集
#include<iostream>
using namespace std;
int a[3]={1,2,3};
//void deep(int a[3],int n){
//	if(n==1){
//		for(int i=0;i<3;i++){
//		cout<<"单元素集合：{"<<a[i]<<"}"<<endl;
//		}
//		cout<<"1,空集"<<endl;
//	}
//	else {//多元素
//		deep(a[2],n); 
//	}
//}

#include<assert.h>
#include<string.h>
int main()
{
	char arr[]="12312345678";
	int a=strlen(arr);
	int thm=1<<a;//含有N个元素的子集共有N！个
	for(int i=0;i<thm;i++)
	{
		for(int j=0;j<a;j++)
		if(i&1<<j)//每次要对其进行左移操作，然后又i进行&
		{
			printf("%c",arr[j]);	
		}
		printf("\n");
	}
	return 0;
}
