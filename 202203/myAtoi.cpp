#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class StrtoNum
{
private:
    string state="start";
    unordered_map<string,vector<string>> status_juge=
    {
        {"start",{"start","sign","number","end"}},
        {"sign",{"end","end","number","end"}},
        {"number",{"end","end","number","end"}},
         {"end",{"end","end","end","end"}},
    };
    
    int get_status(char c)
    {
        if (isspace(c)) return 0;
        if (c=='-'|| c=='+') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign=1;
    long long ans=0;
    void get(char c)
    {
        state=status_juge[state][get_status(c)];
        if(state=="number")
        {
            ans=ans*10 + c-'0';
            ans=sign==1?min(ans,(long long)INT_MAX):min(ans,-(long long)INT_MIN);
        }
        if (state=="sign")
        {
            sign=c=='+'?1:-1;
        }
    }
};

class Solution {
public:
    int myAtoi(string s) 
    {
        StrtoNum strtonum;
        for(char c:s)
        {
            strtonum.get(c);
        }
        return strtonum.sign * strtonum.ans;
    }
};