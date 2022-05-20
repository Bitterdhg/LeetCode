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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

public:
    void traversal(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        } else {
            // left
            traversal(root -> left, res);

            // middle
            res.push_back(root -> val);
            
            // right
            traversal(root -> right, res);
        }
    }
};