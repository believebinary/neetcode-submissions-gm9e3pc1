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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listLen =0;
        ListNode* curr = head;
        while(curr){
           curr = curr->next;
           listLen++;
        }
        int elementFromFront = listLen - n + 1;

        if(elementFromFront<=0){
            return head;
        }
        if(elementFromFront == 1){
            if(head->next != NULL){
                return head->next;
            }
            else{
                return NULL;
            }
        }
        int i =1;
        curr = head;
        ListNode* prev = NULL;
        while(i<elementFromFront){
           prev = curr;
           curr = curr->next;
           i++;
        }
        if(curr->next==NULL){
            prev->next = NULL;
        }
        else{
            prev->next = curr->next;
        }

        return head;
    }
};
