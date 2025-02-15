#include<iostream>
#include<vector>
using namespace std;

//给定一个整数 n，将数字 1∼n排成一排，将会有很多种排列方法。现在，请你按照字典序将所有的排列方法输出。

int N=0; //数字的个数
vector<int> path;
vector<bool> visited;  // 标记数字是否已被使用，以防止出现重复的数字

void DFS(int count){
    //结束条件
    if(count==N){
        for(int i=0;i<N-1;i++){
            cout<<path[i]<<" ";
        }
        cout<<path[N-1]<<endl;
        return;
    }
    for(int i=1;i<=N;i++){
         if (!visited[i]) {  // 如果数字 i 没有被使用
            visited[i] = true;  // 标记为已使用
            path.push_back(i);  // 将数字加入路径
            DFS(count + 1);  // 递归
            path.pop_back();  // 回溯，移除最后一个数字
            visited[i] = false;  // 恢复状态，标记为未使用
        }
    }
}
int main(){
    cin>>N;
    visited.resize(N + 1, false);  // 初始化 visited 数组，N+1 因为数字是从 1 到 N
    DFS(0);
    return 0;
}