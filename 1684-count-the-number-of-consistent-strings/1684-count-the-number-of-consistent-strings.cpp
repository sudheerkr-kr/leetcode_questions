class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0; 
        bool charMila=false;
        for(int i=0 ; i <words.size() ; i++){
            for(int j=0 ; j<words[i].size() ; j++){
               if(allowed.find(words[i][j]) != string::npos){
                    charMila=true;
               } 
               else{
                    charMila=false;
                    break;
               }         
            }
            if(charMila){
                count =count+1;
            }
            
        }
        return count ;
    }
};