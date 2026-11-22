class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans =0; 
        if(nums.size()==1){
            return 1;
        }
        for(int i=0; i<nums.size() ; i++){
            if(i==0 ){
                if(nums[i]>=nums[i+1]){
                  ans++;
                }
            }
            else if(i == nums.size()-1) {
                if(nums[i] >= nums[i-1]) {
                    ans++;
                }
            }
            else {
                 if(2LL * nums[i] >= 1LL * nums[i-1] + nums[i+1]) {
                    ans++;
                }
            }
        }
        return ans ;
    }
};