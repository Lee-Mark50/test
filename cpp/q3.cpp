#include <iostream>
using namespace std;

void display(int ch[],int n,int arr[]) {
    cout << "{ ";
    for(int i = 0;i < n;i++) {
        if(ch[i] == 1) {
            cout << arr[i] << ' ';
        }
    }
    cout << '}' << endl;
}

void dfs(int ch[], int n, int i, int arr[]) {
    if(i >= n) {
        display(ch,n,arr);
    }else {
        ch[i] = 0;
        dfs(ch,n,i+1,arr);
        ch[i] = 1;
        dfs(ch,n,i+1,arr);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n],ch[n];
    for(int i = 0;i < n;i++) {
        arr[i] = i+1;
        ch[i] = 0;
    }
    dfs(ch,n,0,arr);
    return 0;
}
