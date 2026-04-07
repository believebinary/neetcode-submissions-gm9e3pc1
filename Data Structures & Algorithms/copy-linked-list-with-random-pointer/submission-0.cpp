/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        unordered_map<Node*,Node*> mp;
        if(curr==NULL ){
            return NULL;
        }
        Node* prev = NULL;
        Node* newHead = NULL;
        while(curr){
            Node* newNodeCreated = new Node(curr->val);
            mp[curr] = newNodeCreated;
            if(newHead==NULL){
                newHead = newNodeCreated;
                prev = newHead;
            }
            else{
                prev->next = newNodeCreated;
                prev = prev->next;
            }
            curr = curr->next;
        }
        curr = head;
        Node* startNode = newHead;
        while(curr){
            startNode->random = mp[curr->random];
            curr = curr->next;
            startNode=startNode->next;
        }
        return newHead;



    }
};
