/*������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������*/

#include <vector>;

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 0) return 0;
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1) f[i] = 1;
            else if (i == 2) f[i] = 2;
            else f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};