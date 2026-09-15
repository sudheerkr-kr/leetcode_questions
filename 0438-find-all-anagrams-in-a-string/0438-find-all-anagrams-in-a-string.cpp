class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size()){
            return ans;
        }

     int freq[26]={0};
     for(int i=0; i<p.size(); i++){
        freq[p[i]-'a']++;
     }   
     int j=0;
     int count=p.size(); 
     for(int i=0; i<s.size() ; i++){
        if(freq[s[i]-'a']>0){
            count--;
        }
        freq[s[i]-'a']--;
        if(i-j+1 >p.size()){
            if(freq[s[j]-'a']>=0){
                count++;
            }
            freq[s[j]-'a']++;
            j++;
        }
        if(count==0){
            ans.push_back(j);
        }

     }
     return ans;
    }
};