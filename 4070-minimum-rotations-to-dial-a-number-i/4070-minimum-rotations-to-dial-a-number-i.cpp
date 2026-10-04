class Solution {
public:
    int minRotations(string s) {
        int curr = 0;
        int ans = 0;

        for (char ch : s) {
            int target = ch - '0';

            int diff = abs(curr - target);

            ans += min(diff, 10 - diff);

            curr = target;
        }

        return ans;
    }
};