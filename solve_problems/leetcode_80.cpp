/*
    2021 -04 -06
    
    题目：删除有序数组中的重复项 II （26题的一个升级版）
    这里的元素允许最多存在两个

    解题思路： 使用双指针， 快慢指针之间相差一个元素  fast - slow = 2
            当两个指针指向的元素相同使， 说明出现了两个以上该元素，那么快指针移动到不相同的元素上
            把不同的元素放到slow的位置 （我们同时初始化slow和fast都为2） 
            这样容易找回第三个相同元素的位置
    
    代码如下：

*/
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int fast = 2, slow = 2; 
        while (fast < nums.size()) {
            if (nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];    
                slow++;
            }
            fast++;
        }
        return slow;
    }
};