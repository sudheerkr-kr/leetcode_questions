class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        for(int i=1; i<nums.size()-1 ; i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                a.push_back(nums[i]);
            }
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                b.push_back(nums[i]);
            }
        }
        int sum_a=0;
        int sum_b=0;
        for(int i=0; i<a.size() ; i++){
            sum_a+=a[i];
        }
        for(int i=0; i<b.size(); i++){
            sum_b+=b[i];
        }
        return sum_a-sum_b;
    }
};