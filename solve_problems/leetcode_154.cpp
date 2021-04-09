/*
    2021 -04-09


    问题：寻找旋转排序数组中的最小值||

    解题： 本题也是一个二分查找的题目， 缩小范围来查询最小值
            对比153题， 它含有重复的元素， 我们这里使用暴力缩小范围的方法进行处理相同元素



*/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2; 
            if (nums[mid] > nums[right]) {   // 中间值是大于右边，则最小值在右半部分
                left = mid + 1;              // 并且nums[mid] 不是最小值， 缩小范围
            }else if (nums[mid] < nums[right]) { // 中间值是小于右边，则最小值在左半部分
                right = mid;                 // 并且nums[mid] 可能是最小值， 缩小范围
            }else if (nums[mid] == nums[right]){    // 中间值和右边值相等，那么说明是重复元素
                right--;                        // 暴力缩短右边范围
            }
        }
        return nums[left];
    }
};