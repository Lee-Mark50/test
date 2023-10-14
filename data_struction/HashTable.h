#ifndef CIRCLE_H
#define CIRCLE_H

#define keyType int

typedef struct{
    keyType key;
}RcdType;

struct{
    int size;
    int count;
    int *tag;
    RcdType *rcd;
}HashTable;

#endif