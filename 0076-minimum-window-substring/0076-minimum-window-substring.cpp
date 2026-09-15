class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size() > s.size()) {
            return "";
        }

        int freqT[128] = {0};
        int freqS[128] = {0};

        for(int i = 0; i < t.size(); i++) {
            freqT[t[i]]++;
        }

        int j = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int i = 0; i < s.size(); i++) {
            
            freqS[s[i]]++;

            if(freqS[s[i]] <= freqT[s[i]]) {
                count++;
            }

            while(count == t.size()) {
                
                if(i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    start = j;
                }

                freqS[s[j]]--;

                if(freqS[s[j]] < freqT[s[j]]) {
                    count--;
                }

                j++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};