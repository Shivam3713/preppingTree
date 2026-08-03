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
    int solve(TreeNode* node, int&sum){
        if(!node) return 0; //since we reach a null node return 0;
        int left = max(0, solve(node->left, sum)); //at current node we'll ask to sovle it for the left side taking min as 0 since there could be negative numbers
        int right= max(0, solve(node->right, sum)); //for right side and same taking care of negative values
        sum = max(sum, node->val+left+right); //at current node we're computing the path sum from the left and the right including current node val
        return node->val+max(left, right); //what the parent expects is? since we're computing result in sum
        //  we need other node to check too, that, okay give me the best from the left including the child val and 
        // it'll calcutle for the right the same way
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum =0;
        if(!root) return sum;
        solve(root, sum);
        return sum;
    }
};