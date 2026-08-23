class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxprdt = INT_MIN;
        int prdct = 1;

        for(int i = 0; i < nums.size(); i++) {

            prdct *= nums[i];

            mxprdt = max(mxprdt, prdct);

            if(prdct == 0) {
                prdct = 1;
            }
        }

        prdct = 1;

        for(int i = nums.size() - 1; i >= 0; i--) {

            prdct *= nums[i];

            mxprdt = max(mxprdt, prdct);

            if(prdct == 0) {
                prdct = 1;
            }
        }

        return mxprdt;
    }
};