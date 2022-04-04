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

    // 123. 买卖股票的最佳时机 III
    // 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
    // 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
    // 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    //错误解答
    static bool compare(int a, int b){
        return a>b;
    }
    int maxProfit(vector<int>& prices) {
        int total=0;
        vector<int> profitvec;
        int buy=prices[0], sell=prices[0];
        for (int i=1; i<=prices.size(); ++i)
        {
            int profit=0;
            //核查股票收益是否已经结算
            if (i == prices.size()){
                //如果sell和buy价格不相等则未结算
                if (sell != buy) {
                    profit == sell-buy;
                    profitvec.push_back(profit);
                }
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
                    profit == sell-buy;
                    profitvec.push_back(profit);
                    sell=prices[i];
                    buy=prices[i];
                }
            }
            //如果价格开始上涨，则将sell更新；
            else{
                sell = prices[i];
            }
        }
        std::sort(profitvec.begin(),profitvec.end(),compare);
        return profitvec[0]+profitvec[1];
    }

    //状态转移
    int maxProfit(vector<int>& prices){
        int buy1=-prices[0], sell1=0;
        int buy2=-prices[0], sell2=0;
        for (int i=0; i<prices.size(); ++i)
        {
            buy1 = max(buy1,-prices[i]);
            sell1 = max(sell1,buy1+prices[i]);
            buy2 = max(buy2,sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
    }
};