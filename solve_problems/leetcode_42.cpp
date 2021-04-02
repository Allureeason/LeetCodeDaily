/*  2021-04-02 
*   leetcode question:
*   给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*
*   解题思路：
*   	     我们可以先假设装满水的时候， 也就是 所有柱子的体积 + 能接雨水体积 = 接满雨水时候总体积  
*   	     那么 就可以得到 能接雨水体积 = 接满雨水时候总体积 - 也就是 所有柱子的体积
*   	     编码实现： 1、遍历height求出所有柱子的体积
*                      2、开始遍历每一层的体积， 左右指针分别移动到柱子高度为该成高度的位置
*                         一层的体积为 right - left + 1
*                      3、每一层的高度加起来， 然后 返回 两种体积的差值
*/

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int totalV = 0;
        int fullV = 0;
        int letf = 0;   
        int curH = 1;   // 当前层柱子的高度
        int right = height.size() - 1;
        // 计算出所有柱子的体积和
        for (int h : height)
            totalV += h;
        
        while (letf <= right) 
        {
            while (letf <= right && curH > height[letf]) // 跳过不能装水的位置
                letf++;
            while (letf <= right && curH > height[right]) 
                right--;
            fullV += right - letf + 1;  // 获取每一层满水时的体积
            curH++;
        }
        return fullV - totalV;  // 满水体积减去没有装水的体积，得到答案
    }
};