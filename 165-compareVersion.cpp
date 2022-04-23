// 165. 比较版本号
// 给你两个版本号 version1 和 version2 ，请你比较它们。
// 版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。
// 每个修订号由多位数字组成，可能包含前导零 。每个版本号至少包含一个字符。
// 修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，
// 以此类推。例如，2.5.33 和 0.1 都是有效的版本号。
// 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，
// 只需比较忽略任何前导零后的整数值。也就是说，修订号 1 和修订号 001 相等 。
// 如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小于版本 1.1 ，
// 因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。
// 返回规则如下：
// 如果 version1 > version2 返回 1，
// 如果 version1 < version2 返回 -1，
// 除此之外返回 0。

#include <string>
using std::string;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // 如果v1和v2相等，则直接返回0
        if (version1 == version2) return 0;
        // 变量分别记录是v1和v2的长度
        int l1 = version1.length(), l2 = version2.length();
        // 变量作为指针，指向v1和v2的元素下标，用于访问v1和v2，初始值为0
        int ptr1 = 0, ptr2 = 0;
        // 访问v1和v2，直到全部访问完成
        while (ptr1 < l1 || ptr2 < l2){
            // 变量分别记录v1和v2的子串代表的数字
            int digit1 = 0, digit2 = 0;
            // 计算v1的子串代表的数字
            while (ptr1 < l1 && version1[ptr1] != '.'){
                digit1 = digit1*10 + (version1[ptr1] - '0');
                ++ptr1;
            }
            // v1的指针后移一位
            ++ptr1;
            // 计算v2的子串代表数字
            while (ptr2 < l2 && version2[ptr2] != '.'){
                digit2 = digit2*10 + (version2[ptr2] - '0');
                ++ptr2;
            }
            // v2的指针后移一位
            ++ptr2;
            // 比较两个变量的大小，返回结果
            if (digit1 != digit2) return digit1>digit2?1:-1;
        }
        //如果计算到最后两者依然没有不同，则表示两个表示的版本号相同
        return 0;
    }
};