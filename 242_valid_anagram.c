bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if (len_s != len_t) return false;
    
    for (int i = 0; i < len_s; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    
    return true;
}
