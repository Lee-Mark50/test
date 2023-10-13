//函数重载
#include<iostream>
using namespace std;
//构造函数来了解函数重载概念
//1,如果两个函数参数列表中参数个数，类型，顺序不同。即参数列表不同，那就认为是函数重载。 
void print(int);
void print(const char*);

void print(const char*);
void print(const char*;const char*);

void print(const char*;int i);
void print(int i;const char*);
//如果两个函数参数列表和返回值类型都相同，那就认为是重复申明，即使参数名一样 

//typedef为现有的数据类型提供了一个替换名，它并没有创建一个新类型。 


//4-1-2全局函数和成员函数的重载
//例子
class String{
	public:
		String();
		String(char*src);
		int length;
		char* getString()const;
		void print();
		void print(bool isLen);
	private:
		int curLen;
		int maxLen;
		char *ch; 
} 
//函数实现
int String::length(){
	return curLen;
} 
char *String::getString()const{
	return ch; 
}
void String::print(){
	cout<<ch<<endl;
}
void String::print(bool isLen){
	cout<<ch;
	if(isLen){
		cout<<":"<<"符串长度"<<curLen;
	}
}
//打印字符串，全局函数重载 
void print(String s){
	cout<<s.getString()<<endl;
}
//打印字符串和长度，全局函数重载 
void print(String s,bool isLen){
	cout<<s.getString();
	if(isLen){
		cout<<":"<<"符串长度"<<s.length();
	}
		cout<<endl;
}
//4-2一元符号重载
//class Integer{
//	int i;
//	public:
//		Integer(int ii):i(ii){
//		}; 
//};
//对操作数i2，i3进行   +  符号重载 
class Integer{
	int i;
	public:
		const Integer(int ii):i(ii)
		operator+(const Integer&rv)const{
			i+=rv.i;
			return *this;
		}
}; 
