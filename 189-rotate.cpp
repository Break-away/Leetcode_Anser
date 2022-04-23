// 189. 轮转数组
// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

//脑残解法
#include <vector>
using std::vector;
struct  ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int _val):val(_val),next(nullptr){};
    ListNode(int _val, ListNode* _next):val(_val),next(_next){};
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return ;
        k = k % n;
        ListNode* head = new ListNode(nums[0]);
        ListNode* temp = head;
        for (int i=1; i<n; i++){
            ListNode* node = new ListNode(nums[i]);
            head->next = node;
            head = head->next;
        }
        head->next = temp;
        while (temp){
            if (temp->val != nums[k]){
                continue;
            }
            for (int i=0; i<n; i++){
                nums[i] = temp->val;
                temp = temp->next;
            }
        }
        return ;
    }
};

//官方解答
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};

//官方解答
class Solution {
public:
    inline int gcd(int a,int b) {
        int r;
        while(b>0) {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    };

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                std::swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};
