class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<long long> ans;
        long long sum=0;
        
        for(int i=0; i<nums.size() ; i++){
            sum+= nums[i];
            string s= to_string(nums[i]);
            sort(s.begin() , s.end() , greater<char>());
            long long newNum = stoll(s);
            ans.push_back(newNum-nums[i]);
        }
        sort(ans.rbegin() , ans.rend());
        for(int i=0 ; i<min(k , (int)ans.size()) ; i++){
           sum+=ans[i]; 
        }
        return sum;
    }
};