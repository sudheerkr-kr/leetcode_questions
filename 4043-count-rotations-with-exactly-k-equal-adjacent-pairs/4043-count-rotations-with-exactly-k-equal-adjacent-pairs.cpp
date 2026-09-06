class Solution {
public:
    int countRotations(string s, int k) {
        if(s.size()==1){
            return(k==0) ? 1:0;
            
        }
        int totalEqual=0;
        for(int i=0; i<s.size() ; i++){
            if(s[i]==s[(i+1)%s.size()]){
                totalEqual++;
            }
        }

        int ans=0; 
        for(int j = 0 ; j<s.size(); j++){
            int brkn = (j-1+s.size())%s.size();
            int score;
            if(s[brkn]==s[j]){
                score = totalEqual-1;
            }
            else{
                score = totalEqual;
            }
            if(score==k){
                ans++;
            }
        }
        return ans ;
    }
};