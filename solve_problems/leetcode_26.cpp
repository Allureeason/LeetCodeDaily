/*
    2021 -04 -18
    题目：删除有序数组中的重复项
    给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
    不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。


    解题思路： 这道题比较简单， 就是要你把重复的元素删除， 返回删除后的数组长度
             在原数组上修改， 所以我们可以使用双指针， 快指针往后指， 假如快指针和慢指针的值是相等的
             那么快指针往后走， 直到还两个指针指向的值不一样， 就把慢指针后一位的设置为快指针指向的元素
             快指针一直走完这个数组

             时间复杂度为 O(n) n为数组长度
             空间复杂度为 O(1) 没有使用额外的空间

    看代码：
*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 ) return 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};