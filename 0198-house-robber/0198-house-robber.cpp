class Solution {
public:

    int robHelper(vector<int>& nums, int i, vector<int>& dp) {

        if(i >= nums.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int robAmt1 = nums[i] + robHelper(nums, i + 2, dp);

        int robAmt2 = robHelper(nums, i + 1, dp);

        return dp[i] = max(robAmt1, robAmt2);
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return robHelper(nums, 0, dp);
    }
};