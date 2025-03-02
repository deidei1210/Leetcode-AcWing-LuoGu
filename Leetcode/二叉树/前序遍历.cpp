#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left=NULL;
    TreeNode *right=NULL;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int v_num=0;//表示二叉树有多少个节点
string input="";
vector<int> preorderTraversal(TreeNode* root) {
    
}

int main(){
    cin>>v_num;
    for(int i=0;i<v_num;i++){
        cin>>input;
        if(input=="null"){
            continue;
        }
        else{

        }
    }

    return 0;
}
