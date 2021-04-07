/*
    2021 -04 -07

    题目：搜索旋转排序数组 II

    解题： 对于查找有序、不完全有序数组元素的，通常使用二分查找法
        本题由于测试数据较小 可以直接暴力搜索，不超时
        同时也可以使用二分查找的方法


*/

#include <vector>

using namespace std;

// 暴力搜索
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return true;
        }
        return false;
    }
};

// 二分查找法

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
