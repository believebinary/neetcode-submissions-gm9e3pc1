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

class Solution {
public:
    ListNode* newHead = NULL;
    ListNode* mergeTwoList(ListNode* head1, ListNode* head2){
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        ListNode* localHead = NULL;
        ListNode* localCurr = NULL;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                if(localHead == NULL){
                    localHead = curr2;
                    localCurr = localHead;
                }
                else{
                    localCurr->next = curr2;
                    localCurr = localCurr->next;
                }
                curr2 = curr2->next;
            }
            else{
                if(localHead == NULL){
                    localHead = curr1;
                    localCurr = localHead;
                }
                else{
                    localCurr->next = curr1;
                    localCurr = localCurr->next;
                }
                curr1 = curr1->next;
            }
        }
        while(curr1){
            localCurr->next = curr1;
            localCurr = localCurr->next;
            curr1 = curr1->next;
        }
        while(curr2){
            localCurr->next = curr2;
            localCurr = localCurr->next;
            curr2 = curr2->next;
        }
        return localHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return 0;
        }
        ListNode* mergedNode = NULL;
        for(int i = 0; i<lists.size(); i++){
            mergedNode = mergeTwoList(mergedNode,lists[i]);
            newHead = mergedNode;
        }
        return newHead;
    }
};
