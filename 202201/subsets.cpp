/*����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��*/
#include <vector>;

using namespace std

class Solution {
public:
    vector<vector<int>> ans{ vector<int>() };
    vector<int> temp;

    void dfs(vector<int>& nums, int min, int max, int k) {
        if (max - min + 1 <= k - temp.size()) return;
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[min]);
        dfs(nums, min + 1, max, k);
        temp.pop_back();
        dfs(nums, min + 1, max, k);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            dfs(nums, 0, n, i);
        }
        return ans;
    }
};