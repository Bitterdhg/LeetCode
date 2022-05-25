//自解：全部遍历一遍
class Solution {
int num = 0;

public:
    int countNodes(TreeNode* root) {
        //前序遍历
        traversal(root);
        return num;
    }

public:
    void traversal(TreeNode* root) {
        if (root == nullptr) {return;}
        else {
            num++;
            traversal(root -> left);
            traversal(root -> right);
        }
    }
};

// 2. 看了题解：优化
class Solution {
public:
    int countNodes(TreeNode* root) {
        return getNum(root);
    }

public:
    int getNum(TreeNode* root) {
        if (root == nullptr) {return 0;}
        else {
            int leftNum = getNum(root -> left);
            int rightNum = getNum(root -> right);
            int rootNum = leftNum + rightNum + 1;
            return rootNum;
        }
    }
};

//3. 【最佳】【递归+特点】看了题解：利用二叉树的特点
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        TreeNode* leftRoot = root -> left;
        TreeNode* rightRoot = root -> right;
        int leftDepth = 1;
        int rightDepth = 1;

        while (leftRoot != nullptr) {
            leftRoot = leftRoot -> left;
            leftDepth++;
        }

        while(rightRoot != nullptr) {
            rightRoot = rightRoot -> right;
            rightDepth++;
        }

        if (leftDepth == rightDepth) {return (int)pow(2, leftDepth) - 1;}
        else {
            return countNodes(root -> left) + countNodes(root -> right) + 1;
        }
    }
};