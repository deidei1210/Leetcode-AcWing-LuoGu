#include<iostream>
#include<vector>
using namespace std;

int N=0; //表示有N个数
vector<int> path;  
void DFS(int count){
    if(count==N){
        for(int i=0;i<N-1;i++){
            cout<<path[i]<<" ";
            path.pop_back();
        }
        cout<<path[N-1]<<endl;
        path.pop_back();
        return;
    }
    
    for(int i=count;i<=N;i++){
        path.push_back(i);
        DFS(count+1);
    }
    
}
int main(){
    cin>>N;
    DFS(0);
    return 0;
}