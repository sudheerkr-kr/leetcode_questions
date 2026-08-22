class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        int product = 1;

        while (n != 0) {
            int digit = n % 10;

            digitSum += digit;
            product *= digit;

            n /= 10;
        }

        int ans = digitSum + product;

        return original % ans == 0;
    }
};