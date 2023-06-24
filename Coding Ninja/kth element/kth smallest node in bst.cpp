//Time Complexity: O(N)

//Space Complexity: O(Height)

 

int kthSmallest(TreeNode<int> *root, int &k)
{
	// Recursive Approach
    // BackTracking: Inorder Traversal
    // Time Complexity: O(N)
    // Space Complexity: O(Height)
    // Base Case
    if(root == NULL) return -1;

    // Left 
    int left = kthSmallest(root->left, k);
    if(left != -1) return left;

    // Current Node 
    k--;
    if(k == 0) return root->data;
    
    // Right
    int right = kthSmallest(root->right, k);
    if(right != -1) return right;
    
    return -1;
}