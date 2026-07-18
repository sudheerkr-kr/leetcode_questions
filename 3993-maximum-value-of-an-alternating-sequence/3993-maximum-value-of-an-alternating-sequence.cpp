class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1){
            return s;
        }

        long long max_odd_index = (n % 2 == 0) ? (n - 1) : (n - 2);

        long long max_val = (long long)s + ((max_odd_index - 1) / 2) * (m - 1) + m;

        return max_val;
    }
};