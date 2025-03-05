#include<iostream>
#include<vector>

using namespace std;
int N,V;
int main(){
    cin>>N>>V;
    vector<int> v;
    vector<int> w;
    int x,y,s;
    for(int i=0;i<N;i++){
        cin>>x>>y>>s;
        //二进制优化方法，转换成01背包问题
        for(int k=1;k<=s;s-=k,k*=2){
            v.push_back(k*x);
            w.push_back(k*y);
        }
        if(s>0){
            v.push_back(s*x);
            w.push_back(s*y);
        }
    }
    vector<int> dp(V+1,0);
    for(int i=0;i<v.size();i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    int res=0;
    for(auto i:dp){
        res=max(i,res);
    }
    cout<<res<<endl;
    return 0;
}