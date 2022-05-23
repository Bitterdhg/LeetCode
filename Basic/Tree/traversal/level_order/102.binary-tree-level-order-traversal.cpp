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

 // 思路 : 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        // 1. init
        int len = 1;
        if (root != nullptr)que.push(root);
        // 2. 
        while (que.empty() != true) {
            vector<int> tmp;
            while ( len > 0) {
                tmp.push_back(que.front() -> val);
                if (que.front() -> left != nullptr) { que.push(que.front() -> left); }
                if (que.front() -> right != nullptr) { que.push(que.front() -> right); }
                que.pop();
                len --;
            }
            len = que.size();
            res.push_back(tmp);
        }
        return res;
    }
};