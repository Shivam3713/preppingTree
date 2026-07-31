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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        if(!root) return res;
        stack<TreeNode*>st;
        st.push(root);
        //we're pushing right first and left next so that we can take out left first and process right after it, that it how we can do preodertraversal

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right){
              st.push(node->right);
            }
            if(node->left){
              st.push(node->left);
            }
        }
        return res;
    }
};