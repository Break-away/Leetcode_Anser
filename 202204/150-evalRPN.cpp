// 150. 逆波兰表达式求值
// 根据 逆波兰表示法，求表达式的值。
// 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
// 注意 两个整数之间的除法只保留整数部分。
// 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

#include <string>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::string;

class Solution {
public:
    //判断字符串是否为数字
    bool isnumber(string s){
        return ( s != "+" && s != "-" && s != "*" && s != "/");
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for (int i=0; i<n; i++){
            string token = tokens[i];
            if (isnumber(tokens[i])){
                stk.push(std::stoi(token.c_str()));
            }
            else{
                int digit2 = stk.top();
                stk.pop();
                int digit1 = stk.top();
                stk.pop();
                switch (token[0])
                {
                    case '+':
                        stk.push(digit1 + digit2);
                        break;
                    case '-':
                        stk.push(digit1 - digit2);
                        break;
                    case '*':
                        stk.push(digit1 * digit2);
                        break;
                    case '/':
                        stk.push(digit1 / digit2);
                        break;
                }
            }
        }
        return stk.top();
    }
};
