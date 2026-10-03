class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficient =0; //kitne petrol ki kmi h
        int balance=0;// kitna petrol bacha hua h 
        int start=0; //ckt kha se start krna h 
        for(int i=0; i<gas.size() ; i++){
            balance+= gas[i]-cost[i];
            if(balance < 0){
                deficient += balance;
                start=i+1;
                balance=0;
            }
        }
        if(balance + deficient>= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};