/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (abs(leftHeight - rightHeight) > 1) return false;
    
    return isBalanced(root->left) && isBalanced(root->right);
}
