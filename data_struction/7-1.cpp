#include<iostream>
#include"7-1.h"

using namespace std;

int QuickSort(int a[numA]){
    int b[numA];
    for(int i=0;i<numA/2;i++){
        //换两部分，根据两部分设置的底部规则更换
        for(int j=numA/2 + i;j<numA;j++)
            if(a[j])
            /*此处突然想到能否先找个最大的，然后再找最小的，依次排除，这有局限性：num必须比较小，最大最小难找，二次比较难
              但有点在于思路清晰

              这里又有一个思路，先找到平均值，再根据平均值作数据差，差值正的向左依次排序，插值负的从右向左排序，
              一眼烂，至少两倍空间复杂度，时间复杂度两次全循环，一次大循环的O（n2）才能达到两次分配目的

              再更
            */
            
            b[i] = a[i];
    }


    return b;
}