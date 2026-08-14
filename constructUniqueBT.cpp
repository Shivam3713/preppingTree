class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here

            // we need exactly one inorder and remainging to be pre or post to return true;
            if( a == b & a == 2) return false;
            if(a == 2) return true;
            if(b == 2) return true;
            return false;
		}
};