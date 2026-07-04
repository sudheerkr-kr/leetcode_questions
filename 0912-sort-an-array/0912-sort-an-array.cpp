class Solution {
public:
    void merge(vector<int>&arr , vector<int>&temp , int start, int mid, int end){
        int i = start ;
        int j= mid+1 ;
        int k=start;
        while(i<= mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k]= arr[i];
                k++;
                i++;
            }
            else{
                temp[k]= arr[j];
                k++;
                j++;
            }
        }    
            while(i<=mid ){
                temp[k++]=arr[i++];

            }
            while(j <=end){
                temp[k++]= arr[j++];
            }
            while(start<=end){
                arr[start] =temp[start];
                start++;
            }
        
    }
    void mergeSort(vector<int>&arr , vector<int>&temp , int start, int end){
        if(start>=end){
            return ;

        }
        int mid=(start+end)/2;
        
        mergeSort(arr, temp , start, mid);
        mergeSort(arr , temp , mid+1 , end);
        merge(arr, temp, start , mid , end);
    }
    vector<int> sortArray(vector<int>& nums) {
       vector<int> temp(nums.size(),0);
       mergeSort(nums, temp , 0, nums.size()-1);
       return nums; 
    }
};