class Solution {
public:
    bool isPalindromic(std::string s) {
        std::string binary = "";

        for (char ch : s) {
            int ascii = (int)ch;

            // 8-bit binary
            for (int bit = 7; bit >= 0; bit--) {
                binary += ((ascii >> bit) & 1) + '0';
            }
        }

        int i = 0;
        int j = binary.length() - 1;

        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};