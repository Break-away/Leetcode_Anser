/*������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
����԰� �κ�˳�� ���ش𰸡�*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void findcombine(int l, int r, int k) {
        if (r - l + 1 < k) return;
        if (k == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = l; l <= r; l++) {
            temp.push_back(l);
            findcombine(l + 1, r, k - 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        findcombine(1, n, k);
        return ans;
    }
};