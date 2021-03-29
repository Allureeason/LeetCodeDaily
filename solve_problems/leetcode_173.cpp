/*  2021-03-28 
*   leetcode question:
*   
*   实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
*   BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。
*   BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
*   boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
*   int next()将指针向右移动，然后返回指针处的数字。
*   注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
*   你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
*
*   解题思路：
*          使用构造时的参数， 利用递归进行中序遍历， 把遍历的值存放到数组中 (vector) 
*          也可以是一个节点， 这题要求返回值就行了。
*          
*            再维护一个下标指针， 用于提取next的值， hasNext() 返回下标指针的值和数组个数的比较
*
*
*   知识点：
*           二叉搜索树的中序遍历， 二叉搜索树
*
*   
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        num = 0;
        InOrder(root, VIO);
    }
    
    int next() {
        return VIO[num++];
    }
    
    bool hasNext() {
        return (num < VIO.size());
    }
private:
    vector<int> VIO;
    int num;
private:
    void InOrder(TreeNode* root, vector<int>& res) {    // 递归进行中序遍历， 把值放入数组中
        if(root == nullptr) return ;
        InOrder(root->left, res);
        res.push_back(root->val);
        InOrder(root->right, res);
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */