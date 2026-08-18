#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        // your code goes here
        int floor = INT_MIN, ceil = INT_MAX;        //floor = res[0] and ceil = res[1]
        vector<int>res;
        if(!root) return res;
        while(root){
            if(root->val <= key){
                if(floor < root->val) floor= root->val;
                root=root->right;
            }
            else{
                if(ceil > root->val)ceil = root->val;
                root= root->left;
            }
        }
        res.push_back(floor);
        res.push_back(ceil);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int key = 7;

    Solution obj;

    vector<int> ans = obj.floorCeilOfBST(root, key);

    cout << "Floor: " << ans[0] << endl;
    cout << "Ceil: " << ans[1] << endl;

    return 0;
}