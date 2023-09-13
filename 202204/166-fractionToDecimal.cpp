// 166. 分数到小数
// 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
// 如果小数部分为循环小数，则将循环的部分括在括号内。
// 如果存在多个答案，只需返回 任意一个 。
// 对于所有给定的输入，保证 答案字符串的长度小于 10**4 。

// 解题思路：
// 分子除以分母，会有三种可能：整数、有限小数和无限循环小数；
// 用分子除分母求余，如果结果为0，则表示答案为整数，否则为小数；
// 针对答案处理，分为三步：
// 第一步：判断结果正负，将对应符号加入答案；
// 第二步：结算结果整数部分，转换为字符串加入答案；
// 第三步：如果答案为整数，则无该步骤，否则计算小数部分，并转化为字符串后加入答案；
// 关于如何判断小数部分是否为循环小数：因为小数只能是有限或者无限循环小数，如果是有限小数，
// 则其小数部分数字肯定不会有重复，因为一旦有重复就是无限循环小数，基于此，可以用hash表记录
// 小数，如果发现有重复部分，则是无限循环小数，对小数进行处理即可

#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //将输入int转换为long
        long numerator_long = numerator;
        long denominator_long = denominator;
        if (denominator_long == 0) return string();
        // ans用于存储答案
        string ans;
        // 判断分子除以分母结果是整数还是小数
        // 如果结果是整数，将结果转化为字符串加入ans，并返回
        if (numerator_long % denominator_long == 0){
            return std::to_string(numerator_long / denominator_long);
        }
        // 判断答案的正负，并将结果写入ans
        if ((numerator_long<0) ^ (denominator_long<0)){
            ans.push_back('-');
        }
        // 结果为小数
        // 计算小数整数部分，并将计算结果转化为字符串加入ans
        ans.append(std::to_string(std::abs(numerator_long) / std::abs(denominator_long)));
        // 将小数点.加入ans
        ans += '.';
        // 计算小数部分
        // 变量remainder用于记录余数
        long remainder = std::abs(numerator_long) % std::abs(denominator_long);
        // hash表用于记录某个余数第一次出现的位置
        unordered_map<int,int> fract_index;
        // 遍历fractional用于记录小数部分的结果
        string fractional;
        // 变量index用于记录余数出现的位置，初始值为0
        int index = 0;
        // 如果余数不为0，且未出现过，则继续查找
        while(remainder != 0 && fract_index.find(remainder) == fract_index.end()){
            fract_index[remainder] = index;
            index++;
            fractional += remainder*10 / std::abs(denominator_long) + '0';
            remainder = remainder*10 % std::abs(denominator_long);
        }
        // 对小数结果进行处理，如果remainder!=0，说明有循环节
        // 在循环部位加上括号
        if (remainder != 0){
            fractional = fractional.substr(0,fract_index[remainder]) + '(' +fractional.substr(fract_index[remainder]) + ')';
        }
        // 在ans后面加上小数部分结果
        ans += fractional;
        // 返回结果
        return ans;
    }
};