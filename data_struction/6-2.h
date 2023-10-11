#include<iostream>
using namespace std;

#define maxsize 100

typedef char vertype;
typedef int edgetype;

bool visited[maxsize];

//邻接表表示

typedef struct EdgeNode{//边表结点
    int adjvex;//下标
    edgetype weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{//顶点表结点
    vertype data;
    EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[maxsize];

typedef struct{
    AdjList adjList;
    int numvertexes,numedges;
}GraphAdjList;


void InitGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;//边表结点，初始开始
    // printf("输入初始顶点数和边数\n");
    cout<<"测试"<<endl;
    G->numedges=0;
    G->numvertexes=0;

    for(int i;i<maxsize;i++){
        G->adjList[i].firstedge=NULL;
    }
    
/*
    cin>>(&G->numvertexes);
    cin>>&G->numedges;
no operator ">>" matches these operandsC/C++(349)
6-2.cpp(32, 8): operand types are: std::istream >> int *
6-2.cpp(32, 8): function "std::basic_istream<_CharT, _Traits>::operator>>(std::basic_istream<_CharT, _Traits>::__streambuf_type *__sb) [with _CharT=char, _Traits=std::char_traits<char>]" does not match because argument #1 does not match parameter
6-2.cpp(32, 8): function "std::basic_istream<_CharT, _Traits>::operator>>(void *&__p) [with _CharT=char, _Traits=std::char_traits<char>]" does not match because argument #1 does not match parameter
*/

}
//查找前结点，找到返回结点下标，未找到返回-1
int FirstNeighbor(GraphAdjList *G,int v){
    
    if(v >= 0 && v < G->numvertexes){
        if(G->adjList[v].firstedge!=NULL)
        return G->adjList[v].firstedge->adjvex;//如果是对于
    }
    else
        return -1;
}


//查找v有无下结点，找到返回结点下标，未找到返回-1
int NextNeighbor(GraphAdjList *G,int v){
    if(v >= 0 && v < G->numvertexes){
        //node1 的声明应该使用箭头 -> 而不是点 . 来访问结构体成员。
        //应该写成 EdgeNode *node1 = G->adjList[v].firstedge;，
        //因为 firstedge 是一个指针
        EdgeNode *node1 = G->adjList[v].firstedge;
        while(node1 != NULL){
            int neighbor = node1->adjvex;
            if(visited[neighbor] == 0){
                return neighbor;
            }
            node1 = node1->next;
        }
        //遍历完毕都没有下一个未访问结点邻居，返回-1
    }
    else
        return -1;
}

int ValueFromA_B(GraphAdjList *G,int u,int v){
    EdgeNode *edge = G->adjList[u].firstedge;
    while(edge != NULL){
        if(edge->adjvex = v){
            return edge->weight;
        }
    }
    return -1;
}

//---课后第二题-----------------------------------------------------------------------------------


void DFS(GraphAdjList *G,int v,int &Vnum,int &Enum){
    visited[v] = true;
    Vnum++;
    int w = FirstNeighbor(G,v);
    while(w!=-1){
        Enum++;
        if(!visited[w]){
            DFS(G,w,Vnum,Enum);
        }
        w = NextNeighbor(G,v);
    }
}

bool Istree(GraphAdjList *G){
    for(int i=0;i<G->numvertexes;i++){
        visited[i]=false;
    }
    int Vnum=0,Enum=0;
    DFS(G,1,Vnum,Enum);

    if(Vnum==G->numvertexes&&G->numedges==2*(Enum-1)){
        return 1;
    }
    else 
        return 0;
}