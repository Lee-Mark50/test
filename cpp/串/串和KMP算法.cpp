#include<iostream>
using namespace std;

#define MAXSIZE 200
typedef struct{
	char a[MAXSIZE];
	int size;
	int top,bottom; 
}*circleLine; 
typedef struct{
	char a[MAXSIZE];
	int length;
}SString1;


typedef struct{
	char *a;
	int length;
}SString;
void StrAssign(SString &T,char s){
	
}
void StrCopy(SString &T,SString S){//复制操作，由串S复制得到串T 
	int i=0;
	S.length=T.length;
	T.a = (char*)malloc(T.length*(sizeof(char)));
	S.a = (char*)malloc(S.length*(sizeof(char)));
	for(;i<T.length;i++){
		S.a[l]=T.a[i];
		l++;
	}
}
bool StrEmpty(SString T){
	if(T->length==0)
		return true;
	else 
		return false;
}
int StrLength(SString T){
	return T->length;
}
void ClearString(SString &T){
	T->length=0;
}

void SubString(SString &T,SString S,int pos,int len){//用T返回串S的从第pos个字符起长度为len的字串 
	T.a = (char*)malloc(T.length*(sizeof(char)));
	S.a = (char*)malloc(S.length*(sizeof(char)));
	if(S.length<=pos){
		cout<<"该串的长度不满足要求，请重新输出pos和len或新串"<<endl;
	} 
	else if(S.length<pos+len-1){
		cout<<"错误"<<endl; 
	}
	for(int i=0;i<pos+len-1;i++){
		S.a[i]=T.a [i+pos-1];
	}
}
bool StrCompare(SString T,SString S){
	T.a = (char*)malloc(T.length*(sizeof(char)));
	S.a = (char*)malloc(S.length*(sizeof(char)));
	for(int i=0;i<S.length&&i<T.length;i++){
		if(S.a[i]!=T.a[i]){
			return false;
		}
	}
	return true;
}
int Indexst(SString T,SString S){//主串S中存在与T相同的字串，定位取T与S中相同的子串，并将其返回 
	int m=T->length;
	int n=S->length;
	SString Sub;
	int i=1;
	while(i<n-m+1){
		SubString(Sub,S,i,n);
		if(StrCompare(Sub,T)){
			++i; 
			return i; 
		}
		return 0;
	}
}
int Index(SString S,SString T){//T为子串 ，S为主串 
	int k=1;
	int i=k,j=1;
	S.a = (char*)malloc(S.length*(sizeof(char)));
	T.a = (char*)malloc(T.length*(sizeof(char)));
	while(i<=S.length&&j<=T.length){
		if(S.a[i]==T.a[j]){
			++i;
			++j;
		}
		else {//回到原位
			k++;
			i=k;
			j=1;
		}
	}
	if(j>T.length){
		return k;
	} 
	else return 0;
}
int kMP_Index(SString S,SString T){
	int i=1,j=1;
	S.a = (char*)malloc(S.length*(sizeof(char)));
	T.a = (char*)malloc(T.length*(sizeof(char)));
	int next[T.length+1];
	get_next(T,next); 
	while(j==0||i<S.length&&j<T.length){
		if(S.a[i]==T.a[j]){
			++i;
			++j;
		}
		else j=next[j];//子数组回溯 
	}
	if(j>T.length){
		cout<<"匹配成功"<<endl;
		return i-T.length;
	}
	else cout<<"匹配失败"<<endl; 
		return 0;
}
void get_next(SString T,int next[]){
	next[1]=0;
	next[2]=1;
	int i=1;int j=0; 
	while(i<T.length){
		if(j==0||T.a[i]<T.a[j]){
			++i;
			++j;
			next[i]=j;
		}
		else j=next[j];
	}
}
int main(){
	SString T;
	T.a=(char *)malloc(MAXLEN*sizeof(char)); 
	free(); 
}
