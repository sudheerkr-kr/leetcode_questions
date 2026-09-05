class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =1;
        string ans="";
        for(int i=0; i<s.size() ; i++){
            if(s[i]== ' '){
                count++;
            }
            if(count > k){
                return ans;
                break;
            }
            ans.push_back(s[i]);
        }
        return ans  ;
         
    }
};