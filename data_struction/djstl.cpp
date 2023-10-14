/*
def dijkstra(graph,v0):
    vNum = graph.numNode
    paths = {}
    count = 0
    cands = PQueue()
    cands.put((0,v0,v0))  #(pLen, u, vmin)表示经由u到vmin的已知最小路径长度为pLen
  
    while count < vNum and not cands.empty():
        pLen, u, vmin = cands.get()   #取出可见点到源点中路径最短的一条,由优先队列实现
        if vmin in paths.keys():
            continue
        paths[vmin] = (u,pLen)   #v0到vmin的最小路径长度为pLen，其前驱为u，记住前驱是为了通过回溯还原路径
 
        for v,w in graph.getOutEdges(vmin):  #找可见点
           if v not in paths.keys():
               cands.put((pLen + w,vmin,v))   
        count += 1
    return paths
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 5; // 假设图中有5个顶点

int minDistance(vector<int>& dist, vector<bool>& visited) {
    int minDist = INT_MAX;
    int minIndex = -1;
    //初始均置最大值和-1，表示没有最短路径、最小结点为-1
    for (int v = 0; v < V; v++) {//对
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(vector<int>& dist) {
    cout << "顶点\t最短距离" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}
/*
初始化：创建一个距离数组 dist[] 和一个标记数组 visited[]，用于跟踪每个顶点的距离和是否已经被访问。将距离数组初始化为无穷大，将标记数组初始化为 false。将起始顶点的距离设置为0。

找到最小距离的顶点：从未被访问的顶点中选择距离最小的顶点，即在 dist[] 数组中找到最小值对应的顶点。

更新距离：对于选中的最小距离顶点的所有邻居，计算从起始顶点到这些邻居的距离。如果计算出的距离小于 dist[] 数组中的当前值，更新 dist[] 数组中的值。

标记为已访问：将选中的最小距离顶点标记为已访问。

重复：重复步骤2到步骤4，直到所有顶点都被访问。

最短路径树：最后，通过 dist[] 数组构建最短路径树，从起始顶点到每个顶点的最短路径都可以从 dist[] 数组中找到。




步骤 1：初始化距离数组和标记数组

首先，我们需要初始化两个数组：

dist 数组用于存储从起始顶点到其他各顶点的最短距离。
visited 数组用于标记顶点是否已经被访问。
在这一步，我们将所有顶点的距离初始化为无穷大（表示尚未计算最短距离），并将所有顶点标记为未访问。

步骤 2：寻找最小距离的顶点

在每一轮迭代中，我们需要选择一个未访问的顶点，它的距离最小。这是 Dijkstra 算法的贪心部分。我们在 minDistance 函数中实现了这一步骤。

步骤 3：更新距离数组

一旦找到了最小距离的顶点，我们需要更新从起始顶点到其邻居的距离。我们检查所有未访问的邻居，并计算通过当前选中的顶点到达邻居的距离。如果这个新计算的距离小于 dist 数组中的当前值，我们更新 dist 数组。这一步是 Dijkstra 算法的核心。

步骤 4：标记为已访问

在找到最小距离的顶点并更新了距离数组后，我们将该顶点标记为已访问，以确保不会再次考虑它。

步骤 5：重复

我们重复步骤 2 到步骤 4，直到所有顶点都被访问。这确保了我们找到了从起始顶点到图中所有其他顶点的最短路径。
*/
void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    //vector<int>使用了C++中的标准容器 vector，它具有动态大小调整的能力。
    //这意味着你可以在运行时更改数组的大小，而不需要事先知道数组的大小。这在需要动态调整数组大小的情况下非常有用。

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}
/*
void djstl(int Graph[V][V],int h){
    int dist[V]={INT_MAX};
    bool visited[V]={false,false,false,false,false};
    dist[h] = 0;
    for(int i=0; i<V-1; i++){
        int u = minDistance(dist,visited);
        visited[u]=true;

        for(int v = 0; v < V ; v++){
            if(!visited[v] && Graph[u][v] && dist[u] != INT_MAX && dist[u]+Graph[u][v]<dist[v])
            //这里判断条件比较复杂，1，判断v，也就是终点v未遍历；2，判断有u-v路径；3，判断初始点到路径u长度不是最大值；4，初始点到u的距离+u-v距离小于dist存储的初始到v的距离
            //满足如上条件后进行更新，即
            dist[v] = dist[u] + Graph[u][v];
        }
    }
    printSolution(dist);
}
*/


int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    dijkstra(graph, 2);

    return 0;
}