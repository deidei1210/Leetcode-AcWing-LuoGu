/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end()); //将nums数组进行排序
    for(int i:nums){
        cout<<nums[i]<<endl;
    }

}

int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    vector<int> nums;
    int x;
    while (cin >> x ) {
        nums.push_back(x); // Dynamically read input until EOF
    }
    threeSum(nums);
    return 0;
}