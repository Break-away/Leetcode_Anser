// 160. 相交链表
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表不存在相交节点，返回 null 。
// 题目数据 保证 整个链式结构中不存在环。
// 注意，函数返回结果后，链表必须 保持其原始结构 。

#include <unordered_set>
using std::unordered_set;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
    };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> node_set;
        while (headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (node_set.count(headB)) {
                return headB;
            }
            headB  = headB->next;
        }
        return nullptr;
    }
};