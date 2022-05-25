//【隐藏版回溯】自解：前序遍历
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        searchPath(root, path, res);
        return res;
    }

public:
    void searchPath(TreeNode* root, vector<int> path, vector<string>&res) {
        if (root -> left == nullptr && root -> right == nullptr) {
            path.push_back(root -> val);
            string tmp;
            tmp += to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                tmp += "->";
                tmp += to_string(path[i]);
            }
            res.push_back(tmp);
            return;
        } else {
            // 前序遍历
            //middle
            path.push_back(root -> val);
            // left
            if (root -> left != nullptr) {
                searchPath(root -> left, path, res);
                // 这里隐藏着 回溯（即path.pop_back(); ）因为 我写的不是引用，
//故 等它递归结束后，path，还是path
            }
            //right
            if (root -> right != nullptr) {
                searchPath(root -> right, path, res);
            } 
        }
    }
};

//【推荐 明确版回溯】题解：前序遍历
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        searchPath(root, path, res);
        return res;
    }

public:
    void searchPath(TreeNode* root, vector<int> &path, vector<string>&res) {
        // end condition
        if (root -> left == nullptr && root -> right == nullptr) {
            path.push_back(root -> val);
            string tmp = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                tmp += "->";
                tmp += to_string(path[i]);
            }
            res.push_back(tmp);
        }
        // move
        // pre   middle left right
        else {
            // middle
            path.push_back(root -> val);
            // left
            if (root -> left != nullptr) {
                searchPath(root -> left, path, res);
                path.pop_back(); // 回溯
            }
            if (root -> right != nullptr) {
                searchPath(root -> right, path, res);
                path.pop_back(); // 回溯
            }
        }
    }
};