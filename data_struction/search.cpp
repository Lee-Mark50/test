//常见查询算法
#include<iostream>
#include"SStable.h"
#include"tool.h"
#define keyType int

using namespace std;


//平平无奇的单for查找，不知道有何特点
int shunxuSearch(SSTable *T,keyType key){
    int len = T->length;
    for(int i=0; i < len; i++){
        if(T->elem[i].key==key){
            return i;
        }
    }
    return 0;
}

int zhebanSearch(SSTable *T,keyType key){
    int head,tail;
    head=1;
    tail = T->length;
    int mid;//中间值
    while(head < tail){
        mid = (head+tail)/2;
        if(T->elem[mid].key=key){
            return mid;
        }
        else if(T->elem[mid].key<key){//这一步看出这个查找是有序的
            head = mid+1;
        }
        else if(T->elem[mid].key>key){
            tail = mid-1;
        }
        else 
            throw "mid异常值bug";
    }
    return 0;
}

int fenkuaiSearch(keyType key){
    //类似于希尔排序算法，将查找表分为若干子块，块内可无序，块间元素有序（第一个块的最大关键字小于第二个块的所有记录关键字）再建立索引表
    //分块查找两步——第一步确定待查记录所在块，可以顺序查找或者折半；第二步块内顺序查找 http://data.biancheng.net/view/123.html
    int a[14] = {88,24,72,61,21,6,32,11,8,31,22,83,78,54};
    int block = 4;

}

int chazhiSearch(SSTable *T,keyType key)
{
    int low = 0;
    int high = 10 - 1;
    int mid = -1;
    int comparisons = 1;
    int index = -1;
    
    while(low <= high){
        printf("比较 %d 次\n" , comparisons );
        printf("low : %d, list[%d] = %d\n", low, low, T->elem[low].key);
        printf("high : %d, list[%d] = %d\n", high, high, T->elem[high].key);

        comparisons++;
        mid = low + (((double)(high - low) / (T->elem[high].key - T->elem[low].key)) * (key - T->elem[low].key));
        printf("mid = %d\n",mid);
        
        // 没有找到
        if(T->elem[mid].key == key){
            index = mid;
            break;
            }
        else{
        if(T->elem[mid].key < key){
            low = mid + 1;
        }
        else{high = mid - 1;}
        }
    }

    printf("比较次数: %d\n", --comparisons);
    return index;
}


int feibonaqieSearch(SSTable *T,keyType key){
    //实现就不写了，
    //斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。他要求开始表中记录的个数为某个斐波那契数小1，及n=F(k)-1；开始将k值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1).
    return Fibonacci1(key);
}

void CreateFind(SSTable **T, int length){
    //这玩意和Init有区别？不也是直接录入信息嘛
    (*T)=(SSTable*)malloc(sizeof(SSTable));
    (*T)->length = length;
    (*T)->elem = (Elemtype*)malloc((length+1)*sizeof(Elemtype));

    for(int i=0;i<length;i++){
        scanf("%d",&((*T)->elem[i].key));
    }
}

int main(){
	SSTable *str;
	int num;
	printf("请输入创建数据元素的个数：\n");
	scanf("%d",&num);
    printf("请依次输入%d个数据:\n",num);
	CreateFind(&str, num);
	getchar();
	printf("请输入要查找的数据：\n");
	int key,location;
	scanf("%d",&key);

    switch(num){
        case 1:
            location = shunxuSearch(str,key);
        case 2:
            location = zhebanSearch(str,key);
        case 3:
            location = chazhiSearch(str,key);
        case 4:
            location = feibonaqieSearch(str,key);
    }


	if (location==0){
		printf("查找失败");
	}
    else{
		printf("要查找的%d的顺序为:%d",key,location);
	}
	return 0;

}