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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        bool res = false;
        traversal(root, root -> val, targetSum, res);
        return res;
    }

public:
    void traversal(TreeNode* root, int sum, int target, bool &res) {
        if (res == true) {return;}
        else {
            // stop confdition
            if (root -> left == nullptr && root -> right == nullptr) {
                if (sum == target) {res = true; return;}
                else {return;}
            // move
            } else {
                // left
                if (root -> left != nullptr) {traversal(root -> left, sum + root -> left -> val, target, res);} // sum隐藏着回溯
                if (root -> right != nullptr) {traversal(root -> right, sum + root -> right -> val, target, res);} // sum隐藏着回溯
                // middle
            } 
        }
    }
};