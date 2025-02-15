//n−皇后问题是指将 n个皇后放在 n×n的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
#include<iostream>

using namespace std;
int N=0;
int a[10][10];//棋盘

//判断是否是合法的放置N皇后的位置
bool isValid(int row,int col){
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (a[i][col] == 1) {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (a[i][j] == 1) {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (a[i][j] == 1) {
            return false;
        }
    }  
    return true;  
}
//搜索放置N皇后的位置，回溯法
void DFS(int row){
    //已经到递归树的最后一层了
    if(row==N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(a[i][j]==0){
                    cout<<".";
                }
                else{
                    cout<<"Q";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    //否则就看棋盘当前行是否存在满足条件的位置可以放皇后
    for(int col=0;col<N;col++){
        if(isValid(row,col)){
            a[row][col]=1;
            DFS(row+1);
            a[row][col]=0;
        }
        else
            continue;
    }
}

int main(){
    cin>>N;
    DFS(0);
    return 0;
}