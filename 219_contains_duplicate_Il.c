struct hashTable {
    int key;
    int index;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct hashTable* hash = NULL;
    struct hashTable* tmp = NULL;
    
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hash, &nums[i], tmp);
        if (tmp != NULL) {
            if (i - tmp->index <= k) {
                return true;
            }
            // 更新索引为当前 i
            tmp->index = i;
        } else {
            tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            tmp->index = i;
            HASH_ADD_INT(hash, key, tmp);
        }
    }
    return false;
}
