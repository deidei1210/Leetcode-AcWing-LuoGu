#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
using namespace std;
const int INF=1e9;
int n,m;
int x;
int c[101][101];
//分别表示基于当前位置的右，左，下，上
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int solvePuzzle(vector<vector<int>> &puzzle){
   //创建一个队列，用来记录要被BFS的点的顺序
    queue<pair<int,int>> q;
    q.push({0,0});

   //直到队列中没有顶点需要被访问，才停止遍历
   while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<=n-1&&ny>=0&&ny<=m-1&&puzzle[nx][ny]==0){
                if(c[nx][ny]>c[x][y]+1){
                    c[nx][ny]=c[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
   }
    return c[n-1][m-1];
}
int main(){
    cin>>n>>m;
    vector<vector<int>> puzzle(n);
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            c[i][j] = INF;
    c[0][0]=0; //自己当前的位置走的步数为0
    //迷宫中只包含0或1
    //0:可以走的路
    //1:不可通过的墙壁
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            puzzle[i].push_back(x);
        }
    }
    cout<<solvePuzzle(puzzle)<<endl;
    return 0;
}