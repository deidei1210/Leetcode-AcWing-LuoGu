//leetcode 151 反转字符串中的单词
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

string str="";

string reverseString(string str){
    stack<string> s;
    string word="";
    for(int i=0;i<str.length();i++){
        //当前字符不是空格
        if(str[i]!=' '){
            word+=str[i];
        }
        //当前字符是空格
        else{
            if(!word.empty()){
                s.push(word);
                word="";
            }
        }
    }
    if(!word.empty()){
        s.push(word);
    }
    string res="";
    while(!s.empty()){
        res+=s.top();
        s.pop();
        if(!s.empty()){
            res+=" ";
        }
    }
    return res;
}

int main(){
    getline(cin, str);
    cout << reverseString(str)<<endl;
    return 0;
}