class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans= -1;
       int  minDistance= INT_MAX;
        int distance =0 ;
        for(int i=0 ; i<drones.size() ;  i++){
            int x= drones[i][0];
            int y= drones[i][1];
            int range = drones[i][2];
            distance= abs(x-target[0]) + abs(y-target[1]);
            if (distance <= range){
                if (distance < minDistance) {
                    minDistance = distance;
                    ans= i;
                }   
            }
        }
        return ans;
    }
};