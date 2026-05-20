/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, char** res, int* returnSize, int* path, int depth) {
    if (root == NULL) return;
    
    // 记录当前节点
    path[depth] = root->val;
    depth++;
    
    // 叶子节点：生成路径
    if (root->left == NULL && root->right == NULL) {
        char* str = (char*)malloc(100 * sizeof(char));
        int len = 0;
        for (int i = 0; i < depth; i++) {
            len += sprintf(str + len, "%d", path[i]);
            if (i != depth - 1) len += sprintf(str + len, "->");
        }
        res[(*returnSize)++] = str;
        return;
    }
    
    dfs(root->left, res, returnSize, path, depth);
    dfs(root->right, res, returnSize, path, depth);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** res = (char**)malloc(100 * sizeof(char*));
    int* path = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    dfs(root, res, returnSize, path, 0);
    free(path);
    return res;
}
