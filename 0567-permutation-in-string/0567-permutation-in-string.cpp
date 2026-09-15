class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        int freq[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int count = s1.size();
        int j = 0;

        for (int i = 0; i < s2.size(); i++) {

            if (freq[s2[i] - 'a'] > 0) {
                count--;
            }

            freq[s2[i] - 'a']--;

            if (i - j + 1 > s1.size()) {

                if (freq[s2[j] - 'a'] >= 0) {
                    count++;
                }

                freq[s2[j] - 'a']++;
                j++;
            }

            if (count == 0) {
                return true;
            }
        }

        return false;
    }
};