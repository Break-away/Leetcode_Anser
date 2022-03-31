/*存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* ans = head;
        while (head) {
            while (head->next && head->next->val == head->val) {
                head->next = head->next->next;
            }
            head = head->next;
        }
        return ans;
    }
};