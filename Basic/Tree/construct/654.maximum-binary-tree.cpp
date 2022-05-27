//自解
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums);
    }

public:
    TreeNode* build(vector<int> nums) {
        // stop condition
        if (nums.size() == 0) return nullptr;
        if (nums.size() == 1) {
            TreeNode* root = new TreeNode(0);
            root -> val = nums[0];
            return root;
        }

        // move
        int index = -1;
        int max = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }

        vector<int> leftTree;
        vector<int> rightTree;
        for (int i = 0; i < index; i++) leftTree.push_back(nums[i]);
        for (int i = index+1; i < nums.size(); i++) rightTree.push_back(nums[i]);

        // middle
        TreeNode* root = new TreeNode(0);
        root -> val = max;
        
        //left
        root -> left = build(leftTree);

        // right 
        root -> right = build(rightTree);

        return root;
    }
};