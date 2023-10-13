//����㷨����������A[n]�е�Ԫ�ص���Ϊ���������֣������������Ԫ��Ϊ�������ұ�����Ԫ��Ϊż������Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)��

#include<iostream>
using namespace std;
const int MaxSize = 100;
 
template <class T>
class SeqList {
	public:
		SeqList() {
			length = 0;
		}
		SeqList(T a[],int n);
		~SeqList() {}
		int Length() {
			return length;
		}
		Swap(SeqList &a ,int n); //ת���㷨
		void Print();
	private:
		T data[MaxSize];
		int length;
};
 
 
template<class T>
SeqList<T>::SeqList(T a[],int n) {
	for(int i=0;i<n;i++) {
		data[i]=a[i];
	}
	length=n;
}
 
template<class T>
SeqList<T>::Swap(SeqList &a,int n) {
	T b[n]={0};
	for(int k=0,i=0,j=n-1;i<n;i++) {
		if(a.data[i]%2==1) b[k++]=a.data[i];
		if(a.data[i]%2!=1) b[j--]=a.data[i];
	}
	for(int i=0;i<n;i++) {
		a.data[i]=b[i];
	}
}
 
template<class T>
void SeqList<T>::Print() {
	for(int i=0;i<length;i++) {
		cout<<data[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int A[]={8,4,1,2,7,4,9,6,3};
	SeqList<int> SL(A,sizeof(A)/sizeof(int));
	SL.Print();
	SL.Swap(SL,SL.Length());
	SL.Print();
	
	return 0;
}

