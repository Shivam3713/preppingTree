#include <bits/stdc++.h>
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
private:
    void markParentAndFindTargetNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp, int target, TreeNode*& start){
        // if(!root) return; //commenting this base case since im already checking in the recursion
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        if(root->val == target) start = root;
        if(root->left)markParentAndFindTargetNode(root->left, mp, target, start);
        if(root->right)markParentAndFindTargetNode(root->right, mp, target, start);

    }

public:
    int minTime(TreeNode* root, int target){
        int time = 0;
        if(!root) return time;
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* start = nullptr;
        markParentAndFindTargetNode(root, parent, target, start);
        map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(node != root && !visited[parent[node]]){
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
                
            }
            time+=1;
        }
        return time-1; //since the target is already set to fire
        
        

    
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->left->left->right = new TreeNode(7);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;

    cout << obj.minTime(root, 1) << endl;

    return 0;
}