// 126. 单词接龙 II
// 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 
// 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
// 每对相邻的单词之间仅有单个字母不同。
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 
// 不必是字典 wordList 中的单词。
// sk == endWord
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 
// beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。
// 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。

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
    //解题思路：
    //把每个单词都抽象为一个顶点，如果两个单词可以 只 改变一个字母进行转换，
    //那么说明他们之间有一条双向边。因此我们只需要把满足转换条件的点相连，就形成了一张 图。
    //将wordlist中的word构成图，然后查找路径

    void dfs(unordered_map<string,set<string>> &word_froms, const string &word, vector<string>& path, vector<vector<string>> &ans){
        //如果已经到了beginword，那么则到了终点，就没有word可以变化得到beginword
        if (word_froms[word].empty()) {
            ans.push_back(vector<string>(path.rbegin(),path.rend()));
            return;
        }
        //如果没有到终点，则在word的froms中查找下一个单词
        for (auto &from_word : word_froms[word]){
            path.emplace_back(from_word);
            dfs(word_froms,from_word,path,ans);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //存放计算结果
        vector<vector<string>> ans;
        //用于快速查找未计算的word
        unordered_set<string> word_set(wordList.begin(),wordList.end());
        //如果endword不在word_set中则直接终止计算
        if (word_set.find(endWord) == word_set.end()) return ans;

        //构造wordlist中word组成的图
        //存放word被查找到的层级
        unordered_map<string,int> word_level={{beginWord,0}};
        //存放word由哪些单词变换而来
        unordered_map<string,set<string>> word_froms={{beginWord,{}}};
        //依次存放每一次找到的下一层级的word
        queue<string> find_level;
        //beginword为第一层级
        find_level.push(beginWord);
        //如果beginword位于word_set中，需先删除，避免重复查找
        word_set.erase(beginWord);
        //level表示当前查找的层级
        int level=0;
        //每个单词的长度
        int word_length = beginWord.length();
        //表示是否已经查找到路径
        bool found = false;
        while(!find_level.empty()){
            //完成一个循环后，层架加1
            level++;
            //当前循环需要计算的word数量
            int size = find_level.size();
            for (int i=0; i<size; i++){
                //表示该循环需要计算的word，计算有哪些单词可以通过该word变化而来
                const string cur_word = std::move(find_level.front());
                find_level.pop();
                //表示可以通过cur_word变化得到的单词
                string next_word = cur_word;
                //依次修改cur_word中的各个位置的字母
                for (int i=0; i<word_length; i++){
                    //当前需要变化的位置的char的原始值
                    const char origin_char = cur_word[i];
                    //依次改变当前位置的字母
                    for (char c='a'; c != 'z'; ++c){
                        next_word[i] = c;
                        //如果nextword已经可以由其他的上一层级单词变化而来
                        //则将curword添加到nextword的froms中即可
                        if (word_level[next_word] == level) {
                            word_froms[next_word].insert(cur_word);
                        }
                        //如果单词不在word_set中，则表示nextword不可以通过cur_word变化而来
                        //不是我们要找的单词，直接跳过
                        if (word_set.find(next_word) == word_set.end()) continue;
                        //如果nextword可以通过cur_word变化而来，那么表示我们已经找到了该单词
                        //则可以删除掉
                        word_set.erase(next_word);
                        //更新当前找到的nextword的层级
                        word_level[next_word] = level;
                        //更新nextword的可以通过cur_word变化而来
                        word_froms[next_word].insert(cur_word);
                        //nextword位于下一层级的查找，添加到find_level
                        find_level.push(next_word);
                        //如果next_word == endWord，则表示已经找到一条路径
                        if (next_word == endWord) found = true;
                    }
                    //计算完成一个位置后，恢复原始值
                    next_word[i] = origin_char;
                }
            }
            //因为要找最短路径，一旦找到了路径即是最短路径，则可退出查找循环
            if (found) break;
        }
        //如果找到了路径，则将路径添加到结果ans中
        if (found){
            //从endword反推到beginword
            vector<string> path={endWord};
            dfs(word_froms,endWord,path,ans);
        }
        return ans;
    }
};

//官方解答
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        // 修改以后看一下，如果根本就不在 dict 里面，跳过
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        // 特殊用例处理
        dict.erase(beginWord);

        // 第 1 步：广度优先遍历建图
        // 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先遍历的第几层
        unordered_map<string, int> steps = {{beginWord, 0}};
        // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        unordered_map<string, set<string>> from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        int wordLen = beginWord.length();
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                // 将每一位替换成 26 个小写英文字母
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到，且距离更远的单词，需要将它从 dict 中删除
                        dict.erase(nextWord);
                        // 这一层扩展出的单词进入队列
                        q.push(nextWord);
                        // 记录 nextWord 从 currWord 而来
                        from[nextWord].insert(currWord);
                        // 记录 nextWord 的 step
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        // 第 2 步：深度优先遍历找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
        if (found) {
            vector<string> Path = {endWord};
            dfs(res, endWord, from, Path);
        }
        return res;
    }

    void dfs(vector<vector<string>> &res, const string &Node, unordered_map<string, set<string>> &from,
             vector<string> &path) {
        if (from[Node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string &Parent: from[Node]) {
            path.push_back(Parent);
            dfs(res, Parent, from, path);
            path.pop_back();
        }
    }
};