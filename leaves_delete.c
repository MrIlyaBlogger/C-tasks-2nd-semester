#include <stdio.h>
#include <stdlib.h>

// Структура элемента вектора (двусвязный список)
typedef struct _vector_item {
    struct _vector_item * next;
    struct _vector_item * prev;
    struct _tree_node * node;
} vector_item;

// Структура вектора (двусвязный список)
typedef struct _vector {
    int size;
    struct _vector_item * front;
    struct _vector_item * back;
} vector;

// Структура узла дерева
typedef struct _tree_node {
    char id;
    struct _tree_node * parent;
    struct _vector * children;
} tree_node;

// Предполагается, что эти функции реализованы где-то ещё:
void vector_create(vector *v);
void vector_push_back(vector *v, vector_item *item);
vector_item *vector_pop_front(vector *v);
void vector_destroy(vector *v);
void vector_remove_child(vector *v, vector_item *item);

// Функция для полного освобождения памяти под листом (vector_item и tree_node)
void free_leaf(vector_item *item) {
    if (!item) return;
    tree_node *node = item->node;
    if (node) {
        // Освобождаем вектор детей, если он есть
        if (node->children) {
            vector_destroy(node->children);
            free(node->children);
        }
        free(node); // Освобождаем сам узел дерева
    }
    free(item); // Освобождаем элемент вектора
}

// Функция для удаления всех листьев дерева с освобождением памяти
void delete_leaf(tree_node * root) {
    vector_item * curr;
    vector queue;

    vector_create(&queue);

    // Добавляем всех детей корня в очередь
    curr = root->children ? root->children->front : NULL;
    while (curr != NULL) {
        vector_push_back(&queue, curr);
        curr = curr->next;
    }
    
    while (queue.size > 0) {
        curr = vector_pop_front(&queue);
        if (curr->node->children->size == 0) {
            // Удаляем ссылку на этот лист у родителя
            if (curr->node->parent && curr->node->parent->children) {
                vector_remove_child(curr->node->parent->children, curr);
            }
            free_leaf(curr); // Полностью освобождаем память под листом
        } else {
            // Если не лист — добавляем всех его детей в очередь
            vector_item *child = curr->node->children->front;
            while (child != NULL) {
                vector_push_back(&queue, child);
                child = child->next;
            }
        }
    }
    vector_destroy(&queue);
}
