#include <stdio.h>

int main() {
    // Открываем три файла для чтения
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "r");
    FILE *f3 = fopen("f3.txt", "r");
    // Открываем файл для записи результата
    FILE *f = fopen("f.txt", "w"); 
    char c = '\0';
    // Копируем содержимое первого файла в результирующий
    while ((c = getc(f1)) != EOF) {
        putc(c, f);
    }
    // Копируем содержимое второго файла в результирующий
    while ((c = getc(f2)) != EOF) {
        putc(c, f);
    }
    // Копируем содержимое третьего файла в результирующий
    while ((c = getc(f3)) != EOF) {
        putc(c, f);
    }
    // Закрываем все файлы
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f);
    return 0;
}
