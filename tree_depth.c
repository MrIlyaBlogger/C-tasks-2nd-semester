#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла дерева
// Каждый узел содержит данные, указатель на первого сына и указатель на брата
typedef struct Node {
    int data;                  // Значение, хранящееся в узле
    struct Node* son;          // Указатель на первого сына (первый дочерний элемент)
    struct Node* brother;      // Указатель на следующего брата (следующий элемент на том же уровне)
} Tree;

// Рекурсивная функция для вычисления глубины дерева
// root — текущий узел
// depth — указатель на максимальную глубину
// local — текущая глубина обхода
void tree_depth(Tree* root, int *depth, int local) {
    if (root == NULL) {
        return;               // Если дошли до пустого узла — возвращаемся
    }
    if (local > *depth) {
        *depth = local;       // Обновляем максимальную глубину, если текущая больше
    }
    tree_depth(root->son, depth, local + 1);     // Рекурсивно идём к сыну (глубже на 1)
    tree_depth(root->brother, depth, local);     // Рекурсивно идём к брату (глубина не меняется)
}

//Ниже - визуализация (на зачёте не пишем)

int main() {
    int count = 0;

    // Выделяем память и создаём корень дерева
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->data = 1;

    // Создаём остальные узлы
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
    root->son = n2;           // У корня сын — n2
    n2->brother = n3;         // У n2 брат — n3
    n3->brother = n4;         // У n3 брат — n4
    n3->son = n5;             // У n3 сын — n5

    // Теперь можно тестировать функцию tree_depth
    tree_depth(root, &count, 0); // Вычисляем глубину дерева
    printf("Глубина корня: %d\n", count + 1); // Выводим глубину (прибавляем 1, т.к. отсчёт с 0)

    // Не забудь освободить память!
    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(root);
    return 0;
}
