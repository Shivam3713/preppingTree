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
    void solve(int col, int row, TreeNode* node, map<int, map<int, vector<int>>>&mp){
        if(!node) return ;// since it reaches a leaf node
        mp[col][row].push_back(node->val); //recording the values
         //traverse
        // when going in the left
        solve(col-1, row+1, node->left, mp);
        //when going right
        solve(col+1, row+1, node->right, mp);

    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //create an empty res to return if root is not present
        vector<vector<int>>res;
        if(!root) return res;
        //a func to traverse and store the data in col->row->vector way so that we can sort if there are multiple values in the same row at the end
        map<int, map<int, vector<int>>>mp;
        solve(0, 0, root, mp); //start from the root

        //after recording values, now arrange them and return the 2d vector
        for(auto col:mp){
            vector<int>ans; /*for curr col*/
            for(auto row: col.second ){
                vector<int>curr = row.second; //access the vector
                sort(curr.begin(), curr.end()); //sort the vector
                //this is the only one instance and there could be multiple instance at this col
                for(int val:curr){
                    ans.push_back(val);
                }
                //push the vector in the resulting 2d vec
            }
            res.push_back(ans);
        }
        return res;




    }
};