// 【漂亮！】只遍历一遍
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int res = getHeight(root);
        if (res == -1) return false;
        else {
            return true;
        }
    }

public:
    int getHeight(TreeNode* root) {
        if (root == nullptr) {return 0;}
        else {
            // 后序
            int leftHeight = getHeight(root -> left);
            int rightHeight = getHeight(root -> right);
            if (leftHeight == -1 || rightHeight == -1) return -1;
            else {
                if (abs(leftHeight - rightHeight) > 1) {
                    return -1;
                } else {
                    return max(leftHeight, rightHeight) + 1;
                }
            }
        }
    }
};