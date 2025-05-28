#include <stdio.h>
#include <stdlib.h>

// Описание структуры узла дерева (сын/брат)
typedef struct Node {
    int data;
    struct Node* son;     // Первый сын
    struct Node* brother; // Следующий брат
} Tree;

// Функция вычисления степени (максимального числа детей у одного узла)
void degree(Tree* root, int *count, int local) {
    if (root == NULL) {
        return;
    }
    // Если текущая длина цепочки братьев больше найденного максимума — обновляем
    if (local > *count) {
        *count = local;
    }
    // Рекурсивно идём по братьям, увеличивая счётчик
    degree(root->brother, count, local + 1);
    // Рекурсивно идём по сыну, сбрасывая счётчик братьев
    degree(root->son, count, 0);
}

// Функция вычисления глубины дерева (максимальной длины пути от корня до листа)
void tree_depth(Tree* root, int *depth, int local) {
    if (root == NULL) {
        return;
    }
    // Если текущая глубина больше найденного максимума — обновляем
    if (local > *depth) {
        *depth = local;
    }
    // Рекурсивно идём по сыну, увеличивая глубину
    tree_depth(root->son, depth, local + 1);
    // Рекурсивно идём по братьям, глубина не меняется
    tree_depth(root->brother, depth, local);
}

//Ниже - визуализация (на зачёте не пишем)

int main() {
    int count = 0;

    // Создание узлов дерева
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->data = 1;

    Tree* n2 = (Tree*)malloc(sizeof(Tree));
    n2->data = 2;
    n2->son = NULL;
    n2->brother = NULL;

    Tree* n3 = (Tree*)malloc(sizeof(Tree));
    n3->data = 3;
    n3->son = NULL;
    n3->brother = NULL;

    Tree* n4 = (Tree*)malloc(sizeof(Tree));
    n4->data = 4;
    n4->son = NULL;
    n4->brother = NULL;

    Tree* n5 = (Tree*)malloc(sizeof(Tree));
    n5->data = 5;
    n5->son = NULL;
    n5->brother = NULL;

    // Связываем сыновей и братьев
    root->son = n2;
    n2->brother = n3;
    n3->brother = n4;
    n3->son = n5;

    // Вызываем функцию для поиска степени корня
    degree(root, &count, 0);
    printf("Степень корня: %d\n", count + 1);

    // Вызываем функцию для поиска глубины дерева
    int depth = 0;
    tree_depth(root, &depth, 0);
    printf("Глубина корня: %d\n", depth + 1);

    // Освобождаем память
    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(root);
    return 0;
}
