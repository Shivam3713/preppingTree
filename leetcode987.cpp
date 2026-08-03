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
    void solve(int row, int col, TreeNode*node,  map<int, map<int, vector<int>>>&mp){
        if(!node ) return;
        
        mp[col][row].push_back(node->val);

        if(node->left){
            solve(row+1, col-1, node->left, mp);
        }
        if(node->right){
            solve(row+1, col+1, node->right,mp);
        }


    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        map<int, map<int, vector<int>>>mp;
        //since we need row and col and we need to store a list of nodes and also need sorting, so this is a useful ds
        solve(0, 0, root, mp); //calling the root
        for(auto &col: mp){
            vector<int>ans;
            for(auto &row:col.second){
                vector<int>curr = row.second;
                sort(curr.begin(), curr.end());
                for(int val: curr){
                    ans.push_back(val);
                }
                
            }
            res.push_back(ans);
        }
        return res;

    }
};