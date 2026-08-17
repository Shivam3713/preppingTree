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
    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int start,int end, int& idx){
        if(start > end) return NULL; 

        int i= start; //since we need to start from the left and goto the right to find the root
        // everything from the left of the root in inorder is the left subtree and on the right it's the right subtree
        for(;i<=end;i++){
            if(inorder[i] == preorder[idx]) break;
        }
        idx++;
        TreeNode* root = new TreeNode(inorder[i]);
        root->left  = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx =0;
        return solve(preorder, inorder, 0, preorder.size()-1, idx);
    }
};