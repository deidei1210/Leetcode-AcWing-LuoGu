/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target,
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 
提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。*/

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
    
    int left=0;
    int right=nums.size()-1;
    int mid=(left+right)/2;
    while(left<=right){
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        mid=(left+right)/2;
    }
    return -1;//没找到就返回-1
}

int main(){
    int n=0;//表示数组中元素的个数
    cin>>n;
    vector<int> nums; //用来存储输入的数组
    int number=0;
    //输入已排序数组
    for(int i=0;i<n;i++){
        cin>>number;
        nums.push_back(number);
    }
    int target=0;
    cin>>target;
    // cout<<target<<endl;
    cout<<search(nums,target)<<endl;

    return 0;
}

