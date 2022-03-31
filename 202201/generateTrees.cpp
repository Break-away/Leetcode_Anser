/*����һ������ n ���������ɲ����������� n ���ڵ�����ҽڵ�ֵ�� 1 �� n 
������ͬ�Ĳ�ͬ ���������� �����԰� ����˳�� ���ش𰸡�*/

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