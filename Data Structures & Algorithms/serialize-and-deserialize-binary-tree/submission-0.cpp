/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        //ans+=to_string(root->val);

        while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    ans = ans+to_string(node->val)+",";
                }
                else{
                    ans+="#,";
                }
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
            }  
            return ans;
    }
        

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n = data.length();
        if(n==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode* newLeftNode = new TreeNode(stoi(str));
                node->left = newLeftNode;
                q.push(newLeftNode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode* newRightNode = new TreeNode(stoi(str));
                node->right = newRightNode;
                q.push(newRightNode);
            }
        }
        return root;
        
    }
};
