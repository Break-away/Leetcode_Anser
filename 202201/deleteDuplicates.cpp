/*存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，
只保留原始链表中 没有重复出现 的数字。
返回同样按升序排列的结果链表。*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(-1);
        ans->next = head;
        ListNode* temp = ans;
        while (temp->next) {
            if (temp->next->next && temp->next->next->val == temp->next->val) {
                int x = temp->next->val;
                while (temp->next && temp->next->val == x) {
                    temp->next = temp->next->next;
                }
            }
            else temp = temp->next;
        }
        return ans->next;
    }
};