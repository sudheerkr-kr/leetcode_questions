class Solution {
public:
    void mergeInPlace(vector<int>&arr , int start, int mid, int end){
        int total_size = end-start+1;
        int gap =  total_size/2 +total_size%2;
        while(gap>0){
            int i= start , j =  start +gap  ;
            while(j<= end){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
                ++i , ++j ;
            }
            gap = gap<=1 ? 0 : (gap/2) + gap%2 ;
        } 
        
    }
    void mergeSort(vector<int>&arr , int start, int end){
        if(start>=end){
            return ;

        }
        int mid=(start+end)/2;
        
        mergeSort(arr , start, mid);
        mergeSort(arr  , mid+1 , end);
        mergeInPlace(arr,  start , mid , end);

    }
    vector<int> sortArray(vector<int>& nums) {
       
       mergeSort(nums, 0, nums.size()-1);
       return nums; 
    }
};