class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0; 
        int ans=0;
        map<int, int>mp;
        for(int i=0; i<nums.size() ; i++){
            mp[nums[i]]++;
            while(mp[0]>k){
                
                mp[nums[j]]--;
                j++;
            }
            ans= max(ans, i-j+1);
        }
        return ans;
    }
};