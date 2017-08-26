#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MC(T, n) (T *)malloc(sizeof(T) * (n));
#define CC(T, n) (T *)calloc((n), sizeof(T));
#define RC(data, T, n) (T *)realloc(data, (n) * sizeof(T));
 
typedef struct Bitmap {
    int *data;
    int size;
} Bitmap;
 
Bitmap *init_bitmap(int n = 1) {
    Bitmap *bm = MC(Bitmap, 1);
    bm->data = CC(int, n);
    bm->size = n;
    return bm;
}
 
void expand_bitmap(Bitmap *bm, int size) {
    int *data_temp = CC(int, size);
    memcpy(data_temp, bm->data, sizeof(int) * bm->size);
    free(bm->data);
    bm->data = data_temp;
    bm->size = size;
    return ;
}
 
int is_one(Bitmap *bm, int n) {
    if (n / 30 + 1 > bm->size) {
        expand_bitmap(bm, n / 30 + 1);
    }
    return bm->data[n / 30] & (1 << (n % 30));
}
 
void set_one(Bitmap *bm, int n) {
    if (n / 30 + 1 > bm->size) {
        expand_bitmap(bm, n / 30 + 1);
    }
    bm->data[n / 30] |= (1 << (n % 30));
    return ;
}
 
void left_bitmap(Bitmap *bm, int n) {
    is_one(bm, n);
    bm->data[0] <<= 1;
    for (int i = 1; i < bm->size; i++) {
        bm->data[i] <<= 1;
        bm->data[i] |= !!(bm->data[i - 1] & (1 << 30));
    }
    return ;
}
 
void and_bitmap(Bitmap *bm1, Bitmap *bm2, int n) {
    is_one(bm1, n);
    is_one(bm2, n);
    int index = 0, i = 0;
    while (index <= n) {
        bm1->data[i] &= bm2->data[i];
        i++;
        index += 30;
    }
    return ;
}
 
void clear(Bitmap *bm) {
    free(bm->data);
    free(bm);
}
 
void shift_and(char *s, char *t) {
    Bitmap *str_encode[256];
    for (int i = 0; i < 256; i++) {
        str_encode[i] = init_bitmap();
    }
    Bitmap *p = init_bitmap();
    int len = 0;
    int times = 0;
    for (int i = 0; t[i]; i++) {
        set_one(str_encode[t[i]], i);
        len++;
        times++;
    }
    for (int i = 0; s[i]; i++) {
        times++;
        left_bitmap(p, len);
        set_one(p, 0);
        and_bitmap(p, str_encode[s[i]], len);
        if (is_one(p, len - 1)) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", times);
    return ;
}
 
int main() {
    char s[1000];
    char t[1000];
    scanf("%s%s", s, t);
    shift_and(s, t);
    return 0;
}