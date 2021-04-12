/*
    2021 -04 -12

    题目：最大数

    给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
    注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数

    我们看示例：
    示例 1：
    输入：nums = [10,2]
    输出："210"

    示例 2：
    输入：nums = [3,30,34,5,9]
    输出："9534330"

    示例 3：
    输入：nums = [1]
    输出："1"    
    
    示例 4：
    输入：nums = [10]
    输出："10"

    解题分析: 我们看示例， 可以总结出这道题的关键要素 
                    1、所给的数组的数是一个整体
                    2、我们应该把最高位尽可能大的数放前面
                    3、我们的思路是对两个数的组合取最大值 如 10,2  
                       可以组合成 "10" + "2" = "102" 和 "2" + "10" = "210" 取"210"

    看代码：

*/

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr; // 用于存放nums元素的string形式
        for (int n : nums) {    // 依次放入数组中
            numsStr.push_back(to_string(n));
        }
        // 对这些字符串进行排序， 按照 a + b > b + a 的形式排序 
        // 如 10 + 2 = 102   2 + 10 = 210  选择大的那个值
        sort(numsStr.begin(), numsStr.end(),[](string &a, string &b) {return a + b > b + a;});
        if (numsStr[0] == "0") return "0"; // 假如排序后 "0" 是最大的数，就说明字符串只有0，直接返回
        string ans = "";    
        for (string s : numsStr) { // 依次拼接组成最大的数
            ans += s;
        }
        return ans;
    }
};