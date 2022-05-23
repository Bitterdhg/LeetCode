
// 递归
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
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
public:
    void traversal(TreeNode* root) {
        if (root == nullptr) {return;}
        else {
            swap(root -> left, root -> right);
            if (root -> left != nullptr) traversal(root -> left);
            if (root -> right != nullptr) traversal(root -> right);
        }
    }
};

//迭代

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
    TreeNode* invertTree(TreeNode* root) {
        int len = 1;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while(que.empty() != true) {
            TreeNode* tmp;
            while (len > 0) {
                tmp = que.front();
                swap(tmp -> left, tmp -> right);
                if (tmp -> left != nullptr) que.push(tmp -> left);
                if (tmp -> right != nullptr) que.push(tmp -> right);
                que.pop();
                len--;
            }
            len = que.size();
        }
        return root;
    }
};