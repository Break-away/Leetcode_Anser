/*����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������
�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������*/
#include <vector>

using namespace std;

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
    TreeNode* sort(vector<int>& nums, int min, int max) {
        if (max < min) return nullptr;
        int mid = min + (max - min) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (min == max) return root;
        root->left = sort(nums, min, mid - 1);
        root->right = sort(nums, mid + 1, max);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
};