
class Solution {
public:
    TreeNode* BSTUsingInorder(vector<int>& nums, int s, int e) {
        if(s > e) {
            return NULL;
        }

        int mid = (s + e) / 2;
        int element = nums[mid];

        TreeNode* root = new TreeNode(element);

        root->left = BSTUsingInorder(nums, s, mid - 1);
        root->right = BSTUsingInorder(nums, mid + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        TreeNode* root = BSTUsingInorder(nums, s, e);

        return root;
    }
};
