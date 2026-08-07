class Solution {
public:
    int balancedStringSplit(string s) {
        int left=0;
        int count=0;
        int right=0;

        for(char ch : s){
            if(ch=='L'){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                count++;
            }
        }
        return count ;
    }
};