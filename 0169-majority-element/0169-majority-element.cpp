class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i=1 ;i<n; i++){
            if(nums[i]==nums[i-1]){
                count++;

            }
            else{
                count =1;
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return nums[0];
    }
};