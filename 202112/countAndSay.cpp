/* ����һ�������� n �����������еĵ� n �
��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
����Խ����������ɵݹ鹫ʽ����������ַ������У�
countAndSay(1) = "1"
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ���
ǰ�������£�
1.     1
2.     11
3.     21
4.     1211
5.     111221
��һ�������� 1
����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"*/

#include <string>;
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1) return "1";
        string nums = countAndSay(n - 1);
        string ans;
        int start = 0, cur = 0;
        while (cur < nums.size())
        {
            while (nums[cur] == nums[start])
            {
                cur++;
            }
            int num = cur - start;
            ans += to_string(num) + nums[start];
            start = cur;
        }
        return ans;
    }
};