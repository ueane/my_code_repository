#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void sunday(char *s, char *t) {
    int str_index[256] = {0};
    int len_t = strlen(t);
    int len_s = strlen(s);
    for (int i = 0; i < 256; i++) {
        str_index[i] = len_t + 1;
    }
    for (int i = 0; t[i]; i++) {
        str_index[t[i]] = len_t - i;   
    }
    int i = 0, j = 0;
    while (i + len_t <= len_s) {
        if (s[i + j] != t[j]) {
            i += str_index[s[i + len_t]];
            j = 0;
        } else {
            j++;
        }
        if (t[j] == '\0') {
            printf("sunday YES");
            return ;
        }
    }
    printf("sunday NO");
    return ;
}
 
 
int main() {
    char s[] = "aecaeaecaed";
    char t[] = "aecaed";
    sunday(s, t);
    return 0;
}
