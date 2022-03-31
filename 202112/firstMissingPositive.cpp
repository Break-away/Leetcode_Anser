#include <vector>;
#include <iostream>;

using namespace std;
/*����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) < n + 1)
            {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) return i + 1;
        }
        return ans;
    }
};

void main()
{
    vector <int> input0{ 1,2,0 };
    Solution solution;
    int ans=solution.firstMissingPositive(input0);
    cout << "the ans is" << ans << endl;
}