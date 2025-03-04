#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N,V;
    //n:物品数量
    //v:背包体积
    cin>>N>>V;
    int v[N+1],w[N+1];
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i];
    }
    //引入一个二维的dp数组dp[i][j]表示对于前i个物品，当背包容量为j的时候最大价值
    int dp[N+1][V+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=V;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=V;j++){
            if(v[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    int res=0;
    for(int i=0;i<N+1;i++){
        for(int j=0;j<V+1;j++){
            // cout<<dp[i][j]<<" ";
            res=max(dp[i][j],res);
        }
        // cout<<endl;
    }
    cout<<res<<endl;

    return 0;
}