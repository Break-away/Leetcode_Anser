/*有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
这些地址可以通过在 s 中插入 '.' 来形成。你不能重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。*/

/*示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：
输入：s = "0000"
输出：["0.0.0.0"]*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    static constexpr int seg_count=4;  //ip地址分段数量
    vector<string> ans;
    vector<int> segments;  //存放string分段结果
public:
    void dfs(const string &s,int segid, int segstart)
    {
        //调用函数第一步先判断是否已经找到四段，若已找到且已经到了string末尾，则找到了一个正确的组合
        if (segid==seg_count)
        {
            if (segstart==s.size())
            {
                string ipaddr;
                for (int i=0; i<seg_count; ++i)
                {
                    ipaddr+=to_string(segments[i]);
                    if (i != seg_count-1)
                    {
                        ipaddr+=".";
                    }
                }
                ans.push_back(move(ipaddr));
            }
            return ;
        }
        //若未到第四段，但是已到string末尾，则说明前面的组合不正确，需要退回
        if (segstart==s.size())
        {
            return;
        }
        //若当前段以'0'开始，则必须将'0'作为一个单独的分段
        if (s[segstart]=='0')
        {
            segments[segid]=0;
            dfs(s,segid+1,segstart+1);
        }
        //其余一般的情况
        int addr=0;
        for(int segend=segstart; segend<s.size(); ++segend)
        {
            addr=addr*10 + (s[segend]-'0');
            if (addr>0 && addr<=0xFF) 
            {
                segments[segid]=addr;
                dfs(s,segid+1,segend+1);
            }
            else 
            {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        segments.resize(seg_count);
        dfs(s,0,0);
        return ans;

    }
};