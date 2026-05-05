/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    
    // 交换左右孩子
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // 递归翻转左右子树
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
