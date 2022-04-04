// 121. 买卖股票的最佳时机
// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
// 设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    //错误解答
    // int maxProfit(vector<int>& prices) {
    //     int maximum=INT_MIN;
    //     int left=0, right=prices.size()-1;
    //     while (left < right)
    //     {
    //         maximum = max(maximum,prices[right]-prices[left]);
    //         if (prices[left+1] < prices[left]) left = left+1;
    //         else right = right-1;
    //     }
    //     return maximum;
    // }

    int maxProfit(vector<int>& prices){
        int minprice=INT_MAX, maxProfit=0;
        for (auto price : prices){
            maxProfit = max(maxProfit, price-minprice);
            minprice = min(minprice,price);
        }
        return maxProfit;
    }
};