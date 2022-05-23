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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* tmp;
        TreeNode* left;
        TreeNode* right;
        int len = 1;
        if (root != nullptr){que.push(root);}

        while (que.empty() != true) {
            vector<int> res;
            while (len > 0) {
                tmp = que.front();
                if (tmp != nullptr) {
                    res.push_back(tmp -> val);
                    left = que.front() -> left;
                    right = que.front() -> right;
                } else {
                    res.push_back(-101);
                    que.pop();
                    len--;
                    continue;
                }

                if ((left != nullptr) || (left == nullptr && tmp != nullptr)) {
                    que.push(left); 
                }
                if (right != nullptr || (right == nullptr && tmp != nullptr)) { 
                    que.push(right); 
                }

                que.pop();
                len--;
            }
            len = que.size();
            // for(int i = 0; i < res.size(); i++) {
            //     cout << res[i] << " ";
            // } 
            for(int i = 0; i < res.size()/2; i++) {
                if (res[i] != res[res.size() - i - 1]) return false;
            } 
        }
        return true;
    }
};