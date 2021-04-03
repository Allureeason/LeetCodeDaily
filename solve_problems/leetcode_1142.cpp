/* 2021-04-03

    求两个字符串的最长公共子序列


    text1 和 text2     
 
    解题思路：
        使用动态规划求解
        1、首先用一个二维数组作为dp 状态数组
        2、分析转移方程：
            1) 当前位置的 text1[i] 和 text2[j]不相等的时候取相邻位置的最大值
                         dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            2) 当前位置的 text1[i] 和 text2[j]相等的时候取  左上角的值加一
                        dp[i][j] = dp[i-1][j-1] + 1;


*/

 // 代码如下


 #include <iostream>
 #include <algorithm>
 #include <vector>

 using namespace std;

 class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                if (text1[i-1] == text2[j-1]) {  // 当前位置的 i 和 j 的字符相同
                    dp[i][j] = dp[i-1][j-1] + 1; // 取左上角的值 + 1
                }else {             // 当前位置的 i 和 j 的字符相同
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);// 取相邻两个数的最大值
                }
            }
        }
        return dp[n][m];
    }
};