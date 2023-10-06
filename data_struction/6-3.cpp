//关于dfs和bfs伪码写一些
//例程仅供参考

typedef struct{

}Node;

typedef struct{
    int 
}

void BFS()




void DFS(GraphAdjList *G,int v,int &Vnum,int &Enum,bool visited[]){
    visited[v] = true;
    Vnum++;
    int w = FirstNeighbor(G,v);
    while(w!=-1){
        Enum++;
        if(!visited[w]){
        w = NextNeighbor(G,v,visited);
        }
    }
}