#include <stdio.h>
#include <stdlib.h>

// Структура узла дека
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Структура дека
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Инициализация дека
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Добавление в конец
void pushBack(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = dq->rear;
    if (dq->rear)
        dq->rear->next = node;
    dq->rear = node;
    if (!dq->front)
        dq->front = node;
}

// Вывод дека
void printDeque(Deque* dq) {
    Node* curr = dq->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Реверс дека
void reverseDeque(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    // Поменять местами front и rear
    if (temp) {
        temp = dq->front;
        dq->front = dq->rear;
        dq->rear = temp;
    }
}

// Очистка памяти
void freeDeque(Deque* dq) {
    Node* curr = dq->front;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(dq);
}

//Ниже - визуализация (на зачёте не пишем)

int main() {
    Deque* dq = createDeque();
    int n, x;
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    printf("Введите элементы:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        pushBack(dq, x);
    }
    printf("Дек до реверса: ");
    printDeque(dq);

    reverseDeque(dq);

    printf("Дек после реверса: ");
    printDeque(dq);

    freeDeque(dq);
    return 0;
}

