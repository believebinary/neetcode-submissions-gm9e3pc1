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
    ListNode* rev(ListNode* head){
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
           ListNode* temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revList = rev(slow);

        ListNode* curr = head;
        while(revList->next!=NULL){
             ListNode* currNext = curr->next;
             curr->next = revList;
             ListNode* revNext = revList->next;
             revList->next = currNext;

             curr = currNext;
             revList = revNext; 
        }
    }
};
