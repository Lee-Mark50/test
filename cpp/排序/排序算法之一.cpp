#include<iostream>
using  namespace std;
template <class T>
void sier_sort(){
	
}
void mopao_sort(){
	
}
void zhijiepai_sort(char a[] ){
	int i, j;                                    //循环变量
	for (i = 1; i < 16; i++) {
		j = i;
//待排序元素赋值给临时变量
		while (j > 0 && a[i]< a[j - 1]) {   //当未达到数组的第一个元素或者待插入元素小于当前元素
			a[j] = a[j - 1];             //就将该元素后移
			j--; 
			cout<<a[j];                                //下标减一，继续比较
		}
		a[j] = a[i]; 
            //插入位置已经找到，立即插入
	}
}
void kuaisupai_sort(int a[]){
	int midnum=a[2];
	for(int i=0;i<(sizeof(a[5])/2)-1;i++){
		for(int l=5;l>i;l--){
			if(a[i]>a[l]){//当中间数的后者小于前者，交换位置 
				int temp=a[i];
				a[i]=a[l];
				a[l]=temp;
			}
			//否则不变 
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
