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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;
    struct TreeNode* cur = root;

    while (cur != NULL || top != -1) {
        // 一路向左，全部压栈
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        // 弹出栈顶
        cur = stack[top--];
        // 访问（记录）
        res[(*returnSize)++] = cur->val;
        // 转向右子树
        cur = cur->right;
    }

    free(stack);
    return res;
}
