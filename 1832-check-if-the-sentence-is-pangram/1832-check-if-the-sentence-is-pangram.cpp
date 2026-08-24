class Solution {
public:
    bool checkIfPangram(string sentence) {
         int freq[26]={0};
        for(int i=0; i<sentence.size() ; i++){
            freq[sentence[i]-'a']++;
        }
        for(int j=0; j<26 ; j++){
            if(freq[j]<1){
                return false;
            }
        }
        return true;
    }
};