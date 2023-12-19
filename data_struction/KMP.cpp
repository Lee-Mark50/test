//KMP algorithm
/*
what does it mean or where can use it?
i think should learn what its mean.
    structure of KMP algorithm:
    
*/
#include<iostream>
using namespace std;

/*  first,we need to know what is kmp algorithm can instead of.
    in word compare,we use 'for criculate' to work out,but there is a imporant question——O(n^n),
    yeah,the time complex rate is most big in a easy time.
    in order to reduce the stress,we must find a high-effection algorithm.
    so we start using----KMP
    and other?
    real it is a joke ,
    we first try to get a flexible 'for'----BF algorithm(reduce the cricle of 'for')
*/

int BF(char a[], char key[]){
    int t1,t2;
    t1=sizeof(a);
    t2=sizeof(key);
    for(int i=1;i<t1-t2+1;i++){
        for(int j=1;j<t2;j++){
            if(a[i]==key[j])
            return i;
        }
    }
}


int skmp() {
	string a;
	cin >> a;
	int* ne = new int[a.size()];
	ne[0] = 0;
	for (int i = 1, j = 0; i < a.size(); i++) {
		while (j>=0 and a[i]!=a[j])
		{
			j = ne[j - 1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		ne[i] = j;
	}
	for (auto ch : a) {
		cout << ch << ' ';
	}
	cout << endl;
	for (int i = 0; i < a.size();i++) {
		cout << ne[i] << ' ';
	}
	return 0;
}


void KMP_Algorithm(){
    //easily achievement
    int a,b,c;
    string patten_str="aba";
    string text_str="aabaabaaf";
}

#define MAXLEN 255
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;


//2023.12.19 正确理解前后缀子串，next数组，能减少匹配次数的含义，才是理解并运用kmp算法的根本
int next(SString pattern){
    int next[pattern.length];
    for(int j=0,i=1;i<pattern.length;i++){
        //ij都是对于匹配串而言，也就是都是指向next数组的指针
        
        while(pattern.ch[i]!=pattern.ch[j] && j>0)
        {
            j = next[j-1];
            //两个不相等的时候，也就是下一个不一样字符，都是0
            //详细解释这一句代码：当i与j个没匹配到，此时要i继续向前，j要向回，回到的位置应该是模式串中，前面(j-1个数)因为匹配到相等，因为next[j-1]代表数值是0，j-1有无相同序列，若有，返回next[j-1]对应前面相等的数的下一个
        }


        if(pattern.ch[i]=pattern.ch[j])
            j++;
            //相等，就是接下来匹配失败从你开始，赋值出现次数
        next[j]=j;
        if(j=pattern.length) return i-j;
    }

}

void SSting(SString S,SString T){
    /*

    //串的定义和实现
    //串的存储结构
    #define MAXLEN 255
    typedef struct 
    {
        char ch{MAXLEN};
        int length;
    }SString;

    typedef struct{
        char *ch;
        int length;
    }HString;

    */
    //初始化
    

    //break-operation
    B_Index(S,T);

    //model-compare-operation

}
int B_Index(SString S,SString T){
    int i=1,j=1;
    while(i<S.length&& j<T.length){
        if(S.ch[i]=T.ch[j]){
            //匹配到对应元素
            ++i;
            ++j;
        }
        else{
            i=i-j+2;
            //此处解释:
            //对于两个串，模式（匹配）串用来查找主串中相同部分；
            //如从第一个开始不相同，则j指针归零，即重新从模式串第一个元素匹配
            //  但对于主串，接下来从下一个也就是第二个开始匹配，i与j相同，于是开始于2处；
            //若对于第二次匹配时，主串匹配元素S.ch[i]是相对的，
            //  因为匹配失败的情况，所以相对位置下i永远小于j；
            //  此时及之后，i-j都是匹配次数，那从第二个开始就是二，i-j+2=2大概
            j=1;
        }
    }
    if(j>T.length) return i-T.length; 
    else return 0;
}

int KMP(SString S,SString T){
    int i=1,j=1;
    int key[T.length];
    //先计算出对于子串的部分匹配值

    while(i<S.length && j<T.length){
    //
        if(S.ch[i]==T.ch[j]){
           ++i;
           ++j;
        }
        else{
            //此处关键在于i需要回到那个位置
            //i需要回到第一次匹配后，若已有前缀部分匹配，即到匹配的下一位
            i=key[i]+1;

            j=1;
        }
    }
    if(j>T.length) return i-T.length;
    else return 0;
}

int main(){
    // char str1[9]="aabbccdd";
    // char key[3]="bc";
    // string str2="123456789";
    // cout<<str1<<endl;
    // cout<<key<<endl;
    // //char sizeof return space
    // cout<<sizeof(str1)<<endl;
    // cout<<sizeof(key)<<endl;
    // //string return byte of it
    // cout<<str2.length()<<endl;
    // cout<<BF(str1,key)<<endl;
    skmp();
}