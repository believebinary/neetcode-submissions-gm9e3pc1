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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> level;
        level.push(root);

        while(!level.empty()){
           int n = level.size();
           vector<int> levelVec;
           while(n>0){
              TreeNode* node = level.front();
              level.pop();
              if(node != NULL){
                   levelVec.push_back(node->val);
                   if(node->left != NULL){
                      level.push(node->left);
                   }
                   if(node->right != NULL){
                      level.push(node->right);
                   }
              }
              n--;
           }
           result.push_back(levelVec);
        }
        return result;
    }
};
