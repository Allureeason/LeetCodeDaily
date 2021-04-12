/*
    2021 -04 -13

    问题：二叉搜索树节点最小距离

    给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。


    由于这里不好放置图片， 建议去leetcode看示例的图片

    解题分析： 题目的意思就是让我们找到两个不同的节点，它们满足差值是任意两个节点中最小
                我们可以对这颗二叉树进行排序（升序，可以直接使用中序遍历）
                然后两两计算差值，取最小的作为答案

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

#include <algorithm>
#include <limits.h>

using namespace std;

struct TreeNode {
      int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        InOrder(root, pre, ans);
        return ans;
    }
private:
    void InOrder(TreeNode* root, int& pre, int& ans)
    {
        if (root == nullptr) return ;
        InOrder(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        }else { // 递归放回时进行对本次的值和上一次的值求差值
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        InOrder(root->right, pre, ans);
    }
};