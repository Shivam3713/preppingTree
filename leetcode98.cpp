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
    void dfs(TreeNode* node, vector<int>&ans){
        
        if(node->left)dfs(node->left, ans);
        ans.push_back(node->val);
        if(node->right)dfs(node->right, ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        dfs(root, ans);
        bool flag = true;
        for(int i=1;i<ans.size();i++){
            if(ans[i] <= ans[i-1]){
                flag= false;
                break;
            }
        }
        return flag;
    }
};