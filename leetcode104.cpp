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
    int maxDepth(TreeNode* root) {
        // int ans = 0;
        // if(!root) return ans;

        // int lh=0, rh=0;
        // if(root->left) lh =maxDepth(root->left);
        // if(root->right) rh = maxDepth(root->right);
        // return 1+max(rh, lh);

        //the above was done using recursion, we can do that using dfs O(N) 
        queue<TreeNode*>q;
        if(!root) return 0;
        q.push(root);
        int height =0;
        while(!q.empty()){
            height++;
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return height;
    }
};