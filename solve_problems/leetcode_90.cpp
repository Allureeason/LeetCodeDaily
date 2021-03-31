
/*  2021-03-31 
*   leetcode question:
*   
*   给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
*
*   解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。。
*
*   
*       思路：
*           可以先去做 LeetCode 78 题， 求子集， 78题所给的nums不含重复的元素
*           78 题思路： 通过递归实现每一种子集放入， 先选取，后不选取， 两种情况分别递归
*           
*
*
*           在  78题的基础上 多加一个筛选， 用一个set存放，已放入的子集
*           在每次插入子集时判断是否已存在，不存在则放入到res中 
*/



#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        set<vector<int>> uset;
        res.push_back({});
        sort(nums.begin(), nums.end());
        generate(0, nums, sub, res, uset);
        return res;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &sub, 
    vector<vector<int>> &res, set<vector<int>> &uset)
    {
        if (i >= nums.size()) return ;
        sub.push_back(nums[i]);
        if (uset.find(sub) == uset.end()) {
            res.push_back(sub);
            uset.insert(sub);
        }
        generate(i+1, nums, sub, res, uset);
        sub.pop_back();
        generate(i+1, nums, sub, res, uset);  
    }

};