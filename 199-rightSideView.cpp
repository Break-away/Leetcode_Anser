// 199. 二叉树的右视图
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，
// 按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

#include <vector>
#include <queue>
using std::queue;
using std::vector;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int que_size = que.size();
            //层序遍历，每一层的最后一个node->val加入ans即可
            for (int i=0; i< que_size; i++){
                TreeNode* node = que.front();
                que.pop();
                if (i == que_size-1){
                    if (node->left != nullptr) que.push(node->left);
                    if (node->right != nullptr) que.push(node->right);
                    ans.emplace_back(node->val);
                }
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
        }
        return ans;
    }
};