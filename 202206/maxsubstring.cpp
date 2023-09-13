/*描述
输入一个字符串，返回其最长的数字子串，以及其长度。若有多个最长的数字子串，则将它们全部输出（按原字符串的相对位置）
本题含有多组样例输入。

数据范围：字符串长度 1 \le n \le 200 \1≤n≤200  ， 保证每组输入都至少含有一个数字
输入描述：
输入一个字符串。1<=len(字符串)<=200
输出描述：
输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）。*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    string str;
    while (getline(cin, str)){
        vector<string> mp; //存放数字字符串及其长度
        int size = str.length();
        int max_num=0;
        for(int i=0; i<size; ){
            string digit = "";
            int dsize = 0;
            while(i<size && isdigit(str[i])){ //获取连续数字字符串
                digit += str[i];
                dsize++;
                i++;
            }
            if (dsize>max_num) {
                max_num=dsize;
                mp.clear();
                mp.push_back(digit);
            }
            else if (dsize == max_num){
                mp.push_back(digit);
            }
            i++;
        }
        for (auto num: mp){
            cout << num;
        }
        cout << "," <<  max_num << endl;
    }
    return 0;
}