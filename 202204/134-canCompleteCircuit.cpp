// 134. 加油站
// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站
// 需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
// 给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时
// 加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using std::vector;
using std::accumulate;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //如果gas的总油量小于cost总油量，则一定不能行驶一周
        if (accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
            return -1;
        }
        int n = gas.size();
        //依次判断能否从各个加油站出发
        int i=0;
        while (i<n){
            //如果当前加油站的加油量大于等于到达下一加油站所有的油量
            //则有可能从当前加油站出发完成一周行驶，否则一定不能
            if (gas[i] >= cost[i]){
                //表示在某个加油站时已加的油总量
                int sumofgas = 0;
                //表示从出发加油站到下一加油站所需的总油量
                int sumofcost = 0;
                //用于判断从当前站点出发走了多少个加油站
                int cnt = 0;
                //检验从当前站点出发能否行驶一周
                while (cnt < n){
                    int l = (i+cnt) % n;
                    sumofgas += gas[l];
                    sumofcost += cost[l];
                    if (sumofgas < sumofcost) break;
                    cnt++;
                }
                //如果走了n个加油站则表示已完成一周行驶
                if (cnt == n) return i;
                //如果从i走cnt个加油站都没法行驶一周
                //则从i到之后的cnt个肯定也不能行驶一周
                //直接跳过之后的cnt个加油站
                else i=i+cnt;
            }
            i++;
        }
        return -1;
    }
};