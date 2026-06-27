class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &p : freq) {
            long long x = p.first;

            if (x == 1)
                continue;

            int len = 0;
            long long cur = x;

            while (true) {
                if (!freq.count(cur))
                    break;

                if (freq[cur] >= 2) {
                    len += 2;

                    // Prevent overflow before squaring
                    if (cur > 1000000000LL / cur)
                        break;

                    cur = cur * cur;
                } else {
                    len++;
                    break;
                }
            }

            // If last number had frequency >=2 but couldn't become peak,
            // remove one occurrence.
            if (len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};