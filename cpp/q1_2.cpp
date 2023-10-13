#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int count = 0;

void fun1(stack<int> nums, stack<int> help, vector<int> output,int n);
void fun2(stack<int> nums, stack<int> help, vector<int> output,int n);
void judge(stack<int> nums, stack<int> help, vector<int> output,int n);

int main() {
    stack<int> nums,help; //定义两个栈，一个用来存原始收据，一个用来当辅助栈
    int n;
    cin >> n;
    vector<int> output;
    for(int i = 1;i <= n;i++) { //压入数据
        nums.push(i);
    }
    judge(nums,help,output,n);
    return 0;
}

void fun1(stack<int> nums, stack<int> help, vector<int> output,int n) {
    //选择1
    if(nums.empty()) //如果栈空了，直接返回
        return;
    help.push(nums.top()); //压入辅助栈中
    nums.pop(); //从输出栈中弹出数据
    judge(nums,help,output,n); //继续递归
}

void fun2(stack<int> nums, stack<int> help, vector<int> output,int n) {
    //选择2
    if(help.empty()) //如果栈空了，直接返回
        return;
    output.push_back(help.top()); //压入输出序列中
    help.pop();
    judge(nums,help,output,n); //继续递归
}

void judge(stack<int> nums, stack<int> help, vector<int> output,int n) {
    if(nums.empty() && help.empty()) { //若原栈与辅助栈都空了，那么就输出output之中的数据
        vector<int>::iterator it; //声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素
        for(it=output.begin() ; it!=output.end() ; it++) {
            cout << *it << " ";
        }
        cout << endl;
        output.clear(); //每输出完一次，就重新开始一次
        return;
    }
    /*如果输入栈和辅助栈均不空，接下来有两种选择：
     * 1.输出栈中有一个数据弹出并压入辅助栈中
     * 2.辅助栈中有一个数据弹出并压入输出队列中
     * 故采用递归的方法
     */
    fun1(nums,help,output,n);
    fun2(nums,help,output,n);
}
