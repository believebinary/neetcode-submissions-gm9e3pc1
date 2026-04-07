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

    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftLen = solve(root->left);
        if(leftLen == -1){
            return -1;
        }
        int rightLen = solve(root->right);
        if(rightLen == -1){
            return -1;
        }
        if(abs(leftLen-rightLen)>1){
            return -1;
        }
        return 1+ max(leftLen,rightLen);
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        int n = solve(root);
        if(n==-1){
            return false;
        }
        return true;
    }
};
