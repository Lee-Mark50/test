#include"6-2.h"
#include<iostream>
#include<vector>
using namespace std;

//6-4-1  最小生成树
void prim(){
    
}

void Kruskal(){

}

//6-4-2  最短路径  均为伪码

void Djstl(GraphAdjList *graph, int start){
    //算法思路：设置两个存储结构分别存储对应结点之间的最小值dist[V]和有无访问visited[V]；然后设置参数初始点v，图G和对两者初始化；
    //         之后for循环遍历图，对visited[v]赋值为1访问后，得到初始v到附近结点的最小路径，存储入dist；
    //         进行下一个结点u的周围访问，visit[u]=1,for循环下遍历，在满足!visited[v]&&graph[u][v]&&dist[u]!=INIT_MAX&&dist[v]+graph[u][v]<dist[u]
    //         情况下，更新dist[v]=graph[v]+dist[u][v];
    //         print即可
    vector<int> dist(graph->numvertexes,INT_MAX);
    vector<bool> visited(graph->numvertexes,false);
    visited[start]=1;
    for(int u = 0;u<graph->numvertexes-1;u++){
        visited[u]=1;
        //distancemin(visited,dist);//得到最短路径
        for(int v = 0; v < graph->numvertexes;v++){
            // if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
            //     dist[v] = graph[u][v]+dist[u];
            //  邻接矩阵实现
            // }
            if(!visited[v] && ValueFromA_B(graph,u,v)!=-1 && dist[u]!=INT_MAX && ValueFromA_B(graph,u,v)+dist[u]<dist[v]){
                dist[v] = dist[u]+ValueFromA_B(graph,u,v);
            }
        }
    }
    
    //傻逼黄毛终于走了真实弱智极了妈的没病是吧一队情侣来教室恶心大伙
}

void Floyd(GraphAdjList *graph, vector<vector<int>> dist){
    //算法思路：初始化距离矩阵：创建一个二维数组 dist，其中 dist[i][j] 表示节点 i 到节点 j 的最短路径的长度。初始时，将 dist[i][j] 初始化为无穷大（或一个足够大的数），但将 dist[i][i] 初始化为0，因为节点到自身的距离为0。
    //         三重循环：对于每一对节点 (i, j)，以及对于每一个可能的中间节点 k，执行以下步骤：
    //         如果 dist[i][k] + dist[k][j] 的值小于 dist[i][j]，则更新 dist[i][j] 为 dist[i][k] + dist[k][j]。这意味着通过节点 k，从节点 i 到节点 j 的路径更短。
    //         重复步骤2直到所有节点对的最短路径都被找到。最终，dist 矩阵将包含每一对节点之间的最短路径长度。
    //（可选）检查负权环：Floyd算法也可以检测负权环。如果在算法的最后一轮迭代中，某些 dist[i][i] 变为负数，则存在负权环。

    int num = graph->numvertexes;
    vector<vector<int>> dist(num,vector <int>(num,INT_MAX));

    for(int i = 0; i < num; i++){
        dist[i][i] = 0;
    }
    //三重循环
}


//补充A*
void Astar(GraphAdjList *G){
    //算法思路：
    //  宏观上，假设一个锚点为邻接矩阵G[maxsize][maxsize]，则就是对于每一个锚点，设立起始点A[i][j]和终点B[x][y]，初始化两个数据队列list[]；
    //  first 、 end；
    //  将初始点优先级value设置为1（最高优先）,再将A入队列first；开始计算A周围所有邻接锚点[i-1][j+1]、[i+1][j+1]、[i][j-1]、[i][j+1]的对应优先级；
    //  这里有一个优先级函数 f(x)= g(x) + G(x),
    //  1.f(x)该锚点距离B的距离函数  f(x)——value=sqrt(x-i+1,y-j-1)
    //  2.

}                         