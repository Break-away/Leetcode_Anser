#include <deque>;
#include<vector>;
#include <algorithm>;
#include <iostream>;

using namespace std;
/*�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��*/
/*�˽�ᵼ�³���int��Χ*/

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string ans;
        if (num1 == "0" || num2 == "0") return "0";
        long long k = 1, res = 0;
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            long n = 1;
            for (int i = num1.size() - 1; i >= 0; i--)
            {
                res += (num1.at(i) - '0') * (num2.at(j) - '0') * k * n;
                n *= 10;
            }
            k *= 10;
        }
        deque<int> temp;
        while (res > 0)
        {
            int num = res % 10;
            res = res / 10;
            temp.push_front(num);
        }
        for (auto i = temp.begin(); i < temp.end(); i++)
        {
            ans += *i + '0';
        }
        return ans;
    }
};