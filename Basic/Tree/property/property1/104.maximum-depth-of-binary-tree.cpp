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
    int maxDepth(TreeNode* root) {
        int depth = 1;
        if (root == nullptr) return 0;
        else {
            depth = seachDepth(root, depth);
            return depth;
        }
        
    }
public:
    int seachDepth(TreeNode* root, int depth) {
        if (root -> left == nullptr && root -> right == nullptr) {
            return depth;
        } else {
            int leftDepth = 0;
            int rightDepth = 0;
            if (root -> left != nullptr && root -> right == nullptr) {
                return seachDepth(root -> left, depth + 1);
            }
            else if (root -> left == nullptr && root -> right != nullptr) {
                return seachDepth(root -> right, depth + 1);
            }
            else {
                leftDepth = seachDepth(root -> left, depth + 1);
                rightDepth = seachDepth(root -> right, depth + 1);
                return max(leftDepth, rightDepth);
            }
        }
    }
};