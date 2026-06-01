/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, int targetSum, int** res, int* returnSize, int** returnColumnSizes, int* path, int depth) {
    if (root == NULL) return;
    
    // 记录当前节点
    path[depth] = root->val;
    depth++;
    
    // 叶子节点判断
    if (root->left == NULL && root->right == NULL) {
        if (targetSum == root->val) {
            // 保存当前路径
            int* list = (int*)malloc(depth * sizeof(int));
            for (int i = 0; i < depth; i++) list[i] = path[i];
            res[*returnSize] = list;
            (*returnColumnSizes)[*returnSize] = depth;
            (*returnSize)++;
        }
        return;
    }
    
    // 递归左右子树
    dfs(root->left, targetSum - root->val, res, returnSize, returnColumnSizes, path, depth);
    dfs(root->right, targetSum - root->val, res, returnSize, returnColumnSizes, path, depth);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;
    int* path = (int*)malloc(2000 * sizeof(int));
    
    dfs(root, targetSum, res, returnSize, returnColumnSizes, path, 0);
    
    free(path);
    return res;
}
