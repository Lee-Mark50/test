//��������
#include<iostream>
using namespace std;
//���캯�����˽⺯�����ظ���
//1,����������������б��в������������ͣ�˳��ͬ���������б�ͬ���Ǿ���Ϊ�Ǻ������ء� 
void print(int);
void print(const char*);

void print(const char*);
void print(const char*;const char*);

void print(const char*;int i);
void print(int i;const char*);
//����������������б�ͷ���ֵ���Ͷ���ͬ���Ǿ���Ϊ���ظ���������ʹ������һ�� 

//typedefΪ���е����������ṩ��һ���滻��������û�д���һ�������͡� 


//4-1-2ȫ�ֺ����ͳ�Ա����������
//����
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
//����ʵ��
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
		cout<<":"<<"��������"<<curLen;
	}
}
//��ӡ�ַ�����ȫ�ֺ������� 
void print(String s){
	cout<<s.getString()<<endl;
}
//��ӡ�ַ����ͳ��ȣ�ȫ�ֺ������� 
void print(String s,bool isLen){
	cout<<s.getString();
	if(isLen){
		cout<<":"<<"��������"<<s.length();
	}
		cout<<endl;
}
//4-2һԪ��������
//class Integer{
//	int i;
//	public:
//		Integer(int ii):i(ii){
//		}; 
//};
//�Բ�����i2��i3����   +  �������� 
class Integer{
	int i;
	public:
		const Integer(int ii):i(ii)
		operator+(const Integer&rv)const{
			i+=rv.i;
			return *this;
		}
}; 
