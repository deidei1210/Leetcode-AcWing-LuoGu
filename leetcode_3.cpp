# include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charHasAppeared; //用来记录字符出现的次数
    int ans=0;//用来记录目前发现的最长的子串

    //滑动窗口的思路，left是窗口的左指针，right是窗口的右指针
    //始终保证窗口内没有重复的字符
    for(int left=0,right=0;right<s.size();right++){
        if(!charHasAppeared.count(s[right])){//如果当前字符没有出现过，就将其加入集合中
            charHasAppeared.insert(s[right]);
        }
        else{//当前字符出现过了，那就移动左指针，将左指针向右移动,直到没有重复的字符
            while(charHasAppeared.count(s[right])&&left<=right){
                charHasAppeared.erase(s[left]);
                left++;
            }
            charHasAppeared.insert(s[right]);
        }
        ans=max(ans,right-left+1);
    }
    return ans;
}

int main(){
    freopen("in.txt","rt",stdin);  //输入文件
    freopen("out.txt","wt",stdout);//输出文件

    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}