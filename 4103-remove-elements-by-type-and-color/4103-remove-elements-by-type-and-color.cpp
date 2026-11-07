class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        struct element{
            int type;
            int color;
            int count;
        };

        vector<element> st;
        int n = types.size();

        for(int i = 0; i < n; i++){
            int t = types[i];
            int c = colors[i];
            int required = groupSize[t];

            if(!st.empty() && st.back().type == t && st.back().color == c){
                st.back().count++;
                if(st.back().count == required){
                    st.pop_back();
                }
            }
            else{
                if(required == 1){
                    continue;
                }
                st.push_back({t, c, 1});
            }
        }

        return st.empty();
    }
};