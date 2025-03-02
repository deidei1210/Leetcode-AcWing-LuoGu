//leetcode-17
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
string digits;
string combination[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<char> path;
vector< vector<char> > result;

void trackback(string digits,int round){
    if(path.size()==digits.length()){
        result.push_back(path);
        return;
    }
    int d=digits[round]-'0';
    for(int i=0;i<combination[d].size();i++){
        path.push_back(combination[d][i]);
        trackback(digits,round+1);
        path.pop_back();
    }
}


int main(){
    cin>>digits;
    trackback(digits,0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<digits.length();j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }

    
}


