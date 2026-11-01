class Solution {
private:
    void dfs(int node , vector<int>adj[] , vector<int> &visited){
      visited[node]=1;
      for(auto it : adj[node]){
          if(!visited[it]){
              dfs(it, adj , visited);
          }
      }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>adj[V];
        
        //to chnge matrix into the list 
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(V,0);
        int count =0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj , visited);
            }
        }
        return count;
    }
};