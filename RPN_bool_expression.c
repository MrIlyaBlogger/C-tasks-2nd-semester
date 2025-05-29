#include <stdio.h>
#include "stack.h"

int main() {
    char c, a, b;
    stack s;

    stack_create(&s); // Инициализация стека

    // Читаем символы до конца файла
    while ((c = getchar()) != EOF) {
        if (c == '0' || c == '1') {
            // Если символ — 0 или 1, кладём его на стек как число
            stack_push(&s, c - '0');
        } else if (c == '+') {
            // Операция ИЛИ (дизъюнкция): снимаем два значения со стека
            a = stack_pop(&s); 
            b = stack_pop(&s);

            // Если оба операнда истинны, кладём 1, иначе сумму (0+1=1, 0+0=0)
            if (a && b) 
                stack_push(&s, a);
            else 
                stack_push(&s, a + b);
        } else if (c == '*') {
            // Операция И (конъюнкция): снимаем два значения со стека
            a = stack_pop(&s); 
            b = stack_pop(&s);
            stack_push(&s, a * b); // Кладём результат умножения (логическое И)
        }
    }

    // Выводим результат, который остался на вершине стека
    printf("%d\n", stack_top(&s));
    return 0;
}
