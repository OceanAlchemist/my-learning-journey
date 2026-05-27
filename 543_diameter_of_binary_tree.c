/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root, int* diameter) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left, diameter);
    int right = maxDepth(root->right, diameter);
    if (left + right > *diameter) *diameter = left + right;
    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    maxDepth(root, &diameter);
    return diameter;
}
