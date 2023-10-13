#include<iostream>
#include<stack>
using namespace std;

//括号的扫描
//基础的多项式计算方式
#define MAXSize 10;
typedef struct {
	int top;
	char data[MAXSize];
}sqstart;
//对接口进行概述
//栈的初始化
void initstark(sqstart &s) {

}
//判断栈是否为空，若为空返回零
bool empty(sqstart) {
	return 0;
}
//入栈
bool push(sqstart& s,char x) {

}
//出栈
bool pop(sqstart&s,char &x) {

}

//函数实现
void blanket(char a[],int length) {
	sqstart s;
	initstark(s);

	if (empty(s)) {//判读是否为空栈
		cout << "该计算式中无对应括号";
		cout << "开始！";
	}
	for (int i = 0; i < length; i++) {
		if (a[i] == '(' || a[i] == '<' || a[i] == '{')//判断若有左括号，入栈
			push(s, a[i]);
	}
	char topelement;
	pop(s, topelement);//比对括号对的完整性
		for (int i; i = 0; i++) {
			if (topelement == '>' && a[i] == '<')
				if (topelement == ')' && a[i] == '(')
					if (topelement == '}' && a[i] == '{')
						return 1;
					else return 0;
	}
}