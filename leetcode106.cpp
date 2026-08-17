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
    TreeNode* solve(vector<int>& inorder, vector<int>&postorder, int start, int end, int &idx){
        if(start>end) return nullptr;
        int i = start;
        for(;i<=end;i++){
            if(inorder[i] == postorder[idx])break;
        }
        idx-=1;
        TreeNode* root = new TreeNode(inorder[i]);
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left = solve(inorder, postorder, start, i-1, idx);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = inorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1, idx);
    }
};