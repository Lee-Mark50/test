#include<iostream>
using namespace std;
typedef struct{
	int a[];
	struct *t;
}List;

int main(){
	List list1,list2;
	for(int i=0;i<10;i++){
		list1->a[i]=i;
	} 
	for(int i=1;i<4;i++){
		list2->a[i]=i;
	}
	for(int i=0;i<10;i++){
		if(list1->a<list2.a){
			
		}
	}
	
}
