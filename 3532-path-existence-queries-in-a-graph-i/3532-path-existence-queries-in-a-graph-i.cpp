class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        // component[i] = connected component of node i
        vector<int> component(n);

        component[0] = 0;
        int currentComponent = 0;

        for (int i = 1; i < n; i++) {

            // New component starts
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentComponent++;
            }

            component[i] = currentComponent;
        }

        vector<bool> answer;

        for (auto &query : queries) {

            int u = query[0];
            int v = query[1];

            if (component[u] == component[v])
                answer.push_back(true);
            else
                answer.push_back(false);
        }

        return answer;
    }
};