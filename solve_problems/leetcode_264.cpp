/*
    2021 -04-11

    题目：丑数||

    给你一个整数 n ，请你输出第 n 个丑数 。
    丑数 就是只包含质因数 2、3 和/或 5 的正整数。

    解题思路：这道题是263丑数的一个升级版，问题需要输出第n个丑数
            我们可以先看示例：
            输入：n = 10
            输出：12
            解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。

            就是让我们找到从小到大数，第n个丑数

            那么我们可以计算出每一个丑数数组， 里面依次存放从小到大的丑数， 容量为n+1
            我们可以用动态规划的方法来做

            确定状态: 由于丑数是由 2*i + 3*j + 5*k 组成， 那么第n个丑数也是满足这个公式的   

            初始化: 我们知道的是 1 是一个最基本的丑事， 所以初始化为 dp[1] = 1

            动态转移方程为:  dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5))

    看代码：
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p1 = 1, p2 = 1, p3 = 1;
        for (int i = 2; i <= n; i++) {
            int n1 = dp[p1]*2, n2 = dp[p2]*3, n3 = dp[p3]*5;
            dp[i] = min(min(n1, n2), n3);
            if (dp[i] == n1) p1++;
            if (dp[i] == n2) p2++;
            if (dp[i] == n3) p3++;
        }
        return dp[n];
    }
};