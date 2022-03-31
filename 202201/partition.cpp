/*给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp1 = ans;
        ListNode* temp2 = new ListNode(-1);
        ListNode* cur = temp2;
        while (head) {
            if (head->val < x) {
                temp1->next = head;
                temp1 = temp1->next;
                head = head->next;
            }
            else {
                temp2->next = head;
                temp2 = temp2->next;
                head = head->next;
            }
        }
        temp2->next = nullptr;
        temp1->next = cur->next;
        return ans->next;
    }
};