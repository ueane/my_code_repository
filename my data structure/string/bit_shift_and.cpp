#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bitmap
{
    int sign, len, times;
    int **str_encode;
    int *p;
}bitmap, *pbitmap;

void init(bitmap *strbit) {
    strbit->p = (int*)malloc(sizeof(int) * 300);
    strbit->str_encode=(int**)malloc(sizeof(int*)*256);  
    for(int i = 0;i < 300; i++)  
        strbit->str_encode[i]=(int*)calloc(sizeof(int),300);  
    strbit->len = 0;
    strbit->times = 0;
}

void get_bit(bitmap *strbit, char *s, char *t) {
    for (int i = 0; t[i]; i++) { 
        strbit->str_encode[t[i]][i / 32] |= (1 << (i % 32));
        strbit->len++;
        strbit->times++;
    }
}

void move_operation(bitmap *strbit) {
        strbit->times++;
        strbit->sign = !!(strbit->p[0] >> 31);
        strbit->p[0] = (strbit->p[0] << 1 | 1);
        
        for(int j = 1; j < 320; j++) {
            if(strbit->sign == 0) {
                strbit->sign = !!(strbit->p[j] >> 31);
                strbit->p[j] = (strbit->p[j] << 1);
            } else {
                strbit->sign = !!(strbit->p[j] >> 31);
                strbit->p[j] = (strbit->p[j] << 1 | 1);
            }
        }
}

void and_operation(bitmap *strbit, char *s, int i) {
    for(int j = 0; j < 320; j++) {
        strbit->p[j] = strbit->p[j] & strbit->str_encode[s[i]][j];
    }
}

void shift_and(char *s, char *t) {
    bitmap *strbit = (bitmap *)malloc(sizeof(bitmap));
    init(strbit);
    get_bit(strbit, s, t);

    for (int i = 0; s[i]; i++) {
        move_operation(strbit);
        and_operation(strbit, s, i);

        int k = strbit->len / 32, z = strbit->len % 32;
        if (strbit->p[k] & (1 << (z - 1))) {
            printf("SHIFT AND YES : %d\n", strbit->times);
            printf("String t's position in string s is %d\n",i - strbit->len + 1);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", strbit->times);
    return ;   
}

int main() {
    char s[] = "aecaea aecaed";
    char t[] = "aecaed";        
    char a[] = "`1234567890-=qwertyuiop[]]asdfghjkl;'zxcvbnm,./~!@#$^&*()_+ASDFGHJKL::ZXCVBNM<>?qazwsxedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfghnjkujhvcxserfghj"; // 252
    char b[] = "xedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfg"; //150  
    char c[] = "xedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfgaaa"; //153 
    
    shift_and(s, t);
    shift_and(a, b);
    shift_and(a, c);
    return 0;
}

