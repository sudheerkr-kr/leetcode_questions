class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        // Mark visited indices
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        // Find indices that were never visited
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};