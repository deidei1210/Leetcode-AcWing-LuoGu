//leetcode28 找出字符串中第一个匹配项的下标
#include<iostream>
#include<vector>

using namespace std;

string heystack="";
string needle="";

//获取next数组
vector<int> getNext(string needle){
    vector<int> next(needle.size());
    next[0]=0;//初始化next[0],next[0]为0
    int j=0;//j为前缀末尾
    for(int i=1;i<needle.size();i++){ //遍历needle字符串
        while(j>0 && needle[i]!=needle[j]){ //当前字符不匹配
            j=next[j-1]; //回退到前缀末尾
        }
        // 当前字符串匹配，说明可以直接在前面的基础上+1
        if(needle[i]==needle[j]){ //当前字符匹配
            j++; //前缀末尾后移
        }
        next[i]=j; //更新next[i]
    }
    return next;
}

//KMP算法实现
int strStr(string haystack, string needle) {
    // 如果needle为空，返回0
    if(needle.size()==0){
        return 0;
    }
    // 获取next数组
    vector<int> next=getNext(needle);
    int j=0;
    // 遍历haystack字符串
    for(int i=0;i<haystack.size();i++){
        // 如果当前字符不匹配，回退到前缀末尾
        while(j>0 && haystack[i]!=needle[j]){
            j=next[j-1];
        }
        // 如果当前字符匹配，前缀末尾后移
        if(haystack[i]==needle[j]){
            j++;
        }
        // 如果j==needle.size()，说明needle字符串完全匹配
        if(j==needle.size()){
            return i-needle.size()+1;
        }
    }
    return -1;
}

int main(){
    cin>>heystack>>needle;
    cout<<strStr(heystack,needle)<<endl;
    return 0;
}



