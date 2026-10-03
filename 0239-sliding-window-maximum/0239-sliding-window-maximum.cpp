class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // first window of size k
        for(int i=0; i<k ; i++){
            //chote element remove krdo
            while(!dq.empty() && nums[i]>= nums[dq.back()]){
                dq.pop_back();
            }
            //inserting index , so that we can checkout of window element
            dq.push_back(i);
        }
        //stor answer for fiirst window
        ans.push_back(nums[dq.front()]);
        //remaining windows ko process
        for(int i=k; i<nums.size() ; i++){
            //out of window elemnt ko remove  krdia 
            if(!dq.empty() && i-dq.front() >=k){
                dq.pop_front();
            }
            //ab firse current element k liye chote element ko remove krna h 
            while(!dq.empty() && nums[i]>= nums[dq.back()]){
                dq.pop_back();
            }
            //inserting index , so that we can checkout  of window element 
            dq.push_back(i);
            //current windoow ka answer store krna h 
            ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};