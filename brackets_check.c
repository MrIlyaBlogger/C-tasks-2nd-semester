#include <stdio.h>
// Предполагается, что stack реализован отдельно и поддерживает push, pop, top

int main() {
    int index = 0; 
    char input[100], symbol;
    stack *bracket_stack = NULL; // Стек для хранения открывающихся скобок

    scanf("%s", input); // Считываем строку с выражением
    while (input[index] != '\0') {
        if (input[index] == '(') {
            // Если встретили открывающую скобку — кладём её в стек
            symbol = input[index];
            push(bracket_stack, symbol);
        }
        if (input[index] == ')') {
            // Если встретили закрывающую скобку
            if (top(bracket_stack) == '(') {
                // Если на вершине стека открывающая — снимаем её
                pop(bracket_stack);
            } else {
                // Если стек пуст или на вершине не открывающая — ошибка
                printf("False\n");
                return 1;
            }
        }
        index++;
    }
    // Если после обработки строки стек не пуст — есть лишние открывающие скобки
    if (top(bracket_stack) != NULL)
        printf("False\n");
    else
        printf("True\n");
    return 0;
}
