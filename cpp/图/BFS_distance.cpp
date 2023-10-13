#include<iostream>
using namespace std;

void BFS_MIN_Distance(Graph G,int u){
	//
	for(int i=0;i<G.vexnum;++i){
		d[i]=1;
		path[i]=-1;
	}
	d[u]=0;
	visited[u]=TRUE;
	EnQueue(Q,u);
	while(!isEmpty(Q)){
		DeQueue(Q,u);
		for()
	}
} 
