/*给定一个n个点 m条边的有向图，图中可能存在重边和自环，所有边权均为非负值。请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出−1。

输入格式
第一行包含整数n和m。
接下来m行每行包含三个整数 x,y,z，表示存在一条从点 x到点y的有向边，边长为z。

输出格式
输出一个整数，表示1号点到n号点的最短距离。
如果路径不存在，则输出−1。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // 定义无穷大
int n, m; // n 表示顶点数，m 表示边数

// 图的邻接表表示法：pair<邻接点, 边权>
vector<vector<pair<int, int>>> graph;

// Dijkstra 算法实现
vector<int> dijkstra(int start) {
    //1.首先将dist数组初始化为INF，就是将起点到各个点的距离先初始化为最大值
    vector<int> dist(n + 1, INF); // 记录起点到各个点的最短距离
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //2.初始化
    dist[start] = 0; // 起点到自身的距离为 0
    pq.push( {0, start} ); // {当前点到起点的距离, 当前点}
    //3.开始遍历堆
    while (!pq.empty()) {
        //pq中存储的是pair<int,int>，first是距离，second是节点,这么存储是因为priority_queue存储的是pair时默认按照first排序
        int d = pq.top().first; //取出堆顶元素的距离    
        int u = pq.top().second; //取出堆顶元素的节点
        //5.弹出堆顶元素
        pq.pop();
        // 如果当前点的距离已经不是最优，则跳过
        if (d > dist[u]) continue;
        // 遍历堆顶元素u的邻接点
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;//取出邻接点  
            int w = graph[u][i].second;//取出邻接点的距离
            if (dist[u] + w < dist[v]) { // 发现更短路径
                dist[v] = dist[u] + w;
                pq.push({dist[v], v}); // 加入优先队列
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back( {v, w} );
    }

    vector<int> shortestDistances = dijkstra(1);
    if(shortestDistances[n]!=INF){
    cout<<shortestDistances[n]<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
