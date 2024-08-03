#include <stdio.h>
#include <string.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN + 1]; // �洢����һά����
    int length;          // ���ĵ�ǰ����
} SString;               // ����˳��洢�ṹ

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
        return i - T.length; // ����ƥ��ĵ�һ���ַ����±�
    } else {
        return 0; // ģʽƥ�䲻�ɹ�
    }
}

int main() {
    SString mainStr = {"ababcabcababcabcabc", 18}; // ����
    SString pattern = {"abcabcabc", 9};            // ģʽ��

    int pos = Index_BF(mainStr, pattern);

    if (pos != 0) {
        printf("Pattern found at position: %d\n", pos);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}
