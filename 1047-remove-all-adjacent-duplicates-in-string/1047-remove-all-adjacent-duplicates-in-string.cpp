class Solution {
public:
    string removeDuplicates(string s) {
        //solution using stack //
        stack<char>st;
        string ans="";
        for( auto ch: s){
            
            if(st.empty()){
                
                st.push(ch);
            }

            else if(!st.empty()&& st.top()==ch){
                //
                st.pop();
            
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
        
    }
};