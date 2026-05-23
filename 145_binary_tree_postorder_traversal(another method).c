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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    struct TreeNode** s1 = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    struct TreeNode** s2 = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1) {
        struct TreeNode* cur = s1[top1--];
        s2[++top2] = cur;

        // 注意：先左后右，这样 s2 的顺序是：根、右、左
        if (cur->left) s1[++top1] = cur->left;
        if (cur->right) s1[++top1] = cur->right;
    }

    while (top2 != -1) {
        res[(*returnSize)++] = s2[top2--]->val;
    }

    free(s1);
    free(s2);
    return res;
}
