class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int length = s.size();

        vector<long long> power10(length + 1, 1);
        for (int i = 1; i <= length; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        vector<int> prefixDigitSum(length + 1, 0);
        vector<int> prefixNonZeroCount(length + 1, 0);
        vector<long long> prefixNumber(length + 1, 0);

        for (int i = 1; i <= length; i++) {

            int currentDigit = s[i - 1] - '0';

            prefixDigitSum[i] = prefixDigitSum[i - 1] + currentDigit;

            prefixNonZeroCount[i] =
                prefixNonZeroCount[i - 1] + (currentDigit != 0);

            prefixNumber[i] = prefixNumber[i - 1];

            if (currentDigit != 0) {
                prefixNumber[i] =
                    (prefixNumber[i] * 10 + currentDigit) % MOD;
            }
        }

        vector<int> answer;

        for (const auto &query : queries) {

            int left = query[0];
            int right = query[1];

            int nonZeroDigits =
                prefixNonZeroCount[right + 1] - prefixNonZeroCount[left];

            if (nonZeroDigits == 0) {
                answer.push_back(0);
                continue;
            }

            int digitSum =
                prefixDigitSum[right + 1] - prefixDigitSum[left];

            long long concatenatedNumber =
                (prefixNumber[right + 1]
                - (prefixNumber[left] * power10[nonZeroDigits]) % MOD
                + MOD) % MOD;

            answer.push_back((concatenatedNumber * digitSum) % MOD);
        }

        return answer;
    }
};
