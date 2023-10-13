#include <iostream>
#include<stack>//对栈头文件
using namespace std;
int menu() {
    cout << "---------------------------------- "<< endl;
    cout << "进入加法计算" << endl;
    cout << "进入乘法计算" << endl;
    cout << "3,进入混合运算" << endl;
}
bool 优先级判断函数(char a,char b) {//通过计算a，b的参数所对应的符号的优先级
	//若a的优先级高于b，则 return 1；
	bool TRUE = 1;
	bool False = 0;
	if (a == '+' && b == '+')return 0;
	if (a == '+' && b == '-')return 0;
	if (a == '+' && b == '*')return 1;
	if (a == '+' && b == '/')return 1;
	if (a == '+' && b == '(')return 1;

	if (a == '-' && b == '+')return 0;
	if (a == '-' && b == '-')return 0;
	if (a == '-' && b == '*')return 1;
	if (a == '-' && b == '/')return 1;
	if (a == '-' && b == '(')return 1;

	if (a == '*' && b == '+')return 1;
	if (a == '*' && b == '-')return 1;
	if (a == '*' && b == '*')return 0;
	if (a == '*' && b == '/')return 0;
	if (a == '*' && b == '(')return 1;

	if (a == '/' && b == '+')return 1;
	if (a == '/' && b == '-')return 1;
	if (a == '/' && b == '*')return 0;
	if (a == '/' && b == '/')return 0;
	if (a == '/' && b == '(')return 1;
	//结束
}
//首先了解到，平时输入的计算式为后缀计算式，要使用中缀计算式来改写，并入栈
string first_in_stack(string s)
{
	string res;
	stack<char> st;
	int size = s.size();//计算输入的字符串的size
	for (int i = 0; i < size; i++)//逐一入栈过程
	{
		if (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '*' && s[i] != '-')
			res += s[i];//数字直接放入算术表达式
		if (s[i] == '(')
			st.push(s[i]);//'('左括号优先级最高 直接入栈
		if (s[i] == '+' || s[i] == '*' || s[i] == '-')//或'*' '+' '-'
		{
			if (st.empty())
				st.push(s[i]);//栈空 算术符号入栈
			else//否则根据算术符号优先级出栈
				while (1)
				{
					char temp = st.top();//栈顶算术符号
					if (优先级判断函数(s[i], temp))//栈顶算术符号优先级高于当前算术符号
					{
						st.push(s[i]);//入栈
						break;//出循环
					}
					else
					{
						res += temp;//否则栈顶算术符号放入算术表达式
						st.pop();//直到当前算术符号优先级小于栈顶算术符号
						if (st.empty())//如果栈空 那么当前算术符号入栈
						{
							st.push(s[i]);
							break;//出循环
						}
					}
				}

		}
		if (s[i] == ')')//如果是右括号 
		{
			while (st.top() != '(')//算术符号出栈 直到栈顶为左括号
			{
				res += st.top();
				st.pop();
			}
			st.pop();//'('出栈 且不放入算术表达式
		}
	}
	while (!st.empty())//栈中剩余算术符号放入算术表达式
	{
		res += st.top();
		st.pop();
	}
	return res;//转换后的算术表达式
}

int calculator_03() {

}
int main()
{
    menu();
}
