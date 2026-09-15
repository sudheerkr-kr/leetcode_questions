class Solution {
public:
    int characterReplacement(string s, int k) {
        int  j=0;
        int ans=0; 

        int freq[26]={0};
        int maxfreq = 0;
        for (int  i=0; i<s.size(); i++){
            freq[s[i] - 'A']++;
            maxfreq= max(maxfreq ,freq[s[i]-'A']);
            while((i-j+1) - maxfreq > k){
                freq[s[j] - 'A']--;
                j++;
            }
            ans= max(ans, i-j+1);

        }
        return ans;
    }
};