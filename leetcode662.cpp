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
    int widthOfBinaryTree(TreeNode* root) {
        //we're solving this question in bfs since it has level oder traversal and it gives the 
        int maxWidth = 0;
        if(!root)  return maxWidth;
        queue<pair<TreeNode*,unsigned int>>q;
        //since we need to store the node and it's index to get the current width we'll use this 
        q.push({root, 0}); //0 since it's at 0th index
        while(!q.empty()){
            auto front = q.front();
            auto back = q.back();
            int size = q.size();
            int width = back.second-front.second+1; //calculating current width of the level from it's left most and right most nodes
            //now we have the current lvel in the queue and we need to process it and it's children
            while(size--){
                auto currNode = q.front();
                q.pop();
                //after popping process it's children
                if(currNode.first->left) q.push({currNode.first->left, (currNode.second*2)+1});
                if(currNode.first->right) q.push({currNode.first->right , (currNode.second*2)+2});
                
            }
                maxWidth = max(maxWidth, width);
        }
        return maxWidth;
    }
};