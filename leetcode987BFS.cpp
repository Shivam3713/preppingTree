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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // we need to store col, row and node at it
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<pair<TreeNode*, pair<int, int>>>q;
        // {node, {row, col}}
        map<int, map<int, vector<int>>>mp;
        // {col, row, {vector of node->val}}
        q.push({root, {0, 0}});
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>>p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;
            mp[col][row].push_back(node->val);
            if(node->left)q.push({node->left, {row+1, col-1}});
            if(node->right)q.push({node->right, {row+1, col+1}});
        }

        for(auto col: mp){
            vector<int>calc;
            for(auto row: col.second){
                vector<int>curr = row.second;
                sort(curr.begin(), curr.end());
                for(int val: curr){
                    calc.push_back(val);
                }
            }
            ans.push_back(calc);
        }
        return ans;

    }
};