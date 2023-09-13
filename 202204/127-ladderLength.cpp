// 127. 单词接龙
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列
//  beginWord -> s1 -> s2 -> ... -> sk：
// 每一对相邻的单词只差一个字母。
// 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
// sk == endWord
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 
// 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

// 解题思路：
// 第一步：构建一个转化序列的双向图：
// 如果两个单词可以通过将其中某一位变为*后变得相同，那么这两个单词就可以互相转化，
// 以此为基础，可以构建一个双向图；
// 为每一个单词和其变化而来的带*的单词分配一个id，并用map记录word和id的映射关系，然后用
// 二维数组来记录单词和其可以变化成的单词，记录是用位置来表示单词id，即可构建双向图；
// 第二步：遍历无向图，查找最近的转化路径，得出其单词数目：
// 遍历第一步建立的双向图，用数组来记录从beginword到某个单词的转化序列有多少个单词，记录是
// 用位置表示id，用id表示单词；

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::set;

class Solution {
public:
    //用map来存储word和id的映射关系
    unordered_map<string,int> wordid;
    //用二维vector来存储单词连接的单词组成的数组
    vector<vector<int>> wordedge;
    //双向图中的单词id，初始为0
    int wordnum = 0;

    //为输入单词分配id和初始化存储其连接单词的存储数组
    void addwordid(string &word){
        //如果还没有为word分配id，则指向分配操作
        if (wordid.find(word) == wordid.end()){
            wordid[word] = wordnum++;
            wordedge.emplace_back();
        }
    }

    //查找输入单词与哪些单词相连接
    void addedge(string &word){
        addwordid(word);
        int id1 = wordid[word];
        for(char &c : word){
            const char origin = c;
            c = '*';
            //必须先创建wordid
            addwordid(word);
            int id2 = wordid[word];
            wordedge[id1].emplace_back(id2);
            wordedge[id2].emplace_back(id1);
            c = origin;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //查找每个单词连接的单词
        for (string &word : wordList){
            addedge(word);
        }
        //查找beginword连接的单词
        addedge(beginWord);
        //判断endword是否在wordid中，如果不在即表示没有映射，直接返回0
        if (wordid.find(endWord) == wordid.end()){
            return 0;
        }

        //遍历双向图
        //存储从初始位置到某个id亦即某个单词的转化序列包括的单词数量，用数组存储查找结果，
        //用数组位置表示单词的id，数组中的初始值为int_max，int_max表示还没有查找到该单词；
        vector<int> disword(wordnum, INT_MAX);
        //用变量记录beginword和endword的id；
        int begin_id = wordid[beginWord];
        int end_id = wordid[endWord];
        //到beginword的转化序列单词数量为0
        disword[begin_id] = 0;
        //用queue实现遍历操作
        queue<int> que;
        que.push(begin_id);
        while (!que.empty()){
            //记录当前计算的单词id
            int cur_id = que.front();
            que.pop();
            //如果当前id等于endword的id，表示已经找到目的序列，返回结果
            if (cur_id == end_id){
                //因为转化序列中插入了带*的中间word，所以需转换结果
                return disword[cur_id]/2+1;
            }
            //遍历当前word所有连接的word
            for (auto id : wordedge[cur_id]){
                //用int_max来判断连接的word是否被访问过，如果没有被访问则计算其结果并加入que
                if (disword[id] == INT_MAX){
                    disword[id] = disword[cur_id] + 1;
                    que.push(id);
                }
            }
        }
        //如果没有beginword到endword的转化序列，返回0
        return 0;
    }
};