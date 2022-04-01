//2022.4.1
//反向迭代器
#include <iterator>
#include <vector>
#include <iostream>

using std::vector;
using std::reverse_iterator;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8};
    //vec.rbegin() 指向vec最后一个元素迭代器
    //vec.rend()指向vec第一个元素之前的位置的迭代器
    reverse_iterator<vector<int>::iterator> my_r_iterator(vec.begin());  //指向1之前的位置
    my_r_iterator--;
    reverse_iterator<vector<int>::iterator> my_r_iterator2=vec.rbegin(); //指向8
    reverse_iterator<vector<int>::iterator> begin(vec.begin());
    reverse_iterator<vector<int>::iterator> end(vec.end());

    cout << "my_r_iterator:" << *my_r_iterator <<endl;
    cout << "my_r_iterator2:" << *my_r_iterator2 <<endl;
    for (auto iter=begin.base(); iter != end.base(); iter++)
    {
        cout << "iter" << *iter <<endl;
    }
    return 0;
};