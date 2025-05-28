#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* son;
    struct Node* brother;
} Tree;

void tree_depth(Tree* root, int *depth, int local) {
    if (root == NULL) {
        return;
    }
    if (local > *depth) {
        *depth = local;
    }
    tree_depth(root->son, depth, local + 1);
    tree_depth(root->brother, depth, local);
}

//Ниже - визуализация (на зачёте не пишем)

int main() {
    int count = 0;

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

    // Теперь можно тестировать функцию degree
    tree_depth(root, &count, 0);
    printf("Глубина корня: %d\n", count + 1);

    // Не забудь освободить память!
    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(root);
    return 0;
}
