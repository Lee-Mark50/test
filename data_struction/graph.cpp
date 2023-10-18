#include"HashTable.h"
#include<iostream>
#include<random>
#include<time.h>
//hash
/*
构造要求
*/
bool IsKeyIn(HashTable *H,keyType key){
    for(int i=0;i<H->hashsize;i++){
        if(H->Rcytype.key[i] == key)
            return true;
        else return false;
    }
}

void InitTable(HashTable *H){
    srand(time(NULL)); 
    for(int i=0;i<H->hashsize;i++){
        int a = scanf("%d",rand()%(11));
        H->Rcytype.key[i] = a; 
    }
}

int Hash(HashTable &H,keyType value){
    return value % H.hashsize;
}

void HashSearch(HashTable *H,int SearchData){
    int num = H->hashsize;
    
    // while(H->Rcytype.key[i] != SearchData){

    // }

}

//关键路径算法
//持续时间，活动时间余量