/*
    2021 -04 -19
    题目：移除元素
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。



    解题思路： 这道题比较简单， 就是要你把题目给定的元素删除， 返回删除后的数组长度
             在原数组上修改， 所以我们可以使用双指针， 快指针往后指， 假如快指针和目标值是相等的
             那么快指针往后走， 直到两个的值不一样， 就把慢指针的位置设置为快指针指向的元素
             快指针一直走完这个数组

             时间复杂度为 O(n) n为数组长度
             空间复杂度为 O(1) 没有使用额外的空间

    看代码：
*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};