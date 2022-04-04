//2022.4.1
//反向迭代器
#include <iterator>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::reverse_iterator;
using std::cout;
using std::endl;
using std::string;

class Solution 
{
private:
    vector<vector<int>> vec;
public:
    //s = "rabbbit", t = "rabbit"
    int mynumDistinct(string& s, string& t, int sl, int tl)
    {
        if (sl < tl) return 0;
        if (tl == 0) return 1;
        if (sl == 0 && tl > 0) return 0;
        if (s == t) return 1;
        for (int i = 1; i <= sl; ++i)
        {
            for (int j=1; j <= tl; ++j)
            {
                if (s[i-1] == t[j-1])
                {
                    vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
                }
                else
                {
                    vec[i][j] = vec[i-1][j];
                }
            }
        }
        return vec[sl][tl];
    }

    int numDistinct(string s, string t) 
    {
        //memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的。 
        //其原型是：void* memset(void *_Dst, int  _Val, size_t _Size)
        //_Dst是目标起始地址，_Val是要赋的值，_Size是要赋值的字节数。
        vec=vector<vector<int>> (s.length()+1,vector<int> (t.length()+1));
        for (int i=0; i<s.length()+1; ++i)
        {
            vec[i][0]=1;
        }
        return mynumDistinct(s,t,s.length(),t.length());
    }
};
int main()
{
    //学习iterator
    // vector<int> vec={1,2,3,4,5,6,7,8};
    // //vec.rbegin() 指向vec最后一个元素迭代器
    // //vec.rend()指向vec第一个元素之前的位置的迭代器
    // reverse_iterator<vector<int>::iterator> my_r_iterator(vec.begin());  //指向1之前的位置
    // my_r_iterator--;
    // reverse_iterator<vector<int>::iterator> my_r_iterator2=vec.rbegin(); //指向8
    // reverse_iterator<vector<int>::iterator> begin(vec.begin());
    // reverse_iterator<vector<int>::iterator> end(vec.end());

    // cout << "my_r_iterator:" << *my_r_iterator <<endl;
    // cout << "my_r_iterator2:" << *my_r_iterator2 <<endl;
    // for (auto iter=begin.base(); iter != end.base(); iter++)
    // {
    //     cout << "iter" << *iter <<endl;
    // }

    string s="aa";
    string t="a";
    Solution sl;
    int a=sl.numDistinct(s,t);
    cout << "a: " << a << endl;
    return 0;
};
