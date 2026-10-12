class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int base=0;
        map<pair<int,int>,int> m;
        for(int i=1; i<nums.size() ; i++){
            if(nums[i]==nums[i-1]){
                base++;
                
            }
            else{
                int a= nums[i-1];
                int b= nums[i];

                if(a>b){
                    swap(a,b);
                    
                }
                m[{a,b}]++;
            }
        }
        int extr =0;
        for(auto &it:m){
            extr = max(extr,it.second);
        }
        return base +extr;
    }
};