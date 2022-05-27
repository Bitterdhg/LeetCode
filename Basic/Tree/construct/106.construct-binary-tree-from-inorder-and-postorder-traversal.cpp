// 看了思路 自解
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
public:
    TreeNode* build(vector<int> in, vector<int> post) {
        if (in.size() == 0 && post.size() == 0) {
            return nullptr;
        }
        else {
            int len = post.size(); 
            int rootVal = post[len - 1]; 
            int rootPos = getPosisition(in, rootVal); 
            vector<int> leftIn;
            vector<int> rightIn;
            for (int i = 0; i < rootPos; i++) {
                leftIn.push_back(in[i]); 
            }
            for (int i = rootPos + 1; i < len; i++) {
                rightIn.push_back(in[i]); 
            }
            // middle
            TreeNode* root = new TreeNode(0);
            root -> val = rootVal;
            // left
            vector<int> leftPost = getPost(post, leftIn); 
            root -> left = build(leftIn, leftPost); 
            //right
            vector<int> rightPost = getPost(post, rightIn); 
            root -> right = build(rightIn, rightPost); 
            return root;
        }
    }

    int getPosisition(vector<int> in, int root) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == root) return i;
        }
        return -1;
    }

    vector<int> getPost(vector<int> mom, vector<int> sub) {
        vector<int> post;
        int index[6001];
        // index 初始化
        for (int i = 0; i < 6001; i++) {
            index[i] = 0;
        }
        for (int i = 0; i< sub.size(); i++) {
            index[sub[i] + 3000] = 1;
        }

        for (int i = 0; i < mom.size(); i++) {
            if (index[mom[i]+3000] == 1) post.push_back(mom[i]);
        }
        return post;
    }
};

// 看了题解

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
public:
    TreeNode* build(vector<int> in, vector<int> post) {
        if (in.size() == 0 && post.size() == 0) {
            return nullptr;
        }
        else {
            int len = post.size(); 
            int rootVal = post[len - 1]; 
            int rootPos = getPosisition(in, rootVal); 
            vector<int> leftIn;
            vector<int> rightIn;
            // 得到 中序的左
            for (int i = 0; i < rootPos; i++) {
                leftIn.push_back(in[i]); 
            }
            // 得到 中序的右
            for (int i = rootPos + 1; i < len; i++) {
                rightIn.push_back(in[i]); 
            }
            // middle
            TreeNode* root = new TreeNode(0);
            root -> val = rootVal;

            // left
            // vector<int> leftPost(post.begin(), post.begin()+leftIn.size()-1); 会报错 因为会有null的可能性
            vector<int> leftPost;
            for (int i = 0; i < leftIn.size(); i++) {
                leftPost.push_back(post[i]);
            }
            root -> left = build(leftIn, leftPost); 

            //right
            vector<int> rightPost;
            // vector<int> rightPost(post.begin()+leftIn.size(), post.end()-1); 会报错 因为会有null的可能性
            for (int i = 0; i < rightIn.size(); i++) {
                rightPost.push_back(post[leftIn.size() + i]);
            }
            root -> right = build(rightIn, rightPost); 
            return root;
        }
    }

    int getPosisition(vector<int> in, int root) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == root) return i;
        }
        return -1;
    }
};