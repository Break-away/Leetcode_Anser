// 139. 单词拆分
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
// 请你判断是否可以利用字典中出现的单词拼接出 s 。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;

// 超出时间限制解法
// class Solution {
// private:
//     int s_len = 0;
//     int word_num = 0;
//     bool ans = false;
// public:
//     void my_wordbreak(string s, int id, vector<string> &wordDict){
//         if (id == s_len) {
//             ans = true;
//             return ;
//         }
//         for (int i=0; i<word_num; i++){
//             int word_size = wordDict[i].size();
//             if (s.substr(id,word_size) == wordDict[i]){
//                 my_wordbreak(s, id+word_size, wordDict);
//             }
//         }
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         s_len = s.length();
//         word_num = wordDict.size();
//         my_wordbreak(s,0,wordDict);
//         return ans;
        
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //用set来存储worddict中的单词以便于快速查找
        unordered_set<string> word_set;
        for (auto word : wordDict){
            word_set.insert(word);
        }
        //word总数
        int word_size = word_set.size();
        //用f[i]表示s的前i个单词是否可以由worddict中的单词组成
        vector<bool> f(s.size()+1,0);
        f[0] = true;
        for (int i=1; i<=s.size(); i++){
            for (int j=0; j<i; j++){
                if (f[j] && word_set.find(s.substr(j,i-j)) != word_set.end()){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
        
    }
};

// 140. 单词拆分 II
// 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，
// 使得句子中所有的单词都在词典中。以任意顺序 返回所有这些可能的句子。
// 注意：词典中的同一个单词可能在分段中被重复使用多次。

// 解题思路：
// 用一个vector记录s的前i个元素能否由dict中的单词增加空格来构建句子
// 用一个vector记录s的前i个元素由dict中元素构建的句子
// 从前往后检查s的qiani位能否被构建以及构建的结果

// 关键：
// 1、能够被构建：如果在subs中的某个位置将其分为两部分，如果前一部分能构建句子，
// 且后一部分位于dict中，那么久能构建；
// 2、构建的句子：将前一部分的每一个句子加上空格和后一部分的组成句子即是该位置的句子；

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //用于记录各个子串能否由dict中的单词构建句子
        vector<int> state(s.size()+1,0);
        //用于记录子串由dict中的单词构建出来的句子
        vector<vector<string>> ans(s.size()+1,vector<string>());
        //将worddict中的单词存入hash表，以便快速查找
        unordered_set<string> word_set;
        for (auto word : wordDict){
            word_set.insert(word);
        }
        state[0] = true;
        //计算各个子串能否由dict中的word组成
        //以及组成的句子
        for (int i = 1; i <= s.size(); i++){
            //计算子串从各个位置分开能否组成句子
            for (int j = 0; j < i; j++){
                if (state[j] && word_set.find(s.substr(j,i-j)) != word_set.end()){
                    //更新state
                    state[i] = true;
                    //更新ans
                    //如果第一部分没有组成句子，则直接将第二部分的单词作为句子加入ans
                    //作为当前位置的结果
                    if (ans[j].empty()){
                        ans[i].emplace_back(s.substr(j,i-j));
                    }
                    //如果第一部分组成了句子，将左右句子加上空格和第二部分作为句子
                    //然后加入ans，作为当前位置的结果
                    else{
                        //依次复制第一部分的句子
                        for (auto const sentence : ans[j]){
                            //复制句子
                            string copy_sentence = sentence;
                            //在复制的句子之后加入空格和第二部分
                            copy_sentence += ' ' + s.substr(j,i-j);
                            //将结果加入ans
                            ans[i].emplace_back(copy_sentence);
                        }
                    }
                }
            }
        }
        return ans[s.size()];
    }
};

//方案优化：用map来存储构建出来的句子
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //用于记录各个子串能否由dict中的单词构建句子
        vector<int> state(s.size()+1,0);
        //用于记录子串由dict中的单词构建出来的句子
        unordered_map<int, vector<string>> ans;
        //将worddict中的单词存入hash表，以便快速查找
        unordered_set<string> word_set;
        for (auto word : wordDict){
            word_set.insert(word);
        }
        state[0] = true;
        //计算各个子串能否由dict中的word组成
        //以及组成的句子
        for (int i = 1; i <= s.size(); i++){
            //计算子串从各个位置分开能否组成句子
            for (int j = 0; j < i; j++){
                if (state[j] && word_set.find(s.substr(j,i-j)) != word_set.end()){
                    //更新state
                    state[i] = true;
                    //更新ans
                    //如果第一部分没有组成句子，则直接将第二部分的单词作为句子加入ans
                    //作为当前位置的结果
                    if (ans.find(j) == ans.end()){
                        ans[i].emplace_back(s.substr(j,i-j));
                    }
                    //如果第一部分组成了句子，将左右句子加上空格和第二部分作为句子
                    //然后加入ans，作为当前位置的结果
                    else{
                        //依次复制第一部分的句子
                        for (auto const sentence : ans[j]){
                            //复制句子
                            string copy_sentence = sentence;
                            //在复制的句子之后加入空格和第二部分
                            copy_sentence += ' ' + s.substr(j,i-j);
                            //将结果加入ans
                            ans[i].emplace_back(copy_sentence);
                        }
                    }
                }
            }
        }
        return ans[s.size()];
    }
};