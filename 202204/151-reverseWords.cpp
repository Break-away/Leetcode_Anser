// 151. 颠倒字符串中的单词
// 给你一个字符串 s ，颠倒字符串中 单词 的顺序。
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果
// 字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

// 解题思路：
// 1、将输入字符串的单词提取出来，存入一个数组中，提取完成后，将数组中的元素反转，
// 然后用反转后的元素构建新的句子；
// 2、提取输入句子中的单词时，用双指针提取，初始时双指针指向同一个位置，如果遇到空格，
// 两个指针一起后移，如果遇见字符，右指针后移，当有指针指向空格，但左指针指向字符时，
// 将两个指针之间的单词存入数组，然后两个指针一起指向下一个位置；

// 1 <= s.length <= 104
// s 包含英文大小写字母、数字和空格 ' '
// s 中 至少存在一个 单词

#include <string>
#include <vector>
#include <ctype.h>

using std::string;
using std::vector;
using std::isspace;

class Solution {
public:
    string reverseWords(string s) {
        //计算字符的长度；
        int n = s.length();
        //创建存储单词的数组；
        vector<string> word_vec;
        //创建左、右指针，初始时指向s的末尾
        int left = n-1, right = n-1;
        //从后往前遍历s
        while (left>=0){
            //如果left=0，则将left和right之间的单词加入数组，从left开始，长度为right-left+1
            if (left == 0) {
                if (isspace(s[left])){
                    if (left == right) {
                        break;
                    }
                    else{
                        word_vec.emplace_back(s.substr(left+1,right-left));
                        break;
                    }
                }
                else{
                    word_vec.emplace_back(s.substr(left,right-left+1));
                    break;
                }
            }
            //如果当前位置为空格
            if (isspace(s[left])){
                //如果两个指针指向的位置相同，同时将两个指针前移
                if (left == right) {
                    --left;
                    right = left;
                }
                else{
                    //将左、右指针之间的单词加入数组，从left+1开始，长度为right-left
                    word_vec.emplace_back(s.substr(left+1,right-left));
                    //并将左、右指针一起指向左指针的下一个位置
                    //如果left-1>0，则将左、右指针一起前移，否则直接终止循环
                    if (left>0){
                        --left;
                        right = left;
                    }
                    else break;
                } 
            }
            //如果当前位置为字符或者数字，将左指针前移
            else --left;
        }
        string ret;
        int vec_size = word_vec.size();
        for (int i = 0; i < vec_size; i++)
        {
            if (i == vec_size -1) {
                ret += word_vec[i];
            }
            else{
                ret += word_vec[i] + ' ';
            }
        }
        return ret;
    }     
};

//先对s进行处理
class Solution {
public:
    string reverseWords(string s) {
        //计算字符的长度；
        int n = s.length();
        //处理s前部的空格
        while (isspace(s[0]))
        {
            s = s.substr(1,n-1);
            --n;
        }
        
        //创建存储单词的数组；
        vector<string> word_vec;
        //创建左、右指针，初始时指向s的末尾
        int left = n-1, right = n-1;
        //从后往前遍历s
        while (left>=0){
            //如果left=0，则将left和right之间的单词加入数组，从left开始，长度为right-left+1
            if (left == 0) {
                word_vec.emplace_back(s.substr(left,right-left+1));
                break;
            }
            //如果当前位置为空格
            if (isspace(s[left])){
                //如果两个指针指向的位置相同，同时将两个指针前移
                if (left == right) {
                    --left;
                    right = left;
                }
                else{
                    //将左、右指针之间的单词加入数组，从left+1开始，长度为right-left
                    word_vec.emplace_back(s.substr(left+1,right-left));
                    //并将左、右指针一起指向左指针的下一个位置
                    //如果left-1>0，则将左、右指针一起前移，否则直接终止循环
                    if (left>0){
                        --left;
                        right = left;
                    }
                    else break;
                } 
            }
            //如果当前位置为字符或者数字，将左指针前移
            else --left;
        }
        string ret;
        int vec_size = word_vec.size();
        //将单词组合成句子
        for (int i = 0; i < vec_size; i++)
        {
            if (i == vec_size -1) {
                ret += word_vec[i];
            }
            else{
                ret += word_vec[i] + ' ';
            }
        }
        return ret;
    }     
};