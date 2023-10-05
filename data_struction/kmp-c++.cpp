//kmp-c++
#pragma comment(lib,"winmm.lib")

#include <windows.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// 构建模式串的 next 数组
void buildNext(const string& pattern, vector<int>& next) {
    int m = pattern.size();
    next[0] = -1;
    int j = -1;
    
    for (int i = 1; i < m; ++i) {
        while (j >= 0 && pattern[i] != pattern[j + 1])
            j = next[j];
        if (pattern[i] == pattern[j + 1])
            ++j;
        next[i] = j;
    }
}

// KMP 算法进行字符串匹配
int KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next(m);
    buildNext(pattern, next);
    
    int j = -1;
    for (int i = 0; i < n; ++i) {
        while (j >= 0 && text[i] != pattern[j + 1])
            j = next[j];
        if (text[i] == pattern[j + 1])
            ++j;
        if (j == m - 1) {
            return i - j; // 匹配成功，返回起始位置
        }
    }
    return -1; // 匹配失败
}

//----------------------------------------------------------------------------------------------------------------
typedef struct 
{
    int length;
    char ch[10];

}SString;

void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

int Index_kmp(SString S,SString T,int next[]){
    int i=1,j=1;
    while(i<S.length&&j<T.length){
        if(j==1 || S.ch[i]==T.ch[j]){
            ++i;
            ++j;
            //匹配
        }
        else{
            j=next[j];
        }
    }
    if(j>T.length) return i-T.length;
    else return 0;
}








int main() {
    string text = "ABABABABCABABABABCA";
    string pattern = "ABABABC";
    
    // DWORD t1,t2;
    // t1=timeGetTime();
    clock_t start, finish;
    int sum=0;
    double tim; 
    start = clock();

    int result = KMP(text, pattern);
    Sleep(1000);

    finish = clock();
    tim = (double)(finish - start);
    printf( "该循环运行时间为%f ms\n", tim-1000);

    if (result != -1) {
        cout << "Pattern found at index: " << result <<endl;
    } else {
        cout << "Pattern not found." << endl;
    }
    
    return 0;
}