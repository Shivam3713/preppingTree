/*
  Company Tags : Microsoft, Amazon, Samsung, Snapdeal, PayU, Accolite, OYO Rooms, Hike, FactSet, Kritikal Solutions, Tokopedia (2021)
  Seems pretty important :-)
*/

#include <iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int val) {
        this->val = val;
        this->left = this->right = NULL;
	}
};

Node* newNode(int data) {
	return new Node(data);
}
void leaf(Node*node, vector<int>&ans){
    if(!node) return;
    if(node->left  == nullptr && node->right ==nullptr){
         ans.push_back(node->val);
         return; //since we reached a leaf node from the recursio call for the particular node that called it
    }
    leaf(node->left, ans);
    leaf(node->right, ans);
}
void leftSide(Node* root, vector<int>&ans){
    if(!root) return;
    if(root->left == nullptr && root->right == nullptr) return ;
    if(root->left){
        ans.push_back(root->val);
        leftSide(root->left, ans);
    }
    else if(root->right){
        ans.push_back(root->val);
        leftSide(root->right, ans);
    }

}
void rightSide(Node* root, vector<int>&ans){
    if(!root) return;
    if(root->right == nullptr && root->left == nullptr) return ;
    if(root->right){
        rightSide(root->right,ans);
        ans.push_back(root->val);
    }
    else if(root->left){
        rightSide(root->left, ans);
        ans.push_back(root->val); //here pushing is done after recursion such that we get the reverse order of the node-val
    }
    

}
vector <int> printBoundary(Node *root)
{
    vector<int>ans;
    if(!root) return ans;
    ans.push_back(root->val);
    leftSide(root->left, ans);
    leaf(root->left, ans);
    leaf(root->right, ans);
    rightSide(root->right, ans);
    return ans;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(8);
    	root->right->left->left = newNode(9);
	root->right->left->right = newNode(10);

	vector<int> result = printBoundary(root);
	for(int i:result)
        	cout << i << " ";

	return 0;
}