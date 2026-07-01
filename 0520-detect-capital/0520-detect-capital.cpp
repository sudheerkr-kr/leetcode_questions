class Solution {
public:
    bool detectCapitalUse(string word) {
  
        if (isupper(word[0])) {

            // Agar second letter bhi uppercase hai
            if (word.size() > 1 && isupper(word[1])) {

                for (int i = 2; i < word.size(); i++) {
                    if (!isupper(word[i])) {
                        return false;
                    }
                }
                return true;
            }

            // Agar second letter lowercase hai
            else {

                for (int i = 1; i < word.size(); i++) {
                    if (!islower(word[i])) {
                        return false;
                    }
                }
                return true;
            }
        }

        
        
        if(islower(word[0])){       
            for(int i=1 ; i< word.size() ; i++){
                if(!islower(word[i])){
                    return false;
                }
            }
            return true;
        } 
        return true;   
    }
};