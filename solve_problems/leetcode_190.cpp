/*  2021-03-29 
*   leetcode question:
*   颠倒给定的 32 位无符号整数的二进制位。
*
*   进阶:
*       如果多次调用这个函数，你将如何优化你的算法？
*
*
*   解题思路：
*           类似 lc 7, lc 9， 题一样的思想， 把它翻转
*           输入的是一个二进制数， 而不是十进制数
*           取一位时要 取模以2 位数往左移除以2
*/



// 解题代码     时间复杂度O(n)  空间复杂度O(1)
typedef unsigned int uint32_t;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long res = 0;
        for (int i = 0; i < 32; i++) {
            res =  res * 2 + n % 2;    
            n /= 2;
        }
        return res;
    }
};