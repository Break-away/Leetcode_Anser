/*����������ĸ��ڵ� root ��������ڵ�ֵ�� ����β������ ��
�����ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���*/

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