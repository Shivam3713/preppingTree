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
private:
    void dfs(TreeNode*node, int row, vector<int>&res){
        
        if(row == res.size()){
            res.push_back(node->val);
        }
        //interchange the order of these two below lines to get the left side view of the binary tree
        if(node->right) dfs(node->right, row+1, res);
        if(node->left) dfs(node->left, row+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        dfs(root, 0, res);
    }
    return res;
};