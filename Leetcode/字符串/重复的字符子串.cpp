//leetcode 459
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
#include<iostream>
#include<string>
#include<vector>
using namespace std;


string str="";

bool repeatedSubstringPattern(string s) {
    // 1. 将原字符串s复制一遍得到s+s
    // 2. 去掉首尾字符,得到新字符串STR
    // 3. 如果原字符串s是由重复子串构成的,那么在STR中一定能找到s
    // 例如: s="abab", s+s="abababab"
    // 去掉首尾后STR="bababa"
    // 可以在STR中找到"abab",说明s是由重复子串构成的
    
    // string的erase函数有以下几种用法:
    // 1. erase(pos,len) - 删除从pos开始的len个字符
    // 2. erase(iterator) - 删除iterator指向的单个字符（iterator相当于一个指针）
    // 3. erase(iterator first, iterator last) - 删除[first,last)范围内的字符
    string STR = s + s;
    STR.erase(STR.begin()); // 使用erase(iterator)删除第一个字符
    STR.erase(STR.end()-1); // 使用erase(iterator)删除最后一个字符
    
    // 使用find函数查找s是否在STR中出现
    // 如果找到则返回true,否则返回false

    // find函数用法:
    // 1. find(str) - 查找str在字符串中第一次出现的位置
    // 2. find(str, pos) - 从pos位置开始查找str第一次出现的位置
    // 3. 如果找到则返回位置索引,否则返回string::npos
    if(STR.find(s) != string::npos) { // 查找s在STR中是否存在
        return true;
    }
    else {
        return false;
    }
}

int main(){
    cin>>str;
    if(repeatedSubstringPattern(str)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;   
}