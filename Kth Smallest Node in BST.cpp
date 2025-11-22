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
    int count = 0;
    int result = -1;

    void inorder_optimized(TreeNode* node, int k) {
        if (node == nullptr || result != -1) return;
        inorder_optimized(node->left, k);
        count++; 
        if (count == k) {
            result = node->val;
            return;
        }
        inorder_optimized(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;   
        result = -1; 
        inorder_optimized(root, k);
        return result;
    }
};
