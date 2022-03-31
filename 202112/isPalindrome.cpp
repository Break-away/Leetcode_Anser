#include <vector>;
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        if (x == 0) return true;
        vector<int> a;
        int b;
        while (x > 0)
        {
            b = x % 10;
            a.push_back(b);
        }
        int len = a.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            if (a[left] == a[right])
            {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};