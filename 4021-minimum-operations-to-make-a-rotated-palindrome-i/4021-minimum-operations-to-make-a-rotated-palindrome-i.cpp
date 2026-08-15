class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            int cost = i;
            for(int j = 0; j < n / 2; j++){
                int k = n - 1 - j;

                char a = s[(j + i) % n];
                char b = s[(k + i) % n];

                int x = (b - a + 26) % 26;
                int y = (a - b + 26) % 26;

                cost += min(x, y);
            }
            ans = min(ans, cost);
        }

        return ans;
    }
};