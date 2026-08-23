class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        // Find XOR of both unique numbers
        for (int n : nums) {
            x ^= n;
        }

        // Find any bit where the two numbers are different
        int bit = 1;
        while ((x & bit) == 0) {
            bit = bit << 1;
        }

        int a = 0, b = 0;

        // Divide numbers into two groups
        for (int n : nums) {
            if (n & bit)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};