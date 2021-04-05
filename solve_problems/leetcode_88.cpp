/*
    2021 - 04 -05

    题目：合并两个有序数组


给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

解题分析：
    因为nums1的有效数为前m个，而且nums1的总空间大小为m+n
    那么可以考虑从后面放数据
    我们使用两个指针分别指向nums1的m位置和nums2的n位置，逐一比较，大的依次从m+n往前放入

*/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        n -= 1;
        m -= 1;
        for (end; end >= 0; end-- ) {
            if (n >=0 && m >= 0) {
                nums1[end] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            }
            else if (n >= 0) {
                nums1[end] = nums2[n--];
            }
        }
    }
};