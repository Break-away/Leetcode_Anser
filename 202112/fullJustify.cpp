#include <vector>;
#include <string>;

using namespace std;

class Solution {
public:
    string addspace(int n)
    {
        string ans;
        ans = string(n, ' ');
        return ans;
    }

    string addword(vector<string>& words, int maxWidth, int begin, int end, int wordlen)
    {
        string ret = words[begin];
        int space = (maxWidth - wordlen) / (end - begin - 1);
        int morespace = (maxWidth - wordlen) % (end - begin - 1);
        for (int i = begin + 1; i < end; i++)
        {
            if (morespace > 0)
            {
                ret += ' ';
                morespace--;
            }
            ret += addspace(space) + words[i];
        }
        return ret;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ans;
        int l = words.size();
        int end = 0;
        while (true)
        {
            int begin = end;
            int len = 0;
            while (end < l && len + words[end].length() + (end - begin) <= maxWidth)
            {
                len += words[end].length();
                end++;
            }
            if (end == l)
            {
                string ret;
                for (int i = begin; i < end - 1; i++) ret += words[i] + " ";
                ret += words[end - 1];
                ret = ret + string((maxWidth - ret.size()), ' ');
                ans.push_back(ret);
                return ans;
            }
            if (end - begin == 1)
            {
                string ret;
                ret = words[begin] + string(maxWidth - len, ' ');
                ans.push_back(ret);
                continue;
            }
            string ret = addword(words, maxWidth, begin, end, len);
            ans.push_back(ret);
        }
    }
};