int titleToNumber(char* columnTitle) {
    int res = 0;
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int digit = columnTitle[i] - 'A' + 1;
        res = res * 26 + digit;
    }
    return res;
}
