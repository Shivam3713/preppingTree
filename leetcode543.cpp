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
    int solve(TreeNode*node, int &result){
        if(!node) return 0;
        int left = solve(node->left, result);
        int right = solve(node->right, result);
        //computing diameter at current node with its left and right
        result = max(result, left+right);
        //we're storing the ans in result but we also need to check for other nodes to
        // so inorder for those nodes to participate in the recursion
        //we'll pass them the max of left and right +1 so that they can compute their own result and update it to the result variable
        // the ans is being stored in the result variable itself
        //  the recursion if for allowing all nodes to participate and find the max diameter
        return 1+max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //if root is null just return diameter as 0;
        if(!root) return  0;
        int result = -1e9;
        solve(root, result);
        return result;
    }
};