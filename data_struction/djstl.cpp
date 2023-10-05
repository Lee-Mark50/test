#include<iostream>
using namespace std;



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

