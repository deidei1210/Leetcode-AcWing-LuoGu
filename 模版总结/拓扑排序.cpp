#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> res;
bool tuopu(){
    //表示每一个点的入度
    vector<int> degree(n+1,0);
    queue<int> q;
    //首先先计算每一个点的入度
    for(int i=1;i<=n;i++){
        for(auto v:graph[i]){
            degree[v]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            res.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            int nv=graph[v][i];
            if(--degree[nv]==0){
                q.push(nv);
                res.push_back(nv);
            }
        }
    }
    return res.size()==n;

}
int main(){
    cin>>n>>m;
    int x,y;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    if(tuopu()){
        for(auto item:res){
            cout<<item<<" ";
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}