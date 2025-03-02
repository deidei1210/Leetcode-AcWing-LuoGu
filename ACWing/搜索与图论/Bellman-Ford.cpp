#include<iostream>
#include<vector>

using namespace std;
const int INF=1e9;
int n,m,k;
//first:顶点
//second:权重
vector<vector<pair<int,int>>> graph;

int bellman_ford(int src) {
    vector<int> dist(n + 1, INF); // 1. 初始化距离，所有点设为INF
    dist[src] = 0; // 2. 起点到自身距离为 0
    for (int i = 0; i < k; i++) { // 3. 进行 k 轮松弛
        vector<int> backup = dist; // 4. 备份 dist，防止本轮修改影响后续计算
        for (int u = 1; u <= n; u++) { // 遍历所有点
            for (auto edge : graph[u]) { // 遍历 u 的所有邻边 (u, v, w)
                int v = edge.first;
                int w = edge.second;
                if (backup[u] < INF) { // 5. 避免无效松弛
                    dist[v] = min(dist[v], backup[u] + w); // 6. 更新最短路径
                }
            }
        }
    }
    return (dist[n] == INF) ? INF : dist[n]; // 7. 返回最短路径，若不可达返回 INF
}


int main(){
    cin>>n>>m>>k;
    graph.resize(n+1);
    int x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
    }
    if(bellman_ford(1)==INF) cout<<"impossible"<<endl;
    else cout<<bellman_ford(1)<<endl;
    return 0;
}