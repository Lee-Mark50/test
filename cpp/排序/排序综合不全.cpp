#include<iostream>
using namespace std;

void shell_sort(int A[],int n){
    for(int deep=n/2;deep>=1;deep=deep/2){//�Ե�ǰԪ�غ͵�ǰ���ϲ�����Ԫ��֮����бȽ�
        for(int i=deep+1;i<=n;i++){//�ָ�������� 
            if(A[i]<A[i-deep]){//����Ԫ�����߱Ƚϣ����ǰ�ߴ��ں��� 
            	A[0]=A[i-deep]; 
            	//����λ��
//            	A[i-deep]=A[i];
//				A[i]=A[0]; 
            	//������һ��
//				for(int j=i-deep;j>0&&A[0]<A[j];j-=deep){//j��1��ʼ���� 
//            		A[j+deep]=A[j];	
//				A[j+deep]=A[0];}
				
            }
            
        }
    }
    for(int i=1;i<16;i++){
    	cout<<A[i]<<"	";
	}
}

void ShellSort(int array[], int n)  //ϣ��������
{
	int i, j, step;
	for (step = n / 2; step > 0; step = step / 2)  //�����step�����Ǹ���10��Ԫ��������������
	{
		for (i = 0; i < step; i++)  //i��������ı��
		{
			for (j = i + step; j < n; j = j + step)  //�����±�j�����鲽���±�j+step
			{
				if (array[j] < array[j - step])
				{
					int temp = array[j];  //�������±�j��ֵ�ŵ�temp��
					int k = j - step;
 
					while (k >= 0 && temp < array[k])
					{
						array[k + step] = array[k];  //�Ѵ��ֵ�������
						k = k - step;
					}
					array[k + step] = temp;  //��С��ֵ��ǰ����
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
void zhijiepai_sort(int A[] ,int ow ){     //A[ ]���飬n��Ԫ��
    int i,l;    //�ӵ�һ��Ԫ�ؿ�ʼ
    for(int i=1;i<=n;i++){
        int temp=0;
        if(A[i]<A[i-1]){//�����ǰԪ��С������������Ԫ��
            temp=A[i];//�洢��ֵ
            for(int l=i-1;l>=0&&temp<A[l];l--){//����ǰ�����ź������ҵ���ǰԪ��С��������ĳһ��Ԫ��ʱ
                A[l+1]=A[l];//Ԫ�غ���
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
