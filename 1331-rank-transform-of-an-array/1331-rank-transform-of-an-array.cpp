class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // copy kiya original array
        vector<int> temp = arr;

        // Sort the copy
        sort(temp.begin(), temp.end());

        // Store kro rank ko
        unordered_map<int, int> mp;

        int rank = 1;

        for (int i = 0; i < temp.size(); i++) {

            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank;
                rank++;
            }
        }

        // replace
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};