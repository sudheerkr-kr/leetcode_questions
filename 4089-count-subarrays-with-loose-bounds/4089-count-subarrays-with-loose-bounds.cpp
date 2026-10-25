class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
         long long ans=0;
        int start =0;
        for(int i=0; i<nums.size() ; i++){
            if(nums[i]<minK || nums[i]>maxK){
                start = i+1;
            }
           
                ans+= i-start+1;
            
        }
        return ans;
    }
};