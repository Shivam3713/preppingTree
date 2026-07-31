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
    vector<int> inorderTraversal(TreeNode* root) {
        //first use a copy pointter as the same as root and this is what we'll use 
        vector<int>ans;
        if(!root) return ans;
        TreeNode*curr = root;
        stack<TreeNode*>st;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            //now we came out and curr became null
            curr= st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};