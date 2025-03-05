#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);  // dp[i] 表示以 nums[i] 结尾的最长上升子序列的长度
    int maxLength = 1;  // 记录最大 LIS 长度
    for (int i = 0; i < n; i++) {  // 遍历每个数作为子序列结尾
        for (int j = 0; j < i; j++) {  // 遍历所有比它小的数
            if (nums[j] < nums[i]) {  // 形成递增关系
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
