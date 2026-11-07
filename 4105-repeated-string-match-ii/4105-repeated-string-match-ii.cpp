class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        // string ax = "";
        // string by = "";

        // for(int i = 0; i < x; i++){
        //     ax += a;
        // }
        // for(int i = 0; i < y; i++){
        //     by += b;
        // }
        // if(by.size() > ax.size()){
        //     return false;
        // }
        // if(ax.find(by) != string::npos){
        //     return true;
        // }
        // else{
        //     false;
        // }

        long long alen = (long long)a.size() * x;
        long long blen = (long long)b.size() * y;

        if(alen < blen){
            return false;
        }

        int n = a.size();
        int m = b.size();

        for(int i = 0; i < n; i++){
            bool match = true;

            for(long long j = 0; j < blen; j++){
                char char_b = b[j % m];
                char char_a = a[(i+j) % n];

                if(char_b != char_a){
                    match = false;
                    break;
                }

                if(j > n + m){
                    break;
                }
            }

            if(match){
                if(i + blen <= alen){
                    return true;
                }
            }
        }

        return false;
    }
};