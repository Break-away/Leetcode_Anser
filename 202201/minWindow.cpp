/*����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ���
��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��*/

/*��⣺���û���ڣ��������ڵĵ��ַ�������t���򴰿��Ҳ�������ƣ�
�������ڵ��ַ�����t�����жϴ�������ַ��Ƿ�����t���ַ������ǣ����
��������ڵ��ַ�����������ര������*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*�������ڴ洢�ַ���s�Ļ���ں��ַ���t���ַ�����unordered_map*/
    unordered_map<char, int> temp, strt;
    /*������������Ƿ�����ַ���t�е������ַ�*/
    bool check() {
        for (const auto& ch : strt) {
            if (temp[ch.first] < ch.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        /*��ʼ��strt*/
        for (const auto& c : t) {
            ++strt[c];
        }
        int l = 0, r = -1;
        int ansL = -1, len = INT_MAX;
        while (r < (int)s.size()) {
            if (strt.find(s[++r]) != strt.end()) temp[s[r]]++;
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (strt.find(s[l]) != strt.end()) temp[s[l]]--;
                l++;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};