class Solution {
public:
    bool isPalindrome(string s) {

        string ans_1 = "";
        string ans_2 = "";

        // for(char &c : s)
        // {
        //     if(isalnum(c))
        //     {
        //         ans_1.push_back(tolower(c));
        //     }
        // }
        for(int i = 0; i < s.size(); i++)
        { 
          char &c = s[i];  
          if((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') ||(c >= '0' && c <= '9'))
           {
                // convert uppercase to lowercase manually
                if(c >= 'A' && c <= 'Z')
                    {
                      c = c + 32;
                    }
                ans_1.push_back(c);
           }
        }



        for(int i=ans_1.size()-1; i>=0; i--){
            ans_2.push_back(ans_1[i]);
        }

        if(ans_1==ans_2){
            return true;
        }
        return false;
    }
};