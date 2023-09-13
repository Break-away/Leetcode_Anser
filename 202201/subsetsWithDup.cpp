/*����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�*/

#include <vector>;
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans{};
    vector<int> combination{};

    void dfs(bool choosepre, vector<int>& nums, int i, int n) {
        if (i == n) {
            ans.push_back(combination);
            return;
        }
        dfs(false, nums, i + 1, n);
        if (!choosepre && i > 0 && nums[i] == nums[i - 1]) return;
        combination.emplace_back(nums[i]);
        dfs(true, nums, i + 1, n);
        combination.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        dfs(false, nums, 0, len);
        return ans;
    }
};