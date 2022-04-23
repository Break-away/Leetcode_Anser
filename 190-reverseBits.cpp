// 190. 颠倒二进制位
// 颠倒给定的 32 位无符号整数的二进制位。

#include <stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for (int i=0; i<32; i++){
            uint32_t temp = n;
            //计算ans的第i位，第i位等于n的(31-i)位,将n的(31-i)位移动到0位，
            //与1求逻辑与，并将结果左移i位；
            ans |= ((temp >> (31-i)) & 1) << i;
        }
        return ans;
    }
};