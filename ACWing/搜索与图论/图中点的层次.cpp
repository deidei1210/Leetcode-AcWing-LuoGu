#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//n个点
//m条边
int n,m;
const int INF=1e9;
vector<vector<int>> graph;

int minDistance(){
//求出从1号点到n号点的最短距离
    vector<int> dist(n+1,INF);
    dist[1]=0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto v_next:graph[v]){// 遍历 v 的邻接点
            if(dist[v_next]>dist[v]+1){
                dist[v_next]=dist[v]+1;
                q.push(v_next);
            }
        }
    }
    return dist[n];
}
int main(){
    cin>>n>>m;
    graph.resize(n+1);

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    if(minDistance()==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<minDistance()<<endl;
    }

    return 0;
}


