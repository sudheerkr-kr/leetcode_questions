class Solution {
public:
    int josephus_rec(int n , int k){
       if(n==0){
        return 0;
       } 
       return (josephus_rec(n-1 , k)+k)%n ;
    }
    int josephus (int n, int k){
        //is problem ko josephus problem bhi bolte h isliye function call josephus naam sse bnai h
        
        int ans=0 ;
        for(int i=2 ; i<=n ; i++){
            ans= (ans+k)%i ;
        }
        return ans+1;
    }
    int findTheWinner(int n, int k) {
        return josephus(n, k);
        return josephus_rec(n, k)+1;  ////for recursive approach
    }
};