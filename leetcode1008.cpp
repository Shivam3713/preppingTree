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
    TreeNode* constructBST(vector<int>&inorder, vector<int>&preorder, int start, int end, int& idx){
        if(start > end) return nullptr;

        int i= start;
        for(;i<inorder.size();i++){
            if(inorder[i] == preorder[idx]) break;
        }
        TreeNode* node = new TreeNode(inorder[i]);
        idx++;
        node->left = constructBST(inorder, preorder, start, i-1, idx );
        node->right = constructBST(inorder, preorder, i+1, end, idx);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder = preorder;
        sort(begin(inorder), end(inorder));
        int idx =0;
        return constructBST(inorder, preorder, 0, inorder.size()-1, idx);
    }
};