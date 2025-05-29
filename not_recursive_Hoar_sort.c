#include <stdio.h>
#define MAX_SIZE 1000

// Структура для хранения границ подмассива (стека)
typedef struct {
    int left;
    int right;
} StackItem;

// Итеративная (нерекурсивная) быстрая сортировка Хоара
void quicksort(int arr[], int n) {
    StackItem stack[MAX_SIZE]; // Стек для хранения границ подмассивов
    int top = 0;

    // Кладём в стек границы всего массива
    stack[top].left = 0;
    stack[top].right = n - 1;
    top++;

    while (top > 0) {
        // Достаём границы текущего подмассива
        top--;
        int left = stack[top].left;
        int right = stack[top].right;

        if (left >= right) continue; // Если подмассив пуст или из одного элемента — пропускаем

        // Выбираем опорный элемент (pivot)
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        // Разделение массива относительно опорного элемента
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                // Меняем элементы местами
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }

        // Кладём в стек границы левого и правого подмассивов
        if (left < j) {
            stack[top].left = left;
            stack[top].right = j;
            top++;
        }
        if (i < right) {
            stack[top].left = i;
            stack[top].right = right;
            top++;
        }
    }
}

// Пример использования (на зачёте не пишем)
int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, n);
    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
