/*
    2021 - 04 -04

    问题：森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。
    我们将这些回答放在 answers 数组里。
    返回森林中兔子的最少数量。


示例:

输入: answers = [1, 1, 2]
输出: 5
解释:
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。

输入: answers = [10, 10, 10]
输出: 11

输入: answers = []
输出: 0


题目分析：对于这一题， 首先我们知道的是，兔子说的都是真的（哈哈哈， 有点废话，但是确实是解题的关键）
        我们先分析一下实例， 1,1,2 说明第一只兔子和第二只兔子是同一种颜色的
        第三只兔子则是看到了和它颜色相同的另外两只兔子，那么就是 1 + 1 + 2 + 1 = 5
        这里要求的是最少的兔子数量
        我们可以这样想， 先把answers数组中相同的进行计数 (设n为某一个数， m为出现n的次数)
        这里可以有两种情况：1、m <= n+1 时，说明这些回答n的兔子同颜色，则最少有n+1只兔子
                          2、m > n+1时， 说明这些回答n的兔子存在多种颜色
                            那么就要进行分组， 每一组为 n+1只,那么最少兔子为 (m+n)/(n+1) * (n+1)
                            要向上去整 


*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> hashMap;    // 使用哈希表进行对相同的answer计数
        for (int ans : answers) ++hashMap[ans];
        for (auto &item : hashMap) { // 累加每个answer的最小兔子数量
            res += ((item.second + item.first) / (item.first + 1)) * (item.first + 1); 
        }
        return res;
    }
};