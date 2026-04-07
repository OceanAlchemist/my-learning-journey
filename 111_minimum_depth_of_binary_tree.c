/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    // 如果左子树为空，返回右子树的深度 + 1
    if (root->left == NULL) return rightDepth + 1;
    // 如果右子树为空，返回左子树的深度 + 1
    if (root->right == NULL) return leftDepth + 1;
    
    // 左右都不为空，返回较小的 + 1
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}
