#define keyType int
typedef struct{
    keyType key;
}Elemtype;

typedef struct{
    Elemtype *elem;
    int length;
}SSTable;