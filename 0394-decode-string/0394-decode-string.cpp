class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;

        for (auto ch : s) {
            
            if (ch == ']') {
                
                string stringToRepeat = "";

                while (!st.empty() && st.top() != "[") {
                    string temp = st.top();
                    stringToRepeat += temp;
                    st.pop();
                }

                st.pop();   // remove '['

                string numericTimes = "";

                while (!st.empty() && isdigit(st.top()[0])) {
                    numericTimes += st.top();
                    st.pop();
                }

                reverse(numericTimes.begin(), numericTimes.end());

                int n = stoi(numericTimes);

                string currentDecode = "";

                while (n--) {
                    currentDecode += stringToRepeat;
                }

                st.push(currentDecode);
            }
            
            else if (ch == '[') {
                string temp(1, ch);
                st.push(temp);
            }
            
            else {
                string temp(1, ch);
                st.push(temp);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};