# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
vector<string> vocab;
string path;
vector<string> res;

public:
    vector<string> letterCombinations(string digits) {
        map(digits);
        if (digits == "") {
            return res;
        }
        backtracking(vocab.size(), 0);
        return res;
    }

void map(string digits) {
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] == '2') {
            string tmp;
            tmp = "abc";
            vocab.push_back(tmp);
        }
        if (digits[i] == '3') {
            string tmp;
            tmp = "def";
            vocab.push_back(tmp);
        }
        if (digits[i] == '4') {
            string tmp;
            tmp = "ghi";
            vocab.push_back(tmp);
        }
        if (digits[i] == '5') {
            string tmp;
            tmp = "jkl";
            vocab.push_back(tmp);
        }
        if (digits[i] == '6') {
            string tmp;
            tmp = "mno";
            vocab.push_back(tmp);
        }
        if (digits[i] == '7') {
            string tmp;
            tmp = "pqrs";
            vocab.push_back(tmp);
        }
        if (digits[i] == '8') {
            string tmp;
            tmp = "tuv";
            vocab.push_back(tmp);
        }
        if (digits[i] == '9') {
            string tmp;
            tmp = "wxyz";
            vocab.push_back(tmp);
        }
    }
}

void backtracking(int vocab_num, int vocabIdx) {
    // stop
    if (path.size() == vocab_num) {
        res.push_back(path);
        return;
    }
    // recursion one-layer
    else {
        for (int i = 0; i < vocab[vocabIdx].length(); i++) {
            path.push_back(vocab[vocabIdx][i]);
            backtracking(vocab_num, vocabIdx+1);
            path.pop_back();
        }
    }
}
};

int main() {
    Solution solution = Solution();
    string digits = "23";
    vector<string> res = solution.letterCombinations(digits);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
        cout << endl;
    }
}