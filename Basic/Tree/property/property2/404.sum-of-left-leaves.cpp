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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (root == nullptr) return res;
        else {
            traversal(root, res, false);
            return res;
        }
    }

public:
    void traversal(TreeNode* root, int &res, bool isLeftChild) {
        if (root == nullptr) return;
        else {
            // middle
            if (root -> left == nullptr && root -> right == nullptr && isLeftChild) {
                res += root -> val;
            }

            // left
            traversal(root -> left, res, true);

            // right 
            traversal(root -> right, res, false);
        }
    }

};