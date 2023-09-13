// 168. Excel表列名称
// 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
// 例如：
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

//解题思路：属于26进制，但是对于26的整数倍数字表达方式又与26进制不同
#include <string>
using std::string;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        if (columnNumber <= 26) {
            ans += 'A'+columnNumber-1;
            return ans;
        }
        while (columnNumber > 26){
            int index = columnNumber % 26;
            if (index != 0) {
                ans += 'A' + (columnNumber % 26 - 1);
                columnNumber /= 26;
            }
            else{
                ans += 'Z';
                columnNumber = (columnNumber / 26) -1;
            }
            
        }
        ans += 'A' + columnNumber - 1;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};