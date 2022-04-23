// 171. Excel 表列序号
// 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。
// 返回 该列名称对应的列序号 。
// 例如：
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

#include <string>
using std::string;

// 解题思路：从前往后取输入字符串的各个字符，计算每个字符代表的数字
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto const ch : columnTitle){
            ans = 26 * ans + (ch - 'A' + 1);
        }
        return ans;
    }
};