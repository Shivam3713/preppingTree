/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>&mp){
        if(!node) return;

        if(node->left)  mp[node->left] = node;
        if(node->right) mp[node->right]=node;
        markParent(node->left, mp);
        markParent(node->right, mp);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root) return res;
        unordered_map<TreeNode*, TreeNode*>parent; //to store the parent of each node
        markParent(root, parent);
        map<TreeNode*, bool>visited; //to check if the node is visited or not
        int level =0;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            if(level == k) break;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(curr != root && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]= true;
                }

            }
            level++;
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};