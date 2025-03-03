//leetcode 70
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    //dp[i]表示有dp[i]种方法可以爬上第i层楼梯
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        //到达第i层有两种方法，一种是从第i-1层爬上去，另一种是从i-2层爬上去
        dp[i]=dp[i-2]+dp[i-1];
    }
    cout<<dp[n]<<endl;
    return 0;
}