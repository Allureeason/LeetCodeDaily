/*
    2021 -04-08


    问题：寻找旋转排序数组中的最小值

    解题： 本题也是一个二分查找的题目， 缩小范围来查询最小值




*/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[high] > nums[mid]) {
                high = mid;
            }else {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};