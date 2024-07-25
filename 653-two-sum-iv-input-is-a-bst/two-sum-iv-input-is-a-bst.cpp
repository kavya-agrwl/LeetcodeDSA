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
public:
        bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return inorder(root, k, seen);
    }
    
private:
    bool inorder(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;
        if (inorder(node->left, k, seen)) return true;
        if (seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return inorder(node->right, k, seen);
    }
};