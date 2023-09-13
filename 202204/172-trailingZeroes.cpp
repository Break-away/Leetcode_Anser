// 172. 阶乘后的零
// 给定一个整数 n ，返回 n! 结果中尾随零的数量。
// 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

// 解题思路：
// 1、先计算n的阶乘结果；
// 2、用结果除以10求余，如果余=0，则表明尾随一个0，
//    继续用求模结果重复上述计算；

#include <vector>
using std::vector;

class Solution {
public:
    int get_factorial(int n){
        if (n == 1) return 1;
        int ret = 1;
        for (int i=2; i<=n; i++){
            ret = ret * i;
        }
        return ret;
    }
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        int factorial = get_factorial(n);
        int zero_cnt = 0;
        while(factorial % 10 == 0){
            zero_cnt++;
            factorial /= 10;
        }
        return zero_cnt;
    }
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int zero_cnt = 0;
        unsigned long long ret = 1;
        for (int i=2; i<=n; i++){
            ret = ret * i;
            while(ret % 10 == 0){
                zero_cnt++;
                ret /= 10;
            }

        }
        return zero_cnt;
    }
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int zero_cnt = 0;
        unsigned long long sum = 1;
        for (int i=n; i>1; i--){
            if (i % 2 == 0 || i % 5 == 0){
                int temp = i;
                while (temp % 10 == 0) {
                    zero_cnt++;
                    temp /= 10;
                }
                if (temp % 2 == 0) sum = sum * 2;
                while (temp % 5 == 0) {
                    sum = sum * 5;
                    temp /= 5;
                }
                while (sum % 10 == 0) {
                    zero_cnt++;
                    sum /= 10;
                }
            }
        }
        return zero_cnt;
    }

    //官方解答
    // n! 尾零的数量即为 n! 中因子 10 的个数，而 10=2×5，
    // 因此转换成求 n! 中质因子 2 的个数和质因子 5 的个数的较小值。
    // 由于质因子 5 的个数不会大于质因子 2 的个数（具体证明见方法二），
    // 我们可以仅考虑质因子 5 的个数。
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        if (n == 1) return 0;
        int zero_cnt = 0;
        while(n){
            n /= 5;
            zero_cnt += n;
        }
        return zero_cnt;
    }
};