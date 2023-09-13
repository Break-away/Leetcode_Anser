#pragma once
#include <vector>
#include <utility>
#include <stack>

using std::stack;
using std::vector;
using std::pair;
using std::swap;
//ע�ͣ� ��CTRL + K��Ȼ��CTRL + C
//ȡ��ע�ͣ� ��CTRL + K��Ȼ��CTRL + U

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
    //�ָ���������������������������ĸ��ڵ� root �������е� ǡ�� �����ڵ��ֵ������ؽ�����
    //���ڲ��ı���ṹ������£��ָ������ ��
    //����һ:
    //��������ת��Ϊ���飻
    void inorder(TreeNode* root, std::vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    //���Ҷ�����ת���������еĴ���λ�ã�
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
    //�����������еĴ���λ�ã�
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
    //ִ�г���
    void recoverTree1(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int,int> swaped=FindTwoSwaped(nums);
        recover(root, 2, swaped.first, swaped.second);
    }
    //��������
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
    //��������
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
