class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x =0;
        int sum =0;

        if(n==0){
            return 0;
        }
        string s = to_string(n);
        for(char ch : s){
            int digit = ch-'0';
            if(digit!=0){
                x=x*10 + digit;
                sum =sum + digit;
            }
        }

        return x*sum;
    }
};