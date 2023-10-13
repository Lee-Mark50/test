#include<iostream>
using namespace std;

void shell_sort(int A[],int n){
    for(int deep=n/2;deep>=1;deep=deep/2){//对当前元素和当前加上步长的元素之间进行比较
        for(int i=deep+1;i<=n;i++){//分割成组类型 
            if(A[i]<A[i-deep]){//组内元素两者比较，如果前者大于后者 
            	A[0]=A[i-deep]; 
            	//调换位置
//            	A[i-deep]=A[i];
//				A[i]=A[0]; 
            	//继续下一组
//				for(int j=i-deep;j>0&&A[0]<A[j];j-=deep){//j从1开始遍历 
//            		A[j+deep]=A[j];	
//				A[j+deep]=A[0];}
				
            }
            
        }
    }
    for(int i=1;i<16;i++){
    	cout<<A[i]<<"	";
	}
}

void ShellSort(int array[], int n)  //希尔排序函数
{
	int i, j, step;
	for (step = n / 2; step > 0; step = step / 2)  //这里的step步长是根据10个元素这种情况定义的
	{
		for (i = 0; i < step; i++)  //i是子数组的编号
		{
			for (j = i + step; j < n; j = j + step)  //数组下标j，数组步长下标j+step
			{
				if (array[j] < array[j - step])
				{
					int temp = array[j];  //把数组下标j的值放到temp中
					int k = j - step;
 
					while (k >= 0 && temp < array[k])
					{
						array[k + step] = array[k];  //把大的值往后插入
						k = k - step;
					}
					array[k + step] = temp;  //把小的值往前插入
				}
			}
		}
	}for(int i=1;i<16;i++){
    	cout<<array[i]<<"	";
	}
}
void mopao_sort(int A[]){
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
void zhijiepai_sort(int A[] ,int ow ){     //A[ ]数组，n个元素
    int i,l;    //从第一个元素开始
    for(int i=1;i<=n;i++){
        int temp=0;
        if(A[i]<A[i-1]){//如果当前元素小于已排序数组元素
            temp=A[i];//存储该值
            for(int l=i-1;l>=0&&temp<A[l];l--){//遍历前面已排好数组且当当前元素小于数组中某一个元素时
                A[l+1]=A[l];//元素后移
                A[l]=temp;
            }
        }
    }
    for(int i=0;i<16;i++){
    	cout<<A[i]<<"	";
	}
}
void kuaisupai_sort(int A[] ,int low,int high){
	int temp=A[low];
	for(low=1;low<=high;low++){
		if(A[low]<temp){
			A[low]=A[0]
			low++;	
		}
	}
	for(int i=1;i<16;i++){
    	cout<<array[i]<<"	";
	}
}
void guibing_sort(){
	
}


int main(){
	int a[16]={78,100,120,25,85,40,90,15,60,35,105,50,30,10,28,12};
	ShellSort(a, 16);
}
