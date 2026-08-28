class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int ans;
        for(int i=0 ; i<nums.size() ; i++){
            if(i%10==nums[i]){
                ans= i;

                return ans;
            }
        }
        return -1;
    }
};