//leetcode-344
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
#include<iostream>
#include<vector>
using namespace std;

vector<char> str;

void reverseString(vector<char>& s) {
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}


int main(){

    int n=0;
    char ch;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ch;
        str.push_back(ch);
    }
    reverseString(str);
    for(int i=0;i<n;i++){
        cout<<str[i]<<" ";
    }
    return 0;
}




