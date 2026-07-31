class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // frequency count
        for(int i : nums) {
            freq[i]++;
        }

        vector<int> ans;

        for(int i = 0; i < k; i++) {

            int maxFreq = 0;
            int num = 0;

            // maximum frequency wala element find karo
            for(auto x : freq) {
                if(x.second > maxFreq) {
                    maxFreq = x.second;
                    num = x.first;
                }
            }

            ans.push_back(num);

            // same number dobara na aaye
            freq[num] = 0;
        }

        return ans;
    }
};