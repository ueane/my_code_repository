#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bitmap
{
    int sign, len, many;
    int **str_encode, *p, *position, *times;
}bitmap, *pbitmap;

void init(bitmap *strbit, int n, int m) {
    n += 300;
    m += 300;
    strbit->p = (int*)malloc(sizeof(int) * m);
    strbit->position = (int*)calloc(sizeof(int) , m);
    strbit->times=(int*)calloc(sizeof(int),n);   

    strbit->str_encode=(int**)calloc(sizeof(int*),n);  
    for(int i = 0;i < n; i++)  
        strbit->str_encode[i]=(int*)calloc(sizeof(int),n);  

    strbit->many = 0;
    strbit->len = 0;
}

void get_bit(bitmap *strbit, char *t) {
    for (int i = 0; t[i]; i++) { 
        strbit->str_encode[t[i]][i / 32] |= (1 << (i % 32));
        strbit->len++;
        strbit->times[strbit->many]++;
    }
}

void move_operation(bitmap *strbit) {
        strbit->times[strbit->many]++;
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

void reset(bitmap* strbit, int n) {
    for(int i = 0; i < n; i++) {
        strbit->p[i] = 0;
    }
    strbit->many++;
}

void find(bitmap* strbit, char *s, char *t) {
    for (int i = 0; s[i]; i++) {
        move_operation(strbit);
        and_operation(strbit, s, i);

        if (strbit->p[strbit->len / 32] & (1 << (strbit->len % 32 - 1))) {
            strbit->position[strbit->many] = i - strbit->len + 1;
            reset(strbit, strlen(t) + 300);
        }
    }
}

void shift_and(char *s, char *t) {
    bitmap *strbit = (bitmap *)malloc(sizeof(bitmap));
    init(strbit, strlen(s), strlen(t));
    get_bit(strbit, t);
    find(strbit, s, t);

    if(strbit->many) {
        printf("I find t \033[42;30m%d\033[0m times in s\n", strbit->many);
        printf("position in string s is");
        for(int i = 0; i < strbit->many; i++) {
            printf("  %3d(%d times)", strbit->position[i], strbit->times[i]);
        }
        printf("\n");
    } else {
        printf("SHIFT AND NO WE FIND\n");
    }
    
    return ;   
}

int main() {
    char s[] = "aecaea aecaed aecaed";
    char t[] = "aecaed";        
    char a[] = "`1234567890-=qwertyuiop[]]asdfghjkl;'zxcvbnm,./~!@#$^&*()_+ASDFGHJKL::ZXCVBNM<>?qazwsxedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfghnjkujhvcxserfghjxedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfg"; // 402
    char b[] = "xedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfg"; //150  
    char c[] = "xedcrfvtgbyhnujmik,ol.ZAQXSWCDEVFRBGTNHYMJU<KI>LO?:P!@#$^&*()_+=-0987654321`zaqwsxcderfvbgtyhnmjuuik,.loplkmnbvfrtyhbvcxswerthjkoiuhgfcderghjkjhbvcdfgaaa"; //153 
    
    shift_and(s, t);
    shift_and(a, b);
    shift_and(a, c);
    return 0;
}


