class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;
       for(int i =0; i<nums.size() ; i++){
        if(nums[i]%2==1){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
       } 
       sort(ans.begin() , ans.end());
       return ans;
    }
};