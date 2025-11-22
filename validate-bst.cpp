/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool validate(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr) return true;
        if (node->val <= min_val || node->val >= max_val) return false;

        bool is_left_valid = validate(node->left, min_val, node->val);
        if (!is_left_valid) return false;

        bool is_right_valid = validate(node->right, node->val, max_val);
        return is_right_valid;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
