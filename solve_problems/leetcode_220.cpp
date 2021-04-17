/*
    2021 -04 -17

    题目：存在重复元素 III

    给你一个整数数组 nums 和两个整数 k 和 t 。
    请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
    如果存在则返回 true，不存在返回 false。


    主要思路是桶排序， 把满足题目条件的放到一个桶里面， 最后查看是否有桶存在
    相邻的桶也可能满足条件

    （这几天没什么时间， 没有搞得太清楚， 等空闲一点再重新写一下思路）

    看代码：

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 || k <= 0 || t < 0) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            // 当前数
            long x = nums[i];
            // 获取桶号
            long id = get_id(x, t);
            //前面的i-(k+1)是超出了范围的桶,我们把它提前删除,以免影响判断
            if (i - (k+1) >= 0) {
                mp.erase(get_id(nums[i-(k+1)], t));
            }
            // 存在桶， 说明存在题目条件
            if (mp.find(id) != mp.end()) {
                return true;
            }
            // 前面的一个桶存在， 并且里面的值是和当前值之差 <= t
            if (mp.find(id - 1) != mp.end() && abs(mp[id-1]-x) <= t) {
                return true;
            }
            // 后面的一个桶存在， 并且里面的值是和当前值之差 <= t
            if (mp.find(id + 1) != mp.end() && abs(mp[id+1]-x) <= t) {
                return true;
            }
            mp[id] = x;
        }
        return false;
    }

private:
    int get_id(long x, long t) {
        if (x >= 0) {
            return x / (t+1);
        }else {
            return (x+1) / (t+1) -1;
        }
        return -1;
    }

};