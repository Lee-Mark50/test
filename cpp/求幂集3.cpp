//�󼯺ϣ�1, 2, ..., n�����ݼ�
#include<iostream>
using namespace std;
int a[3]={1,2,3};
//void deep(int a[3],int n){
//	if(n==1){
//		for(int i=0;i<3;i++){
//		cout<<"��Ԫ�ؼ��ϣ�{"<<a[i]<<"}"<<endl;
//		}
//		cout<<"1,�ռ�"<<endl;
//	}
//	else {//��Ԫ��
//		deep(a[2],n); 
//	}
//}

#include<assert.h>
#include<string.h>
int main()
{
	char arr[]="12312345678";
	int a=strlen(arr);
	int thm=1<<a;//����N��Ԫ�ص��Ӽ�����N����
	for(int i=0;i<thm;i++)
	{
		for(int j=0;j<a;j++)
		if(i&1<<j)//ÿ��Ҫ����������Ʋ�����Ȼ����i����&
		{
			printf("%c",arr[j]);	
		}
		printf("\n");
	}
	return 0;
}
