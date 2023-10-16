#ifndef CIRCLE_H
#define CIRCLE_H

#define keyType int

typedef struct{
    keyType key;
}RcdType;

typedef{
    int size;
    int count;
    int *tag;
    RcdType *rcd;
}HashTable;

#endif

/* typedef struct 和struct来创建结构体的区别，此处单指c++中
struct Student
{
int a;
}stu1;//stu1是一个变量
typedef struct Student2
{
int a;
}stu2;//stu2是一个结构体类型
使用时可以直接访问stu1.a//当成成员函数的调用
但是stu2则必须先 stu2 s2;
*/