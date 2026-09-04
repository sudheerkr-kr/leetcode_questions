class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> PSE(n);
        vector<int> NSE(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                PSE[i] = -1;
            else
                PSE[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                NSE[i] = n;
            else
                NSE[i] = st.top();

            st.push(i);
        }

        // Calculate maximum area
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = NSE[i] - PSE[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
public:
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n= matrix.size();
        int m= matrix[0].size();
        for(int i=0; i<n ; i++){
            vector<int> t;
            for(int j=0; j<m; j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area =largestRectangleArea(v[0]);
        for(int i=0; i<n ;i++){
            for(int  j=0; j<m ; j++){
                //let's update current row with previous values;
                if(i > 0 && v[i][j]){
                    v[i][j]+= v[i-1][j];
                }
                else if(v[i][j] == 0){
                    v[i][j]=0;
                }


            }
            area= max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};