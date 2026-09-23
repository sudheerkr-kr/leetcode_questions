class Solution {
public:
    bool isPalindrome(int x) {
        long long sum=0;
        int n=x;

        while(x>0){
       int r=x%10;
       sum=sum*10 +r;
       x=x/10;
        }
if(sum==n){
    return true;
}
else{
    return false;  
}
  
    }
};