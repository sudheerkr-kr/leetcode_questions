class Solution {
public:
    bool checkString(string s) {
        bool ans= false;
        for(int i=0; i<s.size()  ; i++){
            if(s[i]=='a'){
                if(ans){
                    return false;
                }
            }
            if(s[i]=='b'){
                ans = true;
            }
        }
        return true  ;
    }
};