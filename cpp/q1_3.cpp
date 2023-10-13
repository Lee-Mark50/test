#include <iostream>
using namespace std;

//总体思路：元素i之后所有比i小的均为降序序列，否则就不成立

int main()
{
    int n;//用来记录比arr[i]小的数据
    cin >> n;
    int arr[n],judge[n],id;
    for(int i = 0;i < n;i++) {cin >> arr[i];}

    for(int i = 0;i < n;i++) {
        id = 0;
        for(int j = i+1;j < n;j++) {
            if(arr[j] < arr[i]) { //如果找到了后面比前面小的数据了
                judge[id++] = arr[j]; //将符合比arr[i]小的数据储存起来
            }
        }
        //开始判断judge[]是否为降序序列
        for(int j = 0;j < id - 1;j++) {
            if(arr[j] < arr[j+1]) { //若judge不是降序序列
                cout << "NO！" << endl;
                return 0;
            }
        }
    }
    cout << "Yes!" << endl;
    return 0;
}
