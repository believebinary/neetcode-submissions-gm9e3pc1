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
    bool isValidBSTSolve(TreeNode* root, int leftLimit,int rightLimit){
        if(root == NULL){
            return true;
        }
        if(root->val <= leftLimit || root->val >= rightLimit){
            return false;
        }
        return isValidBSTSolve(root->left,leftLimit, root->val ) && isValidBSTSolve(root->right,root->val, rightLimit );

    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isValidBSTSolve(root,INT_MIN,INT_MAX);
        
    }
};
