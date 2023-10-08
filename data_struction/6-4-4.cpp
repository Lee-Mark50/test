// bool the alogrithm named topolohicalsort which used to sort the graph with matrix.
// start whith fake code

/*
    AOV 网
    若用DAG图表示一个工程，其顶点表示活动，用有向边表示活动，用有向边<vi,vj>表示活动Vi必须先于vj进行的这样一种关系，这种有向图称为顶点表示活动网络。

    --DAG图
        有向无环图，一个有向图没有环


    逻辑拓扑排序


*/

bool TopologicalSort(Graph G){
    InitStack(S);
    int i;
    for(i=0;i<G.vexnum;i++){
        if(indegree[i]==0)
        Push(S,i);
    }
    int count=0;
    while(!IsEmpty(S)){
        Pop(S);
        print[count++]=i;
        for(p=G.vertices[i].firstarc;p;p=p->nextarc){
            v=p->adjvex;
            Push(S,v);
        }
    }
    if(count<G.vexnum)
        return false;
    else
        return true;
}