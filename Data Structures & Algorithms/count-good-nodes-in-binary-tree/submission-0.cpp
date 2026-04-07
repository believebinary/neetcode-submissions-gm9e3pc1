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
    // void solve(TreeNode* root,int res, int val){
    //     if(root == NULL){
    //         return;
    //     }
        
    // }
    int goodNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,int>> levelQueue;
        levelQueue.push({root, INT_MIN});
        while(!levelQueue.empty()){
            auto [node , highest] = levelQueue.front();
            levelQueue.pop();
            if(node != NULL){
                if(node->val >= highest){
                    ans++;
                }  
            }
            if(node->left){
                levelQueue.push({node->left, max(highest,node->val)});
            }
            if(node->right){
                levelQueue.push({node->right, max(highest,node->val)});
            }
        }
        return ans;


    }
};
