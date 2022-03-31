/*����������ĸ��ڵ� root ��������ڵ�ֵ �Ե����ϵĲ������ ��
��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����*/

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