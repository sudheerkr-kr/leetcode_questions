class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> blocks;
        for(int i=0; i<nums.size() ;){
            int x= nums[i];
            blocks[x]++;



          while(i<nums.size() && nums[i]==x){
              i++;
          }  
        }
        int ans=0;
        for(auto it:blocks){
            if(it.second==1){
                ans++;
            }
        }
        return ans;
    }
};