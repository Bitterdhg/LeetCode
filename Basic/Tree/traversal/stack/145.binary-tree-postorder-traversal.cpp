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
    vector<int> postorderTraversal(TreeNode* root) {
        // left right middle 
        vector<int> res;
        stack<TreeNode*> st;

        if (root != nullptr) st.push(root);
        while (st.empty() != true) {
            root = st.top();
            st.pop();

            if (root -> left != nullptr) st.push(root -> left);
            if (root -> right != nullptr) st.push(root -> right);
            res.push_back(root -> val);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};