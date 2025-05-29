#include <stdio.h>

int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "r");
    FILE *f3 = fopen("f3.txt", "r");
    FILE *f = fopen("f.txt", "w"); 
    char c = '\0';
    while ((c = getc(f1)) != EOF) {
        putc(c, f);
    }
    while ((c = getc(f2)) != EOF) {
        putc(c, f);
    }
    while ((c = getc(f3)) != EOF) {
        putc(c, f);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f);
    return 0;
}
