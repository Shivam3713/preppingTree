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
class NodeValue{
    public:
    int minNode ;
    int maxNode;
    int sum;
    NodeValue(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum =sum;
    }
};
class Solution {
    int ans = 0;
private: 
        NodeValue dfs(TreeNode* root){
            if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

            auto left = dfs(root->left);
            auto right =dfs(root->right);
            if(left.maxNode < root->val && right.minNode > root->val){
                int sum = left.sum+right.sum+root->val;
                ans = max(ans, sum);
                return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum);
            }
            return NodeValue(INT_MIN, INT_MAX, 0);
            

        }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};