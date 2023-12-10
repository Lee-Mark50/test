#include<iostream>
#include"7-1.h"
#include"tool.h"

using namespace std;

int QuickSort(int a[numA],int start, int end)
{
  if(start >= end || end+1 <= 0) return;

  int mid = a[end];
  int left = start, right = end-1;
  while(left < right){
    while (a[left] < mid && left < right) left++;
    while (a[right] >= mid && left < right) right--;
    swap(a[left],a[right]);
  }
  if(a[left] >= a[end])
    swap(a[left],a[end]);
  else  left++;
  QuickSort(a,start,left-1);
  QuickSort(a,left+1,end);
}

void MapHashSort(){
  
}

/*此处突然想到能否先找个最大的，然后再找最小的，依次排除，这有局限性：num必须比较小，最大最小难找，二次比较难
              但有点在于思路清晰

              这里又有一个思路，先找到平均值，再根据平均值作数据差，差值正的向左依次排序，插值负的从右向左排序，
              一眼烂，至少两倍空间复杂度，时间复杂度两次全循环，一次大循环的O（n2）才能达到两次分配目的

              再更
*/

int SierSort(int a[numA]){
  //
  int i;

  return i;
}

void MaopaoSort(int a[numA]){
  //冒泡的关键就是冒得泡向后依次比较值变大（泡变大），选出，也就是选定最大的一个值，依次类推
  int temp;
  for(int i=numA;i>0;i--){
    for(int j=0;j<i;j++){
      if(a[j] > a[j+1]){
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  };
}
int TuopuSort(int a[numA]){
  //

}

void interMergeSort(int arr[numA],int temp[numA],int left,int right){
    if(left<right){
        int middle = (left+right)/2;
        interMergeSort(arr,temp,left,middle);
        interMergeSort(arr,temp,middle+1,right);
        
    }
}
void GuibingSort(int a[numA]){
  //归并排序的算法是分治法，一种递归实现，一种迭代实现
  int temp[numA];
  interMergeSort(a,temp,0,numA-1);
}
void mergeSortArray(int arr[numA],int temp[numA],int left,int middle,int right){
  int i=left;
  int j=middle+1;
  int k=0;
  while(true){
    temp[k++] = arr[i];
  }
}

int main(){

}