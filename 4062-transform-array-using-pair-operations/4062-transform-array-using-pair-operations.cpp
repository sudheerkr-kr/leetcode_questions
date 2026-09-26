class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long a=0;
        long long b=0;
        for(int i=0; i<source.size() ; i++){
            a+=source[i];
        }
        for(int i=0; i<target.size() ; i++){
            b+=target[i];
        }
        if(a==b){
            return true;
        }
        return false ;
    }
};