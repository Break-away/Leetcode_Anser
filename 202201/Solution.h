#pragma once
#include <vector>
#include <utility>
#include <stack>

using std::stack;
using std::vector;
using std::pair;
using std::swap;
//注释： 先CTRL + K，然后CTRL + C
//取消注释： 先CTRL + K，然后CTRL + U

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    //恢复二叉搜索树：给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。
    //请在不改变其结构的情况下，恢复这棵树 。
    //方法一:
    //将二叉树转换为数组；
    void inorder(TreeNode* root, std::vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    //查找二叉树转换的数组中的错误位置；
    pair<int, int> FindTwoSwaped(vector<int>& nums) {
        int n = nums.size();
        int index1 = -1, index2 = -2;
        for (int i = 0; i < n-1; i++) {
            if (nums[i + 1] < nums[i]) {
                index2 = i + 1;
                if (index1 == -1) index1 = i;
                else break;
            }
        }
        int x = nums[index1], y = nums[index2];
        return std::make_pair(x, y);
    }
    //交换二叉树中的错误位置；
    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = (r->val == x ? y : x);
                if (--count == 0) return;
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }
    //执行程序；
    void recoverTree1(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int,int> swaped=FindTwoSwaped(nums);
        recover(root, 2, swaped.first, swaped.second);
    }
    //方法二：
    void recoverTree2(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* pred = nullptr;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred!=nullptr && root->val < pred->val) {
                y = root;
                if (x == nullptr) x = pred;
                else break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
    //方法三：
    void recoverTree3(TreeNode* root) {
        TreeNode* x = nullptr, * y = nullptr, * pred = nullptr, * predecessor = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
