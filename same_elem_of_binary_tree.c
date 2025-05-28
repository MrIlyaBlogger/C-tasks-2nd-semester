#include <stdio.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} tree;

void same(tree *root, int k) {
    if (root == NULL)
        return;
    if (root->key == k) {
        printf("Repeat found: %d\n", root->key);
    }
    same(root->left, k);
    same(root->right, k);
}

int main() {
    // Создаём дерево:
    //       5
    //      / \
    //     3   7
    //    /   / \
    //   3   5   8
    tree n1 = {3, NULL, NULL};
    tree n2 = {3, &n1, NULL};
    tree n3 = {5, NULL, NULL};
    tree n4 = {8, NULL, NULL};
    tree n5 = {7, &n3, &n4};
    tree root = {5, &n2, &n5};

    int k = 3;
    printf("Поиск всех узлов со значением %d:\n", k);
    same(&root, k);

    k = 5;
    printf("\nПоиск всех узлов со значением %d:\n", k);
    same(&root, k);

    return 0;
}
