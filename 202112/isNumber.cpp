#include <unordered_map>;
#include <string>;

using namespace std;

class Solution {
public:
    enum State
    {
        START,
        SIGN,
        INTE,
        POINT,
        POINT_WITHOUT_INTEGER,
        FRACTION,
        EXPONENT,
        SIGN_EXPONENT,
        INT_EXPONENT
    };
    enum Chartype
    {
        CHAR_SIGN,
        CHAR_NUM,
        CHAR_POINT,
        CHAR_EXP,
        CHAR_ILLEGAL
    };

    Chartype chartotype(char ch)
    {
        if (ch >= '0' && ch <= '9') return CHAR_NUM;
        else if (ch == '.') return CHAR_POINT;
        else if (ch == '-' || ch == '+') return CHAR_SIGN;
        else if (ch == 'e' || ch == 'E') return CHAR_EXP;
        else return CHAR_ILLEGAL;
    }

    bool isNumber(string s)
    {
        unordered_map<State, unordered_map<Chartype, State>> transfer
        {
            {
                START,
                {
                    {CHAR_SIGN,SIGN},
                    {CHAR_NUM,INTE},
                    {CHAR_POINT,POINT_WITHOUT_INTEGER}
                }
            },
            {
                SIGN,
                {
                    {CHAR_NUM,INTE},
                    {CHAR_POINT,POINT_WITHOUT_INTEGER}
                }
            },
            {
                INTE,
                {
                    {CHAR_NUM,INTE},
                    {CHAR_POINT,POINT},
                    {CHAR_EXP,EXPONENT}
                }
            },
            {
                POINT_WITHOUT_INTEGER,
                {
                    {CHAR_NUM,FRACTION}
                }
            },
            {
                POINT,
                {
                    {CHAR_NUM,FRACTION},
                    {CHAR_EXP,EXPONENT}
                }
            },
            {
                FRACTION,
                {
                    {CHAR_NUM,FRACTION},
                    {CHAR_EXP,EXPONENT}
                }
            },
            {
                EXPONENT,
                {
                    {CHAR_SIGN,SIGN_EXPONENT},
                    {CHAR_NUM,INT_EXPONENT}
                }
            },
            {
                SIGN_EXPONENT,{{CHAR_NUM,INT_EXPONENT}}
            },
            {
                INT_EXPONENT,{{CHAR_NUM,INT_EXPONENT}}
            }
        };

        State st = START;
        Chartype ty;
        for (char& str : s)
        {
            ty = chartotype(str);
            if (ty == CHAR_ILLEGAL) return false;
            if (transfer[st].find(ty) == transfer[st].end()) return false;
            else {
                st = transfer[st][ty];
            }
            return st == INTE || st == POINT || st == FRACTION || st == INT_EXPONENT;
        }
    }
};