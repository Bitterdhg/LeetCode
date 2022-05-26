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
    int findBottomLeftValue(TreeNode* root) {
        int len = 1;
        int res = 0;
        bool init = true;
        TreeNode* tmp = nullptr;
        queue<TreeNode*> que;

        que.push(root);

        while (que.empty() != true) {
            while (len > 0) {
                tmp = que.front();
                if (init == true) {
                    res = tmp -> val;
                    init = false;
                }

                if (tmp -> left != nullptr) {que.push(tmp -> left);}
                if (tmp -> right != nullptr) {que.push(tmp -> right);}
                que.pop();
                len --;
            }

            init = true;
            len = que.size();
        }
        return res;
    }
};