class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int ans= 0;
        
        while(i<j){
            int w=j-i;
            int l = min(height[i],height[j]);
            int ar=l*w;
            ans = max(ans,ar);
           if(height[i]<height[j]){
            i++;
           }
           else{
            j--;
           }

        }
        return ans;
    }
};