#ifndef CIRCLE_H
#define CIRCLE_H

#define keyType int
#define maxsize 10
typedef struct{
    keyType key[maxsize];
}value;

typedef struct{
    value Rcytype;
    int hashsize;
}HashTable;

void InitTable(HashTable *H){};

bool IsKeyIn(HashTable *H,keyType key){};

void TypeFind(HashTable *H,keyType name){};

void Insert(HashTable *H,keyType item){};

void DeleteItem(HashTable *H,keyType key){};

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