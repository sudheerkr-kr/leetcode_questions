class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n+1, true) ;
        if(n>=0){
            isPrime[0]= false;
        }
        if(n >=1){
            isPrime[0] = false;
        }
        for(int i=2 ; 1LL*i*i<=n ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j<=n ; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> ans;
        long long sum =0;
        for(int j=2; j<=n ; j++){
            if(isPrime[j]){
                if(sum+j >s){
                    break;
                }
                sum+=j;
                ans.push_back(j);
            }
        }
        return ans;
        
    }
};