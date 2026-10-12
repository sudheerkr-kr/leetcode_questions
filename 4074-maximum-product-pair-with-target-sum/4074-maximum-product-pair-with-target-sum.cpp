class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int>pair={-1,-1};
        int maxProduct = INT_MIN;
        for(int i=0; i<nums.size() ; i++){
            for(int j=0 ; j<nums.size() ; j++){
                if(i!=j && nums[i]+nums[j]==target && nums[i]>nums[j]){
                    int product= nums[i] * nums[j];
                    if(product> maxProduct){
                        maxProduct= product;
                        pair= {i,j};
                    }
                }
            }
        }
        return pair;
        
    }
};