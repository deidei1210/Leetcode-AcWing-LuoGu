#include<iostream>
#include<vector>

using namespace std;

int N,V;


int main(){
    cin>>N>>V;
    vector<vector<int>> v(N),w(N);
    int x,y,num;
    //一共有N组
    for(int i=0;i<N;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>x>>y;
            v[i].push_back(x);
            w[i].push_back(y);
        }
    }
    vector<int> dp(V+1,0);
    // 遍历每一个组
    for(int i=0;i<N;i++){
        // 从背包容量V开始，逆序遍历到0
        for(int j=V;j>=0;j--){
            // 遍历每一个组中的每一个物品
            for(int k=0;k<v[i].size();k++){
                // 如果当前背包容量j大于等于物品体积v[i][k]
                // 则更新dp[j]，选择是否将该物品放入背包
                if(j>=v[i][k]) dp[j]=max(dp[j],dp[j-v[i][k]]+w[i][k]);
            }
        }
    }
    // 逆序遍历背包容量是为了避免在同一组内重复选择同一个物品
    // 这样可以确保每个组内的物品只能被选择一次
    int res=0;
    for(auto item:dp){
        res=max(item,res);
    }
    cout<<res<<endl;
    return 0;
}



