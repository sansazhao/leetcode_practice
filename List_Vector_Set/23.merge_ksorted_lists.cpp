/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {      //021 合并2个List解法复用
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {       //不断二分-合并，除递归栈外无额外空间
        int num = lists.size();
        if (num == 0) return NULL;
        while (num > 1) {
            int k = (num + 1) / 2;
            for (int i = 0; i < num/2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            num = k;
        }
        return lists[0];
    }
};