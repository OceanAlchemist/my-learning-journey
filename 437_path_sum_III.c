/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
long long dfs(struct TreeNode* root, long long targetSum) {
    if (root == NULL) return 0;
    
    long long count = 0;
    if (root->val == targetSum) count++;
    
    count += dfs(root->left, targetSum - root->val);
    count += dfs(root->right, targetSum - root->val);
    
    return count;
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    
    // 以当前节点为起点的路径数 + 左子树的路径数 + 右子树的路径数
    return dfs(root,(long long) targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}
