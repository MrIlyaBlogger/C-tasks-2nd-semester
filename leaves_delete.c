#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла бинарного дерева
typedef struct Node {
    int value;              // Значение, хранящееся в узле
    struct Node *left;      // Указатель на левого потомка
    struct Node *right;     // Указатель на правого потомка
} Tree;

// Рекурсивная функция для удаления всех листьев дерева
Tree* delete_leaves(Tree *root) {
    // Если дерево пустое, возвращаем NULL
    if (root == NULL) {
        return NULL;
    }

    // Если у узла нет потомков (это лист), удаляем его
    if (root->left == NULL && root->right == NULL) {
        free(root);           // Освобождаем память, занятую узлом
        return NULL;          // Возвращаем NULL вместо удалённого листа
    }

    // Рекурсивно удаляем листья в левом и правом поддеревьях
    root->left = delete_leaves(root->left);
    root->right = delete_leaves(root->right);

    // Возвращаем (возможно изменённый) корень
    return root;
}