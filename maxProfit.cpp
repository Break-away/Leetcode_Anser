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

    //121
    int maxProfit(vector<int>& prices){
        int minprice=INT_MAX, maxProfit=0;
        for (auto price : prices){
            maxProfit = max(maxProfit, price-minprice);
            minprice = min(minprice,price);
        }
        return maxProfit;
    }

    // 122. 买卖股票的最佳时机 II
    // 给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
    // 在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 
    // 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
    // 返回 你能获得的 最大 利润 。

    //自解
    int maxProfit(vector<int>& prices) {
        int total=0;
        int buy=prices[0], sell=prices[0];
        for (int i=1; i<=prices.size(); ++i)
        {
            //核查股票收益是否已经结算
            if (i == prices.size()){
                //如果sell和buy价格不相等则未结算
                if (sell != buy) total += sell-buy;
            }
            //如果价格开始下降，则有两种情况：
            else if (prices[i] <= sell){
                //第一种情况：股票价格一直下跌，则将buy和sell价格调整为较低价格
                if (sell == buy){
                    sell=prices[i];
                    buy=prices[i];
                }
                //第二种情况：股票先上涨，后下降，则将此前的收益兑现，
                //并将buy和sell价格调整为今日价格
                else{
                    total += sell-buy;
                    sell=prices[i];
                    buy=prices[i];
                }
            }
            //如果价格开始上涨，则将sell更新；
            else{
                sell = prices[i];
            }
        }
        return total;
    }

    //动态规划
    int maxProfit(vector<int>& prices){
        //dp0表示当天交易完成后手里没有股票的利润；
        //dp1表示当天交易完成后手里有股票的利润；
        int n=prices.size();
        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i=1; i<n; ++i){
            int newdp0 = max(dp0,dp1+prices[i]);
            int newdp1 = max(dp1,dp0-prices[i]);
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return dp0;
    }

    //贪心算法
    int maxProfit(vector<int>& prices){
        int total=0;
        int n=prices.size();
        for (int i=1; i<n; ++i){
            //如果当天价格比前一天价格高，则默认前一天已购买股票，今天卖出
            total += max(0,prices[i]-prices[i-1]);
        }
        return total;
    }
};