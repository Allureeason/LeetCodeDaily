/*  2021-03-29 
*   leetcode question:
*   我们使用的除法是地板除法（floor division），所以 10 * 9 / 8 等于 11。这保证结果是一个整数。
*   实现上面定义的笨函数：给定一个整数 N，它返回 N 的笨阶乘。
*
*   
*
*
*   解题思路：
*           使用栈来记录每前三个数的运算值，N*(N-1)+(N-1) 为一个周期， 而后面的则看成 -N*(N-2)+(N-3)
*           用 先进一个数，然后对栈顶元素进行* +操作， 结束一个周期, 再把-(N - 3) 也就是第四个数的负数再入栈
*           最后到了最后一个元素后，把栈全部元素相加起来， 就是答案
*/


#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        int res = 0;
        int i = 0;
        stk.push(N);
        N -= 1;
        while (N > 0) {
            if (i%4 == 0) {
                stk.top() *= N;
            }
            else if (i%4==1) {
                stk.top() /= N;
            }
            else if (i%4==2) {
                stk.top() += N;
            }
            else {
                stk.push(-N);
            }
            N--;
            i++;
        }

        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};