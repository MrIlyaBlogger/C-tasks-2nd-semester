#include <stdio.h>

// Программа реверсирует содержимое файла внутри самого файла
int main() {
    FILE *file = fopen("input.txt", "r+b"); // Открываем файл для чтения и записи в бинарном режиме
    if (!file) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    // ftell возвращает текущую позицию указателя в файле (в данном случае — длину файла)
    fseek(file, 0, SEEK_END); // Перемещаемся в конец файла
    long file_size = ftell(file); // Получаем размер файла в байтах

    // Реверсируем файл посимвольно
    for (long i = 0; i < file_size / 2; ++i) {
        // Считываем символ с начала
        fseek(file, i, SEEK_SET); // Устанавливаем указатель на i-й байт с начала
        int left = fgetc(file);

        // Считываем символ с конца
        fseek(file, file_size - i - 1, SEEK_SET); // Устанавливаем указатель на соответствующий байт с конца
        int right = fgetc(file);

        // Меняем местами
        fseek(file, i, SEEK_SET);
        fputc(right, file); // fputc записывает символ и сдвигает указатель на 1 байт вперёд

        fseek(file, file_size - i - 1, SEEK_SET);
        fputc(left, file);
    }

    fclose(file);
    printf("Файл успешно реверсирован.\n");
    return 0;
}
