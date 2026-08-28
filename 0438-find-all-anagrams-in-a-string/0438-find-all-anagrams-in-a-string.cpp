class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        // frequency of p
        for (char ch : p) {
            freqP[ch - 'a']++;
        }

        int k = p.length();

        // Sliding Window
        for (int i = 0; i < s.length(); i++) {

            // add current character
            freqS[s[i] - 'a']++;

            // window size > k
            if (i >= k) {
                freqS[s[i - k] - 'a']--;
            }

            // window size == k
            if (i >= k - 1) {
                if (freqS == freqP) {
                    ans.push_back(i - k + 1);
                }
            }
        }

        return ans;
    }
};