/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;

    void dfs(Node* cloneNode, Node* node){
        for(Node* nd : node->neighbors){
            if(mp.find(nd)==mp.end()){
                Node* newCloneNode = new Node(nd->val);
                mp[nd] = newCloneNode;
                cloneNode->neighbors.push_back(newCloneNode);

                dfs(newCloneNode,nd);
            }
            else{
                cloneNode->neighbors.push_back(mp[nd]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        mp.clear();
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;

        dfs(cloneNode,node);
        return cloneNode;
    }
};
