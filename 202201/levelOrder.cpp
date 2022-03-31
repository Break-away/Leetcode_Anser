/*����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
                if (root->left != nullptr) q.push(root->left);
                if (root->right != nullptr) q.push(root->right);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};