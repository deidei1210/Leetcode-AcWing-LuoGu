#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,V;
    cin>>N>>V;
    vector<int> v(N+1),w(N+1),s(N+1);
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    int dp[V+1]={0};
    vector<int> backup=s;
    for(int i=0;i<=V;i++){
        for(int j=1;j<=N;j++){
            if(v[j]<=i&&s[j]){
                if(dp[i]<dp[i-v[j]]+w[j]){
                    dp[i]=dp[i-v[j]]+w[j];
                    s[j]--;
                }
            }
        }
        s=backup;
    }
    cout<<dp[V]<<endl;
    return 0;
}