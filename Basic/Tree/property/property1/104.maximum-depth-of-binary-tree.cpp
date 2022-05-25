// 1. 看了题解 : 递归的简易方式

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }

public:
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        else {
            int leftDepth = getDepth(root -> left);
            int rightDepth = getDepth(root -> right);
            int rootDepth = max(leftDepth, rightDepth) + 1;
            return rootDepth;
        }
    }
};

//2. 看了题解：层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* tmp;
        int depth = 0;
        int len = 1;

        if (root == nullptr) {return 0;}
        else {
            que.push(root);
            while (que.empty() != true) {
                while (len > 0) {
                    tmp = que.front();
                    if (tmp -> left != nullptr) que.push(tmp -> left);
                    if (tmp -> right != nullptr) que.push(tmp -> right);
                    que.pop();
                    len--;
                }
                depth++;
                len = que.size();
            }
        }
        return depth;
    }
};