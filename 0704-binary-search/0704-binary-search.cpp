class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i= 0;
        int j= nums.size()-1;
        int mid= i + (j-i)/2;
        while(i<=j){
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                i = mid+1;
            }
            else{
                j= mid-1;
            }
            mid= i + (j-i)/2;
        }
        return -1;
    }
};