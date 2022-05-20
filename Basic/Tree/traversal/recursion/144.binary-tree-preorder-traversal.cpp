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
    vector<int> preorderTraversal(TreeNode* root) {
        // 中左右
        vector<int> res;
        traversal(root, res);
        return res;
    }
public:
    void traversal(TreeNode* cur, vector<int> &res) {
        if (cur == nullptr) {
            return;
        } else {
            // middle
            res.push_back(cur -> val);
            // left
            traversal(cur -> left, res);
            // right
            traversal(cur -> right, res);
        }
    }
};