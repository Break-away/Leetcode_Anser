/*给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 
互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。*/

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> ans;
        if (l > r) return vector<TreeNode*>{nullptr};
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = generate(l, i - 1);
            vector<TreeNode*> right = generate(i + 1, r);
            for (auto& l : left) {
                for (auto& r : right) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    ans.emplace_back(cur);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{nullptr};
        return generate(1, n);
    }
};