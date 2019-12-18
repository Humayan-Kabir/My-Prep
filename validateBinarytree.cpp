/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkValidity(root, -1e18, 1e18);
    }
    bool checkValidity(TreeNode *root, long long minValue, long long maxValue) {
        if(root == NULL) return true;
        if(root->val < minValue || root->val > maxValue) {
            return false;
        }
        return checkValidity(root->left, minValue, min(maxValue, 1LL * root->val - 1)) 
            & checkValidity(root->right, max(1LL * root->val + 1, minValue), maxValue);
    }
};

