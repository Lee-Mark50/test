//关于dfs和bfs伪码写一些
//例程仅供参考
#include<iostream>
#include"3-2.h"
#include"6-2.h"

using namespace std;
#define maxsize 100

bool visited[maxsize];

typedef struct{
    int adjvex;
    int weight;
    struct edgeNode *next;
}edgeNode;

typedef struct{
    char Edgedata;
    struct edgeNode *first;
}VertexNode,AdjList[maxsize];

typedef struct{
    int Vertexnum,Edgenum;
    AdjList AdjList;
}GraphAdjList;

void visit(int v){
    printf("已访问%d结点",v);
}

void BFSTrverse(GraphAdjList *G,SqQueue &Q){
    for (int i = 0; i < G->Vertexnum; i++)
    {
        if(!visited[i]){
            BFS(G,i,Q);
        }
    }
}

void BFS(GraphAdjList *G, int v, SqQueue &Q){
    visit(v);
    visited[v]=1;//初始访问v开始
    //初始化一个辅助队列
    InitQueue(Q);
    EnQueue(Q,v);

    while(!IsEmpty(Q)){
        DeQueue(Q,v);
        for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v)){
            if(!visited[w]){
                visit(w);
                visited[w]=true;
                EnQueue(Q,w);
            }
        }
    }
}




void DFS(GraphAdjList *G,int v){
    visit(v);
    visited[v] = true;
    
    int w = FirstNeighbor(G,v);
    
    while(w!=-1){
        if(!visited[w]){
        w = NextNeighbor(G,v);
        }
    }
}