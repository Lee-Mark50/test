//图
//·关于图的存储结构和存储类型
//·关于图的遍历算法


#include<iostream>
using namespace std;

#define maxsize 100

typedef char vertype;
typedef int edgetype;

typedef struct{
    int Elemtype[maxsize];
    bool value;
}Graph1;

typedef struct{
    vertype vexs[maxsize]; //顶点表
    edgetype arc[maxsize][maxsize]; //邻接矩阵表示
    int numver,numedge;
}Graph;

void InitGraph(Graph *G){
    int i,j,k,w;
    printf("输入顶点数和边数\n");
    cin >> G->numver >> G->numedge;
    for(i = 0; i < G->numver; i++){
        printf("输入顶点名称:\n");
        cin >> &G->vexs[i];
    }
    for(i = 0; i < G->numver; i++){
        for(j=0; j<G->numedge; j++){
            G->arc[i][j]=0;
        }
    }
    for (k = 0; k < G->numedge; k++){
		printf("输入vi vj 上的下表i,下标j和权w:\n");
		cin>>i>>j>>w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];		//无向图，矩阵对称
	}
}

void DisplayGraph(Graph *G) {
    cout << "Vertices: ";
    for (int i = 0; i < G->numver; i++) {
        cout << G->vexs[i] << " ";
    }
    cout << endl;

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < G->numver; i++) {
        for (int j = 0; j < G->numver; j++) {
            cout << G->arc[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    Graph g1;
    InitGraph(&g1);
    DisplayGraph(&g1);
}