#ifndef CIRCLE_H
#define  CIRCLE_H

int len(int a[]){
    int num=0;
    for(int i=0;;i++){
        if(a[i]!=-1)
        num++;
    }
    return num;
}

bool IsTrue(int a, int b){
    while(1){
        if(a==b){
        return 0;
        }
        else
        return -1;
    }
}

int QuickSort(int a[],int low,int high){
    if(low < high){
        int pilot=a[low];

        int midnum = diaoyon1(a,low,high);

        QuickSort(a,low,midnum-1);
        QuickSort(a,midnum,high);
        // while(low<high){
        //     while(low<high && pilot<a[high]) --high;
        //     a[low]=a[high];

        //     while(low<high && pilot>a[low]) ++low;
        //     a[high]=a[low];
        // }
        // a[low]=pilot;
    }
    return QuickSort(a,low,low-1);   
}

int diaoyon1(int a[],int low, int high){
    int pilot = a[low];
    while (low<high)
    {
        while (low < high && a[low] < pilot)
        {
            a[low] = a[high];
        }
        while (low < high && a[high] > pilot)
        {
            a[high] = a[low];
        }
    }
    return low;
}

#endif