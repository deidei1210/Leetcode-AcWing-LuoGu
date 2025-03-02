//leetcode-77
//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
// 1. 只使用数字1到9
// 2. 每个数字最多使用一次 
// 3. 返回所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

#include<iostream>
#include<vector>

using namespace std;
int k=0;
int n=0;
vector<int> path;
vector<vector<int> > result;
int visited[10];

void combinationSum3(int k, int n,int startIndex) {
    if(k==0){
        if(n==0){
            result.push_back(path);
        }
        return;
    }
    //从1到9之中挑选一个数
    for(int num=startIndex;num<=9;num++){
        if(n>=num&&!visited[num]){
            path.push_back(num);
            visited[num]=1;
            combinationSum3(k-1,n-num,num+1);
            path.pop_back();
            visited[num]=0;
        }
    }
}
int main(){
    cin>>k>>n;
    combinationSum3(k,n,1);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<k;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
