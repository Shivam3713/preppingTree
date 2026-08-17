/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res ="";
        if(!root) return "#,"; //agar empty tree hai toh return aise kar do
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            //agar curr node null nahi hai toh tabhi append karke process karna hai nahi toh bas "#," append karna hai agar null hua toh
            if(curr != nullptr){
                string val = to_string(curr->val);
                res+=val;
                res+=",";
                q.push(curr->left);
                q.push(curr->right);

            }
            else res+="#,";
        }
        return res;

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        if(token=="#")return nullptr;
        
        TreeNode * root = new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            getline(ss, token, ',');
            if(token != "#"){
                TreeNode* leftnode = new TreeNode(stoi(token));
                curr->left = leftnode;
                q.push(curr->left);
            }
            getline(ss, token, ',');
            if(token != "#"){
                TreeNode*rightnode = new TreeNode(stoi(token));
                curr->right= rightnode;
                q.push(curr->right);
            }

        }
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));