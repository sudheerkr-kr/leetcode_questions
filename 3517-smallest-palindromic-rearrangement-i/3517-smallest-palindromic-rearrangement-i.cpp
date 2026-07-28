class Solution {
public:
    string smallestPalindrome(string s) {

        sort(s.begin(), s.end());

        string left = "";
        string mid = "";

        for (int i = 0; i < s.size(); i++) {

            // Pair milgya hme
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                left += s[i];
                i++; 
            }
            else {
                // Unpaired character bichh me daal denge 
                mid = s[i];
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};