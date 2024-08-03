#include <stdio.h>
#include <string.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN + 1]; // 存储串的一维数组
    int length;          // 串的当前长度
} SString;               // 串的顺序存储结构

int Index_BF(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length; // 返回匹配的第一个字符的下标
    } else {
        return 0; // 模式匹配不成功
    }
}

int main() {
    SString mainStr = {"ababcabcababcabcabc", 18}; // 主串
    SString pattern = {"abcabcabc", 9};            // 模式串

    int pos = Index_BF(mainStr, pattern);

    if (pos != 0) {
        printf("Pattern found at position: %d\n", pos);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}
