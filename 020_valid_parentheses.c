bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);  // 栈空间
    int top = 0;  // top 指向下一个要放的位置
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;  // 入栈
        } else {
            if (top == 0) return false;  // 栈空，没有左括号
            char left = stack[--top];    // 出栈
            if (c == ')' && left != '(') return false;
            if (c == ']' && left != '[') return false;
            if (c == '}' && left != '{') return false;
        }
    }
    
    free(stack);
    return top == 0;  // 栈空才有效
}
