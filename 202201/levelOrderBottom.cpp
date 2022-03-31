/*给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int num = q.size();
            for (int i = 0; i < num; i++) {
                TreeNode* root = q.front();
                q.pop();
                temp.emplace_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.emplace(ans.begin(), temp);
        }
        return ans;
    }
};