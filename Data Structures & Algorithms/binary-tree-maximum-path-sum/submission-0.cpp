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
    int sum;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);

        int foundBelowOnly = l+r+root->val;
        int foundOnOneSideAndRoot = max(l,r)+ root->val;
        int onlyRoot = root->val;

        sum = max({sum,foundBelowOnly,foundOnOneSideAndRoot,onlyRoot});

        return max(foundOnOneSideAndRoot,onlyRoot);
    }
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN ;
        solve(root);
        return sum;
    }
};
