#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
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
    vector<int> topView(TreeNode* root) {

        //for a top view in bfs method , the first node at any traversal is the first time we're accessing any node in col
        vector<int>res;
        if(!root)return res;
        map<int, int>mp;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*,int>p = q.front();
            q.pop();
            if(mp.find(p.second) == mp.end()){
                mp[p.second] = p.first->val;
            }
            if(p.first->left) q.push({p.first->left, p.second-1});
            if(p.first->right) q.push({p.first->right, p.second+1});

        }

        for(auto col: mp){
            res.push_back(col.second);
        }
        return res;
    }
};

// Paste your Solution class here

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