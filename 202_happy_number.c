struct hashTable {
    int key;
    UT_hash_handle hh;
};

int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    struct hashTable* visited = NULL;
    struct hashTable* tmp = NULL;

    while (n != 1) {
        // 检查是否已存在
        HASH_FIND_INT(visited, &n, tmp);
        if (tmp != NULL) {
            return false;  // 出现循环，不是快乐数
        }

        // 将当前 n 加入哈希表
        tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
        tmp->key = n;
        HASH_ADD_INT(visited, key, tmp);

        // 计算下一个数
        n = getNext(n);
    }

    return true;
}
