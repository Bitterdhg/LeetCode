//1. 自解：宽度优先遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 层级遍历
        queue<TreeNode*> que;
        int len = 1;
        int depth = 1;

        if (root == nullptr) return 0; 

        que.push(root);
        while (que.empty() != true) {
            TreeNode* tmp;
            while (len > 0) {
                tmp = que.front();

                if (tmp -> left == nullptr && tmp -> right == nullptr) {
                    return depth;
                } else {
                    if (tmp -> left != nullptr) que.push(tmp -> left);
                    if (tmp -> right != nullptr) que.push(tmp -> right);
                }
                que.pop();
                len--;
            }
            depth++;
            len = que.size();
        }
        return depth;
    }
};

