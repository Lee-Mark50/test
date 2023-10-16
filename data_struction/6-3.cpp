//关于dfs和bfs伪码写一些
//例程仅供参考
#include<iostream>
#include"3-2.h"
#include"6-2.h"

using namespace std;
#define maxsize 100

bool visited[maxsize];

/* typedef struct{
//     int adjvex;
//     int weight;
//     struct edgeNode *next;
// }edgeNode;

// typedef struct{
//     char Edgedata;
//     struct edgeNode *first;
// }VertexNode,AdjList[maxsize];

// typedef struct{
//     int Vertexnum,Edgenum;
//     AdjList AdjList;
// }GraphAdjList;
*/

void visit(int v){
    printf("已访问%d结点",v);
}

void BFSTrverse(GraphAdjList *G,SqQueue &Q){
    for (int i = 0; i < G->numvertexes; i++)
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

//Question1:有一个图，0表示通路，1表示非通路墙壁，寻找一条路径从左上角到右下角
void dfs(int a,int b, GraphAdjList *G){
    bool flag;
    if(flag) return;
    // why this use line82 func? two func just one meaning
    // when write the line of dfs core part,you know that visit numvertexes when recurrence ,we must judge it.if not the time and space cost is so anomous.
    // obviously graph is made with metrix so is _visit[a][b];
    visited[a] = true;
    if(a == 5 && b == 5){
        //find the end
        flag = true;
        return;
    }
    while(!flag){
        int next_a = a + 1, next_b = b + 1;
        if(next_a > G->numvertexes || next_b > G->numvertexes){
            continue;
        }
        //核心部分，直接递归来检索没有访问过且没经过的可访问结点，根据情况修改
        if(visited[next_a]==0 && G->adjList[next_a].data == 0){
           dfs(next_a,next_b,G); 
        }
    }
}