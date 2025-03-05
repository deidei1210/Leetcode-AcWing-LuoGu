#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int INF=0x3f3f3f3f;

int n;
int main(){
    cin>>n;
    vector<vector<int>> graph(n);
    int x;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cin>>x;
            graph[i-1].push_back(x);
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-INF));
    dp[0][0]=graph[0][0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            //只能从右上角下来
            if(j==0){
                dp[i][j]=graph[i][j]+dp[i-1][0];
            }
            //只能从左上角走下来
            else if(j==i){
                dp[i][j]=graph[i][j]+dp[i-1][j-1];
            }
            //有两条路可以走，比较哪一个更大
            else{
                dp[i][j]=max(graph[i][j]+dp[i-1][j-1],graph[i][j]+dp[i-1][j]);
            }    
        }
    }
    int res = *max_element(dp[n-1].begin(), dp[n-1].end());

    // int res=dp[n-1][0];
    // for(auto i:dp[n-1]){
    //     res=max(res,i);
    // }
    cout<<res<<endl;
    // cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}