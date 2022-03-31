/*给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对
它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝
色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。*/

#include <vector>
#include <iostream>
#include "sortColors.cpp"

using namespace std;

int main() {
    /*程序输入*/
    vector<int> mainin;
    mainin = vector<int>({ 1, 2, 0, 1, 0 });
    Solution solution;
    solution.sortColors(mainin);
    for (auto const& num : mainin) {
        cout << num;
    }
}