/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return false;
    
    // 如果是叶子节点，判断当前值是否等于剩余目标值
    if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum;
    }
    
    // 不是叶子，继续往下走
    int remain = targetSum - root->val;
    return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
}
