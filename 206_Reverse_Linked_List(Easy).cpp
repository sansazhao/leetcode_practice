/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//指针的头插法..
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        ListNode* p = new ListNode(0);
        while(head){
            ListNode* next = head->next;
            head->next = p->next;
            p->next = head;
            head = next;
        }
        return p->next;
    }
};