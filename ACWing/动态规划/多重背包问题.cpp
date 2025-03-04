#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,V;
    cin>>N>>V;
    vector<int> v,w;
    int x,y,z;
    int sum=0;//用来记录一共有多少个物品
    for(int i=1;i<=N;i++){
        cin>>x>>y>>z;
        sum+=z;
        while(z--){
            v.push_back(x);
            w.push_back(y);
        }
    }
    int dp[V+1]={0};
    for(int i=0;i<v.size();i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    int res=0;
    for(auto item:dp){
        res=max(item,res);
    }
    cout<<res<<endl;
    return 0;
}