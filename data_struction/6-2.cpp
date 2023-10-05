#include<iostream>
using namespace std;

#define maxsize 100

typedef char vertype;
typedef int edgetype;

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
    
/*
    cin>>(&G->numvertexes);
    cin>>&G->numedges;
no operator ">>" matches these operandsC/C++(349)
6-2.cpp(32, 8): operand types are: std::istream >> int *
6-2.cpp(32, 8): function "std::basic_istream<_CharT, _Traits>::operator>>(std::basic_istream<_CharT, _Traits>::__streambuf_type *__sb) [with _CharT=char, _Traits=std::char_traits<char>]" does not match because argument #1 does not match parameter
6-2.cpp(32, 8): function "std::basic_istream<_CharT, _Traits>::operator>>(void *&__p) [with _CharT=char, _Traits=std::char_traits<char>]" does not match because argument #1 does not match parameter
*/

    for(i=0;i<G->numedges;i++){
        for(j=0;j<G->numvertexes;j++){
            G->adjList[j];
        }
    }
}

int FirstNeighbor(GraphAdjList G,int v){
    
    if()
        return v;
    else
        return -1;
}

int NextNeighbor(GraphAdjList G,int v){
    return -1;
}


//---课后第二题-----------------------------------------------------------------------------------

bool visited[maxsize];

bool Istree(GraphAdjList G){
    for(int i=0;i<G.numvertexes;i++){
        visited[i]=false;
    }
    int Vnum=0,Enum=0;
    DFS(G,1,Vnum,Enum,visited);

    if(Vnum==G.numvertexes&&G.numedges==2*(Enum-1)){
        return 1;
    }
    else 
        return 0;
}

void DFS(GraphAdjList &G,int v,int &Vnum,int &Enum,bool visited[]){
    visited[v] = true;
    Vnum++;
    int w = FirstNeighbor(G,v);
    while(w!=-1){
        Enum++;
        if(!visited[w]){
        w = NextNeighbor(G,v);
        }
    }
}