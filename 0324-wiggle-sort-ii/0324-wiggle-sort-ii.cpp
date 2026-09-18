class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int n = nums.size();
        int mid = (n - 1) / 2;
        int right = n - 1;

        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                ans.push_back(nums[mid]);
                mid--;
            }
            else {
                ans.push_back(nums[right]);
                right--;
            }
        }

        nums = ans;
    }
};