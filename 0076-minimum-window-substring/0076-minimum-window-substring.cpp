class Solution {
public:
    string minWindow(string s, string t) {
       
       if(t.size()>s.size()){
        return "";
       }
       int freq[128]={0};
       for(int i=0 ; i<t.size() ; i++){
        freq[t[i]]++;
       }

       int j=0; 
       int count=0;
       int minlen =INT_MAX;
       int start=0;

       for(int i=0; i<s.size() ; i++){
            if(freq[s[i]]>0)
            {
                count++;
            }
            freq[s[i]]--;
            while(count==t.size())
            {
                if(i-j+1 <minlen){
                    minlen=i-j+1;
                    start=j;
                }
                freq[s[j]]++;
                if(freq[s[j]]> 0){
                    count--;
                }
                j++;
            }

       } 
       if(minlen == INT_MAX){
        return "";
       }
       return s.substr(start,minlen);

    }
};