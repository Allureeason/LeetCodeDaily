/*  2021-03-25 
*   leetcode question:
*   存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，
*   只保留原始链表中 没有重复出现 的数字。返回同样按升序排列的结果链表。
*
*
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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {   //空链表， 直接返回
        if (!head)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);    //用于返回
        ListNode *cur = dummy->next;    //当前节点
        ListNode *prev = dummy;         //前驱节点

        while (cur) //循环条件
        {
            while (cur->next && cur->val == cur->next->val)
            {   //重复元素， 移动cur节点 , 可移动到相同元素的最后一个
                cur = cur->next;    
            }
            if (prev->next != cur)  //如果有相同的元素，那么当前节点的位置 不会和 前驱节点相等
            {
                prev->next = cur->next; //前驱指向当前节点的下一节点， 相当于删除重复元素的节点
            }
            else    //否则，两个节点相等， 说明，这个节点和后面的元素的值不相等
            {
                prev = cur; //设置当前节点为下一次循环的前驱
            }
            cur = cur->next;    //节点后移
        }
        return dummy->next;
    }
};