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
    ListNode* currHead = NULL;
    pair<ListNode*,ListNode*> reverse(ListNode* head,int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = head;
        ListNode* returnNode = NULL;
        int n = k;
        while(n>0){
            curr = curr->next;
            n--;
        }
        returnNode = curr;
        curr = head;
        while(k>0){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k--;
        }
        
        currHead = prev;
        return {tail,returnNode};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while(curr){
            length++;
            curr= curr->next;
        }
        int interations = length/k;
        ListNode* nextNode = head;
        ListNode* newhead = NULL;
        ListNode* currTail = NULL;

        while(interations){
            
            pair<ListNode*,ListNode*> result = reverse(nextNode,k);
            ListNode* latestTail = result.first;
            nextNode = result.second;
            if(currTail){
                currTail->next = currHead;
                currTail = latestTail;
            }
            else{
                currTail = latestTail;
            }
            if(newHead == NULL){
                newHead = currHead;
            }
            interations--;
        }
        if(nextNode){
            currTail->next = nextNode;
        }
        return newHead;
    }
};
