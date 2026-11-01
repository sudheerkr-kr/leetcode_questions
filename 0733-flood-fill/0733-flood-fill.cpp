class Solution {
    private:
        void dfs(vector<vector<int>>& answ , vector<vector<int>>&image , int row, int col, int Color, int delrow[] , int delcol[] , int inicolor){
        answ[row][col]= Color;
        int n=image.size();
        int m= image[0].size();
        for(int i=0; i<4 ; i++){
            int nrow =row +delrow[i];
            int ncol =col +delcol[i];
            if(nrow>=0 && ncol>=0&&ncol<m && nrow < n  && image[nrow][ncol] ==inicolor &&answ[nrow][ncol]!=Color){
                dfs(answ ,image , nrow , ncol , Color, delrow, delcol,inicolor);
            }
        }
    }
  public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int Color) {
        // code here
        int inicolor= image[sr][sc];
        vector<vector<int>> answ = image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(answ, image,sr,sc,Color,delrow,delcol, inicolor);
        return answ;
    }
};