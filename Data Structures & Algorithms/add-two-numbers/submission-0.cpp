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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;
        ListNode* newHead = NULL;
        ListNode* curr = NULL;
        while(curr1 && curr2){
            int val1 = curr1->val;
            int val2 = curr2->val;
            int sum = val1+val2+carry;
            int digitVal = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digitVal);
            if(newHead == NULL){
              newHead = newNode;
              curr = newHead;
            }
            else{
                curr->next = newNode;
                curr = newNode;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            int val1 = curr1->val;
            int sum = val1+carry;
            int digitVal = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digitVal);
            curr->next = newNode;
            curr = newNode;
            curr1 = curr1->next;
        }
        while(curr2){
            int val1 = curr2->val;
            int sum = val1+carry;
            int digitVal = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digitVal);
            curr->next = newNode;
            curr = newNode;
            curr2 = curr2->next;
        }
        while(carry>0){
            int digitVal = carry%10;
            carry = carry/10;
            ListNode* newNode = new ListNode(digitVal);
            curr->next = newNode;
            curr = newNode;
        }
        return newHead;
    }
};
