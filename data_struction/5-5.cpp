#include<iostream>
#include<math.h>
#include<windows.h>

#define false 0
#define true 1
#define MAX_SIZE 12

typedef int bool;

typedef struct {
    int ElemNum;
    int SqBiTNode[MAX_SIZE];
}SqBiTree;

bool judgeBST(SqBiTree bt){
    int k,m,*pmin,*pmax;
    SqBiTree T;
    pmin= (int*)malloc(sizeof(bt.data));
    pmax= (int*)malloc(sizeof(bt.data));

    for(k=bt.ElemNum-1;k>0;k--){
        if(bt.SqBiTNode[k]!=-1){
            m=(k-1)/2;
            if(k%2==1&&bt.SqBiTNode[k]>pmax[k])
                pmin[m]=pmin[k];
            else if(k%2==0&&bt.SqBiTNode[k]<pmin[k]){
                pmax[m]=pmax[k];
            }
            else return false;
        }
    }

}