// 87. 扰乱字符串
// 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
// 如果字符串的长度为 1 ，算法停止
// 如果字符串的长度 > 1 ，执行下述步骤：
// 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，
// 则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
// 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。
// 即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
// 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
// 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
// 如果是，返回 true ；否则，返回 false 。

// 示例 1：
// 输入：s1 = "great", s2 = "rgeat"
// 输出：true
// 解释：s1 上可能发生的一种情形是：
// "great" --> "gr/eat" 
// // 在一个随机下标处分割得到两个子字符串
// "gr/eat" --> "gr/eat" 
// // 随机决定：「保持这两个子字符串的顺序不变」
// "gr/eat" --> "g/r / e/at" 
// // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
// "g/r / e/at" --> "r/g / e/at" 
// // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
// "r/g / e/at" --> "r/g / e/ a/t" 
// // 继续递归执行此算法，将 "at" 分割得到 "a/t"
// "r/g / e/ a/t" --> "r/g / e/ a/t" 
// // 随机决定：「保持这两个子字符串的顺序不变」
// 算法终止，结果字符串和 s2 相同，都是 "rgeat"
// 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，
// 返回 true。

#include <string>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::string;

class Solution 
{
private:
    int memo[30][30][31]; //记忆化搜索存储状态的数组，-1表示未false，1表示true，0表示未计算
    string s1,s2;
public:
    //解法超出时间限制
    // bool isScramble(string s1, string s2) 
    // {
    //     int l1=s1.length(),l2=s2.length();
    //     if (l1 != l2) return false;
    //     if (l1==1 && s1==s2) return true;
    //     for (int i=1; i<l1; ++i)
    //     {
    //         //前半部分长度 i，后半部分长度l-i
    //         //判断s1的前半部分和s2的前半部分以及s1的后半部分和s2的后半部分是否交错
    //         if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,l1-i),s2.substr(i,l2-i)))
    //         {
    //             return true;
    //         }
    //         //判断s1的前半部分和s2的后半部分以及s1的后半部分和s2的前半部分是否交错
    //         if (isScramble(s1.substr(0,i),s2.substr(l2-i,i)) && isScramble(s1.substr(i,l1-i),s2.substr(0,l2-i)))
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    //分析s1从位置l1长度为length的子字符串和s2从位置l2开始长度为length的子字符串是否具有相同的元素
    bool check_if_similar(int l1, int l2, int length)
    {
        // std::map<X, Y>实际储存了一串std::pair<const X, Y>
        // std::map<std::string, int> m = /* fill it */;
        // auto it = m.begin();
        // 这里，如果你用*it，那么你将得到map第一个元素的std::pair：
        // 现在你可以接收std::pair的两个元素：
        // (*it).first会得到key，
        // (*it).second会得到value。
        // 这等同于it->first和it->second。
        unordered_map<int,int> freq;
        for (int i=l1; i<l1+length; ++i)
        {
            freq[s1[i]]++;
        }
        for (int j=l2; j<l2+length; ++j)
        {
            freq[s2[j]]--;
        }
        //一元谓词：lambda函数：[] (const auto & entry) {return entry.second() != 0;})
        if (std::any_of(freq.begin(),freq.end(),[] (const auto & entry) {return entry.second() != 0;}))
        {
            return false;
        }
        return true;
    }

    //检索字符串是否属于扰乱字符串
    bool dfs(int l1, int l2, int lenght)  //l代表location
    {
        //检查记忆化数组中是否存储有当前搜索字符串的状态
        if(memo[l1][l2][lenght])  //如果memo[l1][l2][lenght]为非0，判断为真，则表示已经存储有当前字符串的状态，返回结果即可
        {
            return memo[l1][l2][lenght]==1;
        }
        //如果比较的两个子串相等，这一定是扰乱字符串
        if(s1.substr(l1,lenght) == s2.substr(l2,lenght))
        {
            memo[l1][l2][lenght]=1;
            return true;
        }
        //判断两个子串是否具有相同的元素，如果元素不同，则一定不是扰乱字符串
        if (!check_if_similar(l1,l2,lenght))
        {
            memo[l1][l2][lenght]=-1;
            return false;
        }
        //依次检查从各个位置开始是否属于交错字符串
        for (int i=1; i<lenght; ++i)
        {
            //判断是否属于前后对应的类型
            if (dfs(l1,l2,i) && (l1+i,l2+i,lenght-i))
            {
                memo[l1][l2][lenght]=1;
                return true;
            }
            //判断是否属于前后错位的类型
            if(dfs(l1,l2+lenght-i,i) && dfs(l1+i,l2,lenght-i))
            {
                memo[l1][l2][lenght]=1;
                return true;
            }
        }
        memo[l1][l2][lenght]=-1;
        return false;
    }

    bool isScramble(string s1, string s2) 
    {
        //memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的。 其原型是：void* memset(void *_Dst, int  _Val, size_t _Size)
        //_Dst是目标起始地址，_Val是要赋的值，_Size是要赋值的字节数。
        std::memset(memo,0,sizeof(memo));
        this->s1=s1;
        this->s2=s2;
        return dfs(0,0,s1.size());
    }
};