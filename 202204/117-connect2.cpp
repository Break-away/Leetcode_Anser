// 117. 填充每个节点的下一个右侧节点指针 II
// 给定一个二叉树
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
// 如果找不到下一个右侧节点，则将 next 指针设置为 nullptr。
// 初始状态下，所有 next 指针都被设置为 nullptr。

#include <stack>

using std::stack;

// Definition for a Node.
class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
public:
    //超时解答
    // Node* connect(Node* root) 
    // {
    //     stack<Node*> stk;
    //     stk.push(root);
    //     while(!stk.empty())
    //     {
    //         Node* temp=stk.top();
    //         stk.pop();
    //         if (root->left != nullptr)
    //         {
    //             if (root->right != nullptr)
    //             {
    //                 root->left->next = root->right;
    //             }
    //             else if (root->next !=nullptr)
    //             {
    //                 if ( root->next->left != nullptr)
    //                 {
    //                     root->left->next = root->next->left;
    //                 }
    //                 else if (root->next->right != nullptr)
    //                 {
    //                     root->left->next = root->next->right;
    //                 }
    //             }
    //             stk.push(root->left);
    //         }
    //         if (root->right != nullptr)
    //         {
    //             if (root->next !=nullptr)
    //             {
    //                 if (root->next->left != nullptr)
    //                 {
    //                     root->right = root->next->left;
    //                 }
    //                 else if (root->next->right != nullptr)
    //                 {
    //                     root->right = root->next->right;
    //                 }
    //             }
    //             stk.push(root->right);
    //         }
    //     }
    //     return root;
    // }
    Node* connect(Node* root) 
    {
        if (root == nullptr)
        {
            return root;
        }
        Node* temp=root;
        while (temp != nullptr)  //查找各层节点
        {
            Node* dummy=new Node(0);  //用于存放当前node的下一层首节点
            Node* pre=dummy;  //用于搜寻当前node的下一层节点
            while (temp != nullptr)  //查找当前层的各节点
            {
                if (temp->left != nullptr)
                {
                    pre->next = temp->left;
                    pre = pre->next;
                }
                if (temp->right != nullptr)
                {
                    pre->next = temp->right;
                    pre = pre->next;
                }
                temp = temp->next;  //搜索本层的下一节点
            }
            temp = dummy->next;  //上一层节点搜寻完成后，跳转到下一层；
        }
        return root;
    }
};