/*
    2021 -04 -14

    问题：实现 Trie (前缀树)


    题目分析： （详细题目看leetcode208题）

    这里的的前缀数也可以叫做字典树， 什么是字典树呢？
    我在这里大概简述一下（以我个人的理解来叙述，我也今天才学习到）

    根节点下面有26个子节点， 也就是26个字母a-z （这里应该是不区分大小写的，不然更多）
    a b c d e ......w x y z
    可以把这个树和二叉树对比， 那么它就像一个26叉树（个人叫法， 不对勿喷）

    大概是这个样子， 当我们要去找某一个字符串是否在树上的时候， 
    我们只需遍历每个字符， 直到找完全部字符就返回true， 一旦某字符在树节点上不存在，就返回false
    插入也是一样的， 我们找要插入的字符是否存在， 存在就往下找， 不存在就插入该字符对于的节点

    由于这样子使用了很多的空间， 那么这个树的检索速度就会很快， 基本遍历字符串长度就能得到是否存在该字符串


    看代码：
*/

#include <algorithm>
#include <string>

#include <string.h>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : isword(false) { //  初始化
        memset(children, 0, sizeof(children));
    }   
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p = this;
        for (char ch : word) {
            if (p->children[ch - 'a'] == nullptr) { // 不存在则插入
                p->children[ch - 'a'] = new Trie();
            }
            p = p->children[ch - 'a']; // 存在和插入后都要指向一下个子节点， 遍历
        }
        p->isword = true; // 存放完整个字符串的时候就要设置最后的一个字符串 的isword为true，
                        //当我们找的时候，还要验证这个字符串是否为完整串还是子串, 因为存放进去的是一个完整的字符串
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for (char ch : word) {
            if (p->children[ch - 'a'] == nullptr) { // 为空即为不存在该节点，就是字符对于的子节点
                return false;          // 直接返回false
            }
            p = p->children[ch - 'a']; // 指针往下走
        }
        return p->isword;   // 遍历完要搜索的字符串， 
                            // 还要判断最后节点的isword是否为true，假如是false 说明遍历完的目标字符串仅仅是这条路径上的一个子串
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {    // 这个方法只是检索是否存在目标前缀 （目标子串，下标从0开始的）
        Trie* p = this;
        for (char ch : prefix) {
            if (p->children[ch - 'a'] == nullptr) {     // 某一节点不存在的时候，说明不存在目标前缀，返回false
                return false;
            }
            p = p->children[ch - 'a']; // 指针往下找
        }
        return true;    // 走完目标前缀，说明存在，返回true
    }

private:
    bool isword;    // 对某一节点进行设置标志，即当前节点是否为某一插入过的字符串的结尾
    Trie* children[26]; // 26个字节点  
};