class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int last_a = -1;
        int max_a_with_b = -1;
        int max_start = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                last_a = i;
            }
            else if(s[i] == 'b'){
                if(last_a != -1){
                    max_a_with_b = max(max_a_with_b, last_a);
                }
            }
            else if(s[i] == 'c'){
                if(max_a_with_b != -1){
                    max_start = max(max_start, max_a_with_b);
                }
            }

            ans += (i - max_start);
        }

        return ans;
    }
};