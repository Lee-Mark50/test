#include<iostream>
#include"7-1.h"
#include"tool.h"
#include"6-2.h"

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
int TuopuSort(GraphAdjList *G,int a[numA]){
  //是对图遍历（有向无环图），排序结点，要求没有一个结点指向前面的结点
  //排序后，将入度为零的结点输出，然后图中去掉该结点和它指向的所有连线，并给对应的入度-1
  int inrate[numA],outrate[numA];

  for(int i=0;i<G->numvertexes;i++){
    //遍历所有节点,得到结点对应的出度入度
    if(FirstNeighbor(G,i)==-1) //该节点没有前结点，入度为零
      inrate[i]=0;
    else{
      inrate[i]=1;//遍历得到入读
    }
    outrate[i]=0;
    while(G->adjList[i].firstedge->next->adjvex!=0 && G->adjList[i].firstedge!=NULL)
    {
      G->adjList[i].firstedge = G->adjList[i].firstedge->next;//下一个
      outrate[i]+=1;//遍历得到出度
    }
  }
  for(int i=0;i<G->numvertexes;i++)
  {
    if(inrate[i]==0 && outrate[i]!=0){
      printf("point %d\n in graph out",G->adjList[i].data);
      //对应入度-1
    }
  }
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

int MOFTree(int num[numA]){
  int min,m,max;
  if(num!=NULL){
    //敗者樹利於的某个算法，此处简单化
    for(int i=0;i<numA;i++){
      if(num[i]<min)
      m=m+1;
      else if(num[i]>min && num[i]<max)
        min = num[i];
      else return min;
    }
  }
}

int replace_selection(int num[numA],int nums[numA],int m){
  //似乎很简单的方式，
  //每次是部分取部分最小，选择最小，输出，导入一个新值，再进行排序，直到找不到当前队列里选不出min
  //划分一个段，从开始步骤，重新选择最小的开始继续排序
  num=0;
  for(int i=0;i<m;i++){
    int min,max;
    num[i] = nums[i]; //先导入初始序列值
    if(num[i]<min)
    min = num[i];
    if(num[i]>max)
    max = num[i];
  }

  for(int i=m;i<numA;i++)
  {
    int min,fenduanhao;
    //num[i+1] = nums[i];//开始第一步
    if(num[i]>min && num[i]==MOFTree(num)){//遍历，如果当前num中有大于min的最小值，就选择该值
      printf("%d",num[i]);
      num[i] = nums[fenduanhao+1];
    }
  }
}

int main(){

}