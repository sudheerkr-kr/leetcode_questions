class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n= rain.size();
        int alice =0;
        int bob=0;
        vector<string>ans(n);
        for(int i=0; i<n; i++){
            bool a = ( i< n-1 && rain[i]==1 && rain[i+1]==1);
            bool b =(rain[i]==1);
            if(a&&b){
                if(alice <=bob){
                    ans[i]="Alice";
                    alice++;
                }
                else{
                    ans[i]="Bob";
                    bob++;
                }
            }
            else if(b){
                ans[i]="Bob";
                bob++;
            }
            else{
                ans[i]= "None";
            }
        }
        return ans;
    }
};