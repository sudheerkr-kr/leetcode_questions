class Fenwick {
public:
    vector<int> bit;

    Fenwick(int n) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        Fenwick ft(all.size());

        long long ans = 0;

        for (int x : prefix) {

            int idx = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;

            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};