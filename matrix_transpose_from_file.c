#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIMENSION 1000

// Программа транспонирует матрицу из файла без указания размеров
// Строки могут быть разной длины, размеры определяются на лету
int main(void) {
    int num, offset, i, j, n, m;
    int matrix[MAX_DIMENSION][MAX_DIMENSION]; // Массив для хранения исходной матрицы
    int row_lengths[MAX_DIMENSION];           // Массив для хранения количества столбцов в каждой строке

    char *line = NULL; // Буфер для текущей строки
    size_t len = 0;   // Размер буфера для getline
    FILE *input_file = NULL;

    input_file = fopen("matrix.txt", "r"); // Открываем файл для чтения
    if (!input_file) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    // Считываем матрицу из файла построчно
    i = 0;
    int max_cols = 0;
    while (getline(&line, &len, input_file) != -1 && i < MAX_DIMENSION) {
        j = 0;
        char *ptr = line;
        // Считываем все числа из строки
        while (sscanf(ptr, " %d%n", &num, &offset) == 1 && j < MAX_DIMENSION) {
            matrix[i][j++] = num;
            ptr += offset;
        }
        row_lengths[i] = j; // Сохраняем количество столбцов в текущей строке
        if (j > max_cols) max_cols = j; // Определяем максимальное количество столбцов
        i++;
    }
    int rows = i;
    free(line);
    fclose(input_file);

    // Выводим транспонированную матрицу
    printf("Транспонированная матрица:\n");
    for (n = 0; n < max_cols; n++) {
        for (m = 0; m < rows; m++) {
            if (n < row_lengths[m]) // Проверяем, есть ли элемент в этой строке
                printf("%d ", matrix[m][n]);
        }
        printf("\n");
    }

    return 0;
}
