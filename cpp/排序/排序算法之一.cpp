#include<iostream>
using  namespace std;
template <class T>
void sier_sort(){
	
}
void mopao_sort(){
	
}
void zhijiepai_sort(char a[] ){
	int i, j;                                    //ѭ������
	for (i = 1; i < 16; i++) {
		j = i;
//������Ԫ�ظ�ֵ����ʱ����
		while (j > 0 && a[i]< a[j - 1]) {   //��δ�ﵽ����ĵ�һ��Ԫ�ػ��ߴ�����Ԫ��С�ڵ�ǰԪ��
			a[j] = a[j - 1];             //�ͽ���Ԫ�غ���
			j--; 
			cout<<a[j];                                //�±��һ�������Ƚ�
		}
		a[j] = a[i]; 
            //����λ���Ѿ��ҵ�����������
	}
}
void kuaisupai_sort(int a[]){
	int midnum=a[2];
	for(int i=0;i<(sizeof(a[5])/2)-1;i++){
		for(int l=5;l>i;l--){
			if(a[i]>a[l]){//���м����ĺ���С��ǰ�ߣ�����λ�� 
				int temp=a[i];
				a[i]=a[l];
				a[l]=temp;
			}
			//���򲻱� 
			while(a[l]==a[2]||a[i]==a[2]){
				cout<<"ing"<<endl;
				break;
			}
		}
	}
}
int main(){
	char a[16]={78,100,120,25,85,40,90,15,60,35,105,50,30,10,28,12};
	int b[5]={1,4,2,5,3};
	kuaisupai_sort(b[5]); 
}
