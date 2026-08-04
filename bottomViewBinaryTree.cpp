#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution{
    private: void dfs(TreeNode* node, int col, int row, map<int, pair<int, int>>&mp){
        if(!node) return;
        if(mp.find(col) == mp.end() || row >=mp[col].first){
            mp[col].first = row;
            mp[col].second = node->val;
        }
        dfs(node->left, col-1, row+1, mp);
        dfs(node->right,col+1, row+1, mp);
    }
    public: vector<int>topView(TreeNode*root){
        vector<int>res;
        if(!root)return res;
        map<int, pair<int, int>>mp;
        dfs(root, 0, 0, mp);
        
        for(auto it: mp){
            res.push_back(it.second.second);
        }
        return res;
    }
};
int main() {

    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7

        Top View:
        4 2 1 3 7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.topView(root);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}