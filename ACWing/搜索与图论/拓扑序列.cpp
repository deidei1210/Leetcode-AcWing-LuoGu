#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> graph;
vector<int> res;

bool tuopu() {
    vector<int> in_degree(n+1, 0);  // 初始化每个节点的入度为0
    queue<int> q;  // 用于存储入度为0的节点的队列
    // 计算每个节点的入度
    for(int i = 1; i <= n; i++) {
        for(int v : graph[i]) {
            in_degree[v]++;  // 增加节点v的入度
        }
    }
    // 将所有入度为0的节点加入队列
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);  // 入度为0的节点入队
        }
    }
    // 处理队列中的节点
    while(!q.empty()) {
        int v = q.front();  // 取出队首节点
        q.pop();  // 移除队首节点
        res.push_back(v);  // 将节点v加入拓扑序列

        // 更新节点v的邻接点的入度
        for(int u : graph[v]) {
            if(--in_degree[u] == 0) {  // 如果邻接点u的入度减为0
                q.push(u);  // 将邻接点u加入队列
            }
        }
    }
    // 如果拓扑序列的大小小于n，说明图中存在环
    return res.size() == n;
}
int main() {
    cin >> n >> m;
    graph.resize(n+1);
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);  // 只存有向边
    }
    if (tuopu()) {
        for(auto v : res) {
            cout << v << " ";
        }
    } else {
        cout << -1 << endl;  // 存在环，无拓扑序
    }
    return 0;
}