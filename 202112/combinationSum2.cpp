#include <vector>;
#include <algorithm>;

using namespace std;

/*给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。*/
/*错误解法：答案包含重复解*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;
    void trackback(vector<int>& candidates, int index, int target)
    {
        if (target == 0)
        {
            ans.push_back(comb);
            return;
        }
        if (candidates.size() == index)
        {
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0)
            {
                comb.push_back(candidates[i]);
                trackback(candidates, i + 1, target - candidates[i]);
                comb.pop_back();
            }
        }
    };

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        trackback(candidates, 0, target);
        return ans;
    }
};

/*正确解法*/
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num : candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            }
            else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};