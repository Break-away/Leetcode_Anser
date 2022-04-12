// 141. 环形链表
// 给你一个链表的头节点 head ，判断链表中是否有环。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中
// 的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链
// 表的实际情况。
// 如果链表中存在环，则返回 true 。 否则，返回 false 

#include <unordered_set>

using std::unordered_set;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> node;
        while (head){
            if (node.count(head)){
                return true;
            }
            node.insert(head);
            head=head->next;
        }
        return false;
    }
    // 142. 环形链表 II
    // 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 
    // 如果链表无环，则返回 null。
    //解题思路：从链表头开始，将链表中的所有节点都放入hash表中，如果链表中有环，
    //当链表到达末尾后，会再次进入环中进行循环，此时的节点即是入环的第一个节点，且此时
    //hash表中已有该节点，所以hash表中第一个重复出现的节点即是入环的第一个节点；
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> node;
        while (head){
            if (node.count(head)){
                return head;
            }
            node.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};