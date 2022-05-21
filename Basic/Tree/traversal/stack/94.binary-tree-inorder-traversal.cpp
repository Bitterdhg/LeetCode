// 自己的版本 没写出来
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // left middle right
        vector<int> res;
        stack<TreeNode*> st;

        if (root != nullptr) {st.push(root);}
        
        while (st.empty() != true) {
            root = st.top();
            st.pop();

            // left 2 down
            while (root != nullptr) {
                st.push(root);
                root = root -> left;
            }
            
            // 回溯
            // middle
            res.push_back(st.top() -> val);
            st.pop();          

            // right
            if (root -> right != nullptr) {
                st.push(root -> right);
                root = root -> right;
            }
        }
        return res;
    }
};

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
        // left middle right
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        // 两个循环变成一个 更直接的说 用一个 || 将条件转化 很聪明
        while (cur != nullptr || st.empty() != true) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur -> left;
            } else {
                cur = st.top();
                res.push_back(cur -> val); // middle or 之前的left
                st.pop();
                cur = cur -> right;
            }
        }
        return res;
    }
};