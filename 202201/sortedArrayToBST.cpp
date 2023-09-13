/*给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。*/
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