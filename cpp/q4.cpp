#include<iostream>
using namespace std;

int main() {
    Stack op,num;
    cout << "请输入简单的中缀表达式(以#开始#结束):" << endl;
    char ch;
    getchar(); 
    cin >> ch; 
    while(ch != '#') {
        if(ch == '+' || ch == '-') {
            int temp;
            op.get_top(temp); //获取栈顶元素
            if(!op.empty() && char(temp) != '(') { 
                int a,b;
                num.get_top(b);
                num.pop();
                num.get_top(a);
                num.pop();
                int c = (ch == '+') ? a+b : a-b;
                num.push(c);
            }else { //否则就让运算符进栈
                op.push(int(ch));
            }
            cin >> ch;
        }else if(ch == '*' || ch == '/') {
            int temp;
            op.get_top(temp); //获取栈顶元素
            if(!op.empty() && char(temp) != '*' && char(temp) != '/') { 

                int a,b;
                num.get_top(b);
                num.pop();
                num.get_top(a);
                num.pop();
                int c = (ch == '*') ? a*b : a/b;
                num.push(c);
            }else { 
                op.push(int(ch));
            }
            cin >> ch;
        } else if(ch == '(') { 
            op.push(int(ch));
            cin >> ch;
        } else if(ch == ')') { 
            int temp;
            op.get_top(temp);
            while(char(temp) != '(') {

            }
        } else { //输入的为数字，则直接将数字进栈
            num.push(int(ch - '0'));
            cin >> ch;
            continue;
        }
    }
    return 0;
}
