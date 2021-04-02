/*  2021-03-30 
*   leetcode question:
*   编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
*
*   每行中的整数从左到右按升序排列。
*   每行的第一个整数大于前一行的最后一个整数。
*
*
*
*   
*/

#include <iostream>
#include <vector>

using namespace std;

//  暴力解法， 直接暴力搜索， 搜索到返回true    否则返回false
//  时间复杂度O(n^2)
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int v : matrix[i]) {
                if(v == target) return true;
            }
        }
        return false;
    }
};

//  定位加二分查找  先找到target所在行， 然后通过二分查找搜索target是否存在
//  时间复杂度 O(m + log n) m 为搜索位置的次数， n为一行的长度
//  可优化为 O(log m + log n)   搜索行也用二分查找

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][matrix[i].size()-1] >= target) {
                n = i;
                break;
            }
        }
        int low = 0, high = matrix[n].size() - 1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (matrix[n][mid] > target) {
                high = mid - 1;
            }
            else if (matrix[n][mid] < target) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};