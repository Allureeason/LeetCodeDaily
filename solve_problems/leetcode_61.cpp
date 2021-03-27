/*  2021-03-27 
*   leetcode question:
*   给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*
*   解题思路：
*   	       画图可知，每个节点移动k个位置就如 倒数第k个节点作为头结点， 倒数第k+1个元素作为尾节点
*   	       只需找到倒数第k+1个节点， 将它的下一个元素置为头结点， 它指向nullptr, 最后一个节点指向原头结点
*   	       使用快慢指针， 可参考找到链表中的倒数第k个节点题目
*
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* cur = head;
        int len = 0;
        //get len
        while(cur) {
            cur = cur->next;
            len++;
        }
        int n = k % len;    //mod len, get need go n step 
        if(!n) return head;

        ListNode* fast = head, *slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast->next) {
            fast = fast->next;
            slow =slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return ans;

    }
};
