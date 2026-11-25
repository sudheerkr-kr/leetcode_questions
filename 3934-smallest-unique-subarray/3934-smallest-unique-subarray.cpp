
class Solution {
public:
    typedef long long ll;

    const ll mod1 = 1000000007;
    const ll mod2 = 1000000009;
    const ll base = 31;

    bool check(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> a = nums;
        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        vector<int> v(n);

        for(int i = 0; i < n; i++) {
            v[i] = lower_bound(a.begin(), a.end(), nums[i]) - a.begin() + 1;
        }

        map<pair<ll,ll>, int> mp;

        ll h1 = 0, h2 = 0;
        ll p1 = 1, p2 = 1;

        for(int i = 0; i < k; i++) {
            h1 = (h1 * base + v[i]) % mod1;
            h2 = (h2 * base + v[i]) % mod2;

            if(i < k-1) {
                p1 = (p1 * base) % mod1;
                p2 = (p2 * base) % mod2;
            }
        }

        mp[{h1, h2}]++;

        for(int i = k; i < n; i++) {
            h1 = (h1 - (v[i-k] * p1) % mod1 + mod1) % mod1;
            h1 = (h1 * base + v[i]) % mod1;

            h2 = (h2 - (v[i-k] * p2) % mod2 + mod2) % mod2;
            h2 = (h2 * base + v[i]) % mod2;

            mp[{h1, h2}]++;
        }

        for(auto it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
