/*
    2021 -04 -20

    题目：实现 strStr()


    解释一下：strStr(const char* src_, const char* find_)函数是查找src_ 中是否含有find_字符串
            就是判断find_作为src_ 的子串， 返回的是首次出现的位置

    我们可以使用暴力匹配的解法： 
            逐个遍历src_ 和 find_ 当不匹配的时候find_有从头开始匹配
            这样虽然能解决问题， 但是做了很多无用功

    我们可以使用KMP算法来解决多做无用功的问题


    KMP算法： 核心就在需要匹配的字符串的next数组中， 什么是next数组呢？
            next数组就是一个前缀表

            举个例子， 当我们在大学的考试中，都是考过一科之后该科就不需要补考了， 但是没过的就需要补考
            暴力匹配的解法就是学校实行的一种制度， 其中一科没过就全部都重新考（你肯定不想啊）
            KMP算法就是对没考过的进行补考就行了

            那么回来， next数组就是存放失配时需要开始重新匹配的下标
            比如 str_:aabaabaabaac  find_:aabaac 我们匹配的时候是会在find_最后一个元素 c 失配的
            那么我们只需要找到next数组的失配下标， 这里应该是2， 也就是我们只需要从find_中的b开始和src_中失配的位置继续匹配

            这里讲的肯定是不太清楚的，建议有兴趣的小伙伴去看一下详细的KMP算法演算过程

    看代码：
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        if (n == 0) return 0;
        if (m == 0 || m < n) return -1;
        vector<int> next(n, 0);
        get_nextval(needle, next);

        int j = 0;
        int i = 0;

        while (i < m && j < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
                if (j == -1) {
                    i++;
                    j++;
                }
            }
        }
        if (j == n) return i - j;
        return -1;
    }
private:
    void get_nextval(string P, vector<int>& next)
    {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < P.size(); i++) {
            while (j > 0 && P[j] != P[i]) {
                j = next[j - 1];
            }
            if (P[j] == P[i]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = P.size() - 1; i > 0; i--) {
            next[i] = next[i-1];
        }
        next[0] = -1;
    }
};