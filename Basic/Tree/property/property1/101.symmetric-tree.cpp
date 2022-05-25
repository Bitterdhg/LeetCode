// 1. 自解
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
            vector<TreeNode*> res;
            while (len > 0) {
                tmp = que.front();
                if (tmp != nullptr) {
                    res.push_back(tmp);
                    left = que.front() -> left;
                    right = que.front() -> right;
                } else {
                    res.push_back(tmp);
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
            for(int i = 0; i < res.size()/2; i++) {
                TreeNode* left = res[i];
                TreeNode* right = res[res.size() - i - 1];
                if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr)) return false;
                if ((left != nullptr && right!= nullptr) && (left -> val != right -> val)) return false;
            } 
        }
        return true;
    }
};

// 题解：深度优先遍历的应用
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool res;
        res = compare(root -> left, root -> right);
        return res;
    }

public:
    bool compare(TreeNode* leftNode, TreeNode* rightNode) {
        // 终止条件:
        // 有null需要终止（3种），还有就是 val值不等的时候需要终止，val值相等的时候继续遍历
        if (leftNode == nullptr && rightNode == nullptr) {return true;}
        else if (leftNode != nullptr && rightNode == nullptr)  {return false;}
        else if (leftNode == nullptr && rightNode != nullptr)  {return false;}
        else if (leftNode -> val != rightNode -> val)  {return false;}

        bool outside = compare(leftNode -> left, rightNode -> right);
        bool inside = compare(leftNode -> right, rightNode -> left);
        bool res = outside && inside;
        return res;
    }
};
