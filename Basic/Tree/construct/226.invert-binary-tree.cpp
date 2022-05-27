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
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
public:
    void traversal(TreeNode* root) {
        if (root == nullptr) {return;}
        else {
            swap(root -> left, root -> right);
            if (root -> left != nullptr) traversal(root -> left);
            if (root -> right != nullptr) traversal(root -> right);
        }
    }
};