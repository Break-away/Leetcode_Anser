/*����һ���������ĸ��ڵ� root ���������� ���� ������*/

#include <vector>
#include <stack>

using namespace std;

/*�������ṹ��*/
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 /*����������ݹ�*/
class Solution {
public:
    void midtravel(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        midtravel(root->left, ans);
        ans.push_back(root->val);
        midtravel(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        midtravel(root, res);
        return res;
    }
};


/*�������������*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            TreeNode* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            root = top->left;
        }

        return res;
    }
};

/*ǰ��������ݹ�*/
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

/*ǰ�����������*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};

/*����������ݹ�*/
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.emplace(ans.end(), root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

/*�������������*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* pre;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (!root->right || root->right == pre) {
                ans.emplace(ans.end(), root->val);
                pre = root;
                root = nullptr;
            }
            else {
                stk.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};
