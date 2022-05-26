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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        if (root == nullptr) {return res;}
        traversal(root, root -> val, targetSum, path, res);
        return res;
    }

public:
    void traversal(TreeNode* root, int sum, int target, vector<int> path, vector<vector<int>> &res) {
        if (root -> left == nullptr && root -> right == nullptr) {
            if (sum == target) {
                path.push_back(root -> val);
                res.push_back(path);
            }
            else return;
        } else {
            //middle
            path.push_back(root -> val);
            if (root -> left != nullptr) {            
                traversal(root -> left, sum + root -> left -> val, target, path, res);
            }
            if (root -> right != nullptr) {
                traversal(root -> right, sum + root -> right -> val, target, path, res);
            }
        }
    }

};