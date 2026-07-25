class Solution {
public:
    int maxProduct(int n) {
       string str = to_string(n);
       sort(str.begin(), str.end());
       int sz = str.size() ;
       return (str[sz-1]-'0')*(str[sz-2] -'0');
    }
};