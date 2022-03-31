/*给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;
        while (!q.empty()) {
            vector<int> temp;
            int num = q.size();
            for (int i = 0; i < num; i++) {
                root = q.front();
                q.pop();
                if (left) temp.emplace_back(root->val);
                else temp.emplace(temp.begin(), root->val);
                if (root->left != nullptr) q.push(root->left);
                if (root->right != nullptr) q.push(root->right);
            }
            left = !left;
            ans.emplace(ans.end(), temp);
        }
        return ans;
    }
};