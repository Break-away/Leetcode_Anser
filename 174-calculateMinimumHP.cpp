// 174. 地下城游戏
// 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。
// 我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示
// 骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔
// 法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
// 为了尽快到达公主，骑士决定每次只向右或向下移动一步。

// 解题思路：
// 一、由于经过房间的状态和进入房间前的血量决定了经过房间后的血量，可以通过从后往前计算每一
//     步的最低血量；
// 二、由于要求安全到达最后一间房，则表示经过每一个房间以及到达最后一件房后，其血量要大于0，
//     根据这个要求，可以用一个二维数组after记录经过每一个房间后的最低血量要求，表示经过每
//     一个房间后，其血量要大小，不低于1，从后往前遍历过程中更新为当前查找位置的最低血量要求；
// 三、另外，可以用一个二维数组before表示到达某一房间前的最低血量要求；
// 四、一个房间可以到达其右侧或者下方的房间，并且进入其后房间的血量较低要求，即是经过该房间之后
//     的血量要求；
// 五、通过经过一个房间后的血量，可以计算经过一个房间之前的血量要求，根据该要求，可以确定经过
//     上一个房间之后的血量，从后往前，可以计算出所有房间进入之前的血量before和之后的血量after；

#include <vector>

using std::min;
using std::max;
using std::vector;
// 方案一
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // r，c用于记录输入数组的行和列数
        int r=dungeon.size(), c=dungeon[0].size();
        // 二维数组before用于记录进入一个房间之前的最低血量要求，初始值为1
        vector<vector<int>> before(r,vector<int>(c,1));
        // 二维数组after用于记录离开一个房间时的最低血量要求，初始值为INT_MAX
        vector<vector<int>> after(r,vector<int>(c,INT_MAX));
        // 离开最后一个房间的最低血量要求为1
        after[r-1][c-1] = 1;
        // 从后往前遍历每一个房间
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                // 根据当前位置after，以及输入房间状态，计算对应位置的before
                // 如果计算所得的before小于1，说明进入该房间之前只需满足最低血量1即可
                if (after[i][j] - dungeon[i][j] > 1){
                    before[i][j] = after[i][j] - dungeon[i][j];
                }
                // 根据当前位置before，计算当前位置左侧和上部房间的after
                // 由于该处房间可以进入两个房间，故可以从两个后面的房间before，推测前部房间after
                // 上部房间after，取现有值和推测值中的较小值
                if (i-1 >= 0) after[i-1][j] = min(after[i-1][j], before[i][j]);
                // 左侧房间after，取现有值和推测值中的较小值
                if (j-1 >= 0) after[i][j-1] = min(after[i][j-1], before[i][j]);
            }
        } 
        // 返回before[0][0]
        return before[0][0];
    }
};

//方案一优化
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // r，c用于记录输入数组的行和列数
        int r=dungeon.size(), c=dungeon[0].size();
        // before用于记录进入一个房间之前的最低血量要求，初始值为1
        int before = 1;
        // after用于记录离开一个房间时的最低血量要求，初始值为1
        vector<vector<int>> after(r,vector<int>(c,INT_MAX));
        // 离开最后一个房间的最低血量要求为1
        after[r-1][c-1] = 1;
        // 从后往前遍历每一个房间
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                // 根据当前位置after，以及输入房间状态，计算对应位置的before
                // 如果计算所得的before小于1，说明进入该房间之前只需满足最低血量1即可
                before = max(1,after[i][j] - dungeon[i][j]);
                // 根据当前位置before，计算当前位置左侧和上部房间的after
                // 由于该处房间可以进入两个房间，故可以从两个后面的房间before，推测前部房间after
                // 上部房间after，取现有值和推测值中的较小值
                if (i-1 >= 0) after[i-1][j] = min(after[i-1][j], before);
                // 左侧房间after，取现有值和推测值中的较小值
                if (j-1 >= 0) after[i][j-1] = min(after[i][j-1], before);
            }
        } 
        // 返回before[0][0]
        return before;
    }
};