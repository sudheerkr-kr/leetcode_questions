class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans=0; 
        for(int i=0; i<nums.size() ; i++){
            int mini = INT_MAX;
            int bit = INT_MAX;
            for(int j=i; j<nums.size() ; j++){
                mini= min(mini,nums[j]);
                bit = bit&nums[j];
                if(bit==mini){
                    ans++;
                }
            }
        }
        return ans;
    }
};