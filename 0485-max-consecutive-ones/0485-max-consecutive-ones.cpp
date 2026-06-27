class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int currentStrk =0;
         int maxStrk=0;
        for(int i=0; i< nums.size()  ; i++){
            if(nums[i]==1){
              currentStrk++;
            }
            else{
                maxStrk= max(currentStrk, maxStrk);
                currentStrk=0;
            }
            
        }
        return max(maxStrk, currentStrk);
    }
};