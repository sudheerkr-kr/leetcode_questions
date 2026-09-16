class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < customers.size(); i++) {
            if(grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        for(int i = 0; i < customers.size(); i++) {
            int temp = sum;

            for(int j = i; j < i + minutes && j < customers.size(); j++) {
                if(grumpy[j] == 1) {
                    temp += customers[j];
                }
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};