/*����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�*/

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