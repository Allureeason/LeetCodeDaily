/*  2021-03-24 
*   leetcode question:
*   给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，
*   并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
*   如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 
*
*   进阶：很容易想到时间复杂度为 O(n^2) 的解决方案，你可以设计一个时间复杂度为 O(n logn) 或 O(n) 的解决方案吗？
*/

#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

/*解法一：暴力解法 时间复杂度O(n^2) */

bool find132pattern_1(vector<int>& nums) {
    //特殊情况
    if(nums.size() < 3) return false;

    //暴力搜， 维护左边最小值
        int n = nums.size();
        int left_min = nums[0];
        for(int j = 1; j < n - 1; j++) {
            for(int k = n-1; k > j; k--) {
                if(left_min < nums[k] && nums[j] >nums[k]) {
                    return true;
                }
                left_min = min(nums[j], left_min);
            }
        }
        return false;
}

/*  解法二: 使用单调栈  */

bool find132pattern_2(vector<int>& nums) {
        stack<int> stk;
        int num_k = INT_MIN;

        for(int i = nums.size() - 1; i >= 0; i--) { //从右向左维护一个单调递减栈
            
            if(nums[i] < num_k) return true;    //满足条件，返回
            while(!stk.empty() && stk.top() < nums[i]) {    //维护递减栈
                num_k = stk.top();
                stk.pop();
            }         
            stk.push(nums[i]);
        }
        return false;
    }