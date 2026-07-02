class Solution {
public:

    void solve(vector<string> &ans , int n, int open , int close ,int rem_open, int rem_close ,string output){
        //  base case
        if(rem_open==0 && rem_close ==0){
        ans.push_back(output);
        return;
        }
        // include the open bracket 
        if(rem_open>0){
            output.push_back('(');
            solve(ans , n  ,open +1 , close , rem_open-1, rem_close , output   );
            // backtracking  
            output.pop_back();
              
        }
        // include the close bracket 
        if(close<open){
            output.push_back(')');
            solve(ans , n ,open , close+1, rem_open , rem_close-1 , output   );
            // backtracking  
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        int open =0;
        int close =0;
        int rem_open =n;
        int rem_close =n;
        string output = "";
        solve(ans, n , open , close , rem_open, rem_close , output);
        return ans;
    }
};