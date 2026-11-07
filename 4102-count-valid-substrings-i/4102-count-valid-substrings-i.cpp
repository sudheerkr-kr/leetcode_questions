class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long valid = 0;
        int start = -1;

        for(int i = 0; i < n; i++){
            if(i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c'){
                start = i - 2;
            }

            valid += (i - start);
        }

        return valid;
    }
};