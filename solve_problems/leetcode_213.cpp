/*
    2021 -04 -15

    题目：打家劫舍 II

    题目分析： （详细题目看leetcode213题）

    我们可以先去把 打家劫舍 198题 做了， 本题是198题的一个升级 （就是多了个约束条件）

    ------leetcode 198题 打家劫舍 分析：

    本题是一个动态规划， 对于动态规划的问题， 主要就是搞清楚它的边界条件、初始条件 和 状态转移方程
    首先我们思考它的边界条件， 1.当数组为空的时候，返回的肯定是0
                             2.当数组只有一个元素的时候，只能返回唯一的一个值（不拿白不拿）
                             3.当数组只有两个元素的时候， 那么我们就拿最大的一个
    然后我们来思考它的状态转移方程：
                             比如我们现在有一个数组 [1,2,3,1]， 因为不能连续拿， 所以我们要思考的是当前这个值要不要
                             如果要， 那么它的价值是多少， 是否是最大的
                             由初始条件我们可以知道dp[0] = 1; dp[1] = max(1,2) = 2
                             假如第三个数， 我们拿了之后， 由于不能连续， 那么它的价值就是 3 + dp[2 - 1] = 4
                             而不拿的情况下它的价值为 dp[1] = 2 
                             很显然， 我们要取的是最大值， 即dp[2] = 4
                             同理分析， 第四个数要或者不要， 要：2 + 1 = 3  不要：4
                             所以我们可以推倒出来状态转移方程为 
                             dp[i] = max(dp[i-2] + nums[i], dp[i-1])


    然后我们看213题 多了一个约束条件， 那就是头尾两个不能同时要（也就是题目的头尾是相邻的意思）
    那么我们不妨把它分解成两个 198题， 一个是从 0到 n-2 (这里指的是下标) 另一个是从 1到 n-1 (这里指的是下标)
    边界也是和198一样的， 我们去这两个问题返回的最大值就是213题的最优解


    让我们看代码：

*/

#include <algorithm>
#include <vector>

using namespace std;

/*********************先来看198题的代码*********************/ 

class Solution198 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        // 这里没有使用dp数组， 而是使用的两个变量， 滚动的形式， 把空间复杂度优化为 O(1)
        int first = nums[0], second = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) { // 这里滚动状态
            int tmp = second;
            second = max(nums[i] + first, tmp);
            first = tmp;
        } 
        return second;
    }
};

/*********************来看213题的代码*********************/ 
class Solution213 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(rob_sub(nums, 0, n-1), rob_sub(nums, 1, n));
    }
private:
    int rob_sub(vector<int>& nums, int start, int end)
    {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

};

