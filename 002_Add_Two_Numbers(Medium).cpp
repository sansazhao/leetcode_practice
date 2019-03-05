/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// case: [1,8] [0]
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, a, b;
        bool carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while(l1 || l2){
            if(!l1) 
                a = 0;
            else{
                a = l1->val;
                l1 = l1->next;
            }
            if(!l2) 
                b = 0;
            else{
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + carry;
            carry = sum >= 10;
            tmp->val = sum % 10;
            tmp->next = l1 || l2 || carry? new ListNode(1) : NULL;
            tmp = tmp->next;
        }
        return res;
    }
};
