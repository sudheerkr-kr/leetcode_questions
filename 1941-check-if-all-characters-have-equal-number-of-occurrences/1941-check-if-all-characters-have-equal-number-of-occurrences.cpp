class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int>mp;
        for(int i=0; i<s.size() ; i++){
            mp[s[i]]++;
        }
        int freq = mp.begin()->second;
        for(auto it:mp){
            if(it.second!=freq){
                return false;
            }
        }
        return true;

    }
};