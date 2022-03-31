#include <string>;
#include <vector>;
#include <unordered_map>;

using namespace std;

/*方法一*/
class Solution {
public:
    int matchstr(string s, string subs)
    {
        int ans = -1;
        if (subs.size() > s.size()) return ans;
        if (subs.size() == 0 || s.size() == 0) return ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == subs[0])
            {
                int j = 1;
                int k = 1;
                while (s[j] == subs[k])
                {
                    j++;
                    k++;
                }
                if (k == subs.size()) return i;
            }
        }
        return ans;
    }

    vector<string> wordcombination(vector<string>& words)
    {
        if (words.size() == 1) return words;

    }

    vector<int> findSubstring(string s, vector<string>& words)
    {

    }
};


/*方法二*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ans = {};
        int wordlen = words[0].size();
        int wordcount = words.size();
        if (s.size() < wordlen * wordcount) return ans;
        unordered_map<string, int> wordmap;
        for (int i = 0; i < words.size(); i++)
        {
            wordmap[words[i]]++;
        }
        for (int j = 0; j <= s.size() - wordlen * wordcount; j++)
        {
            string word = s.substr(j, wordlen);
            if (wordmap[word] == 0) continue;
            unordered_map<string, int> tempmap = wordmap;
            int n = j;
            for (int k = 0; k < wordcount; k++)
            {
                string tempword = s.substr(n, wordlen);
                if (tempmap[tempword] == 0) break;
                else
                {
                    n += wordlen;
                    tempmap[tempword]--;
                }
            }
            if (n == wordlen * wordcount + j) ans.push_back(j);
        }
        return ans;
    }
};