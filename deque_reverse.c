#include <stdio.h>
#include <stdlib.h>

// Структура узла дека
// Каждый узел содержит данные, а также указатели на предыдущий и следующий элементы
typedef struct Node {
    int data;              // Значение, хранящееся в узле
    struct Node* prev;    // Указатель на предыдущий узел
    struct Node* next;    // Указатель на следующий узел
} Node;

// Структура дека
// Дек содержит указатели на начало (front) и конец (rear) списка
typedef struct Deque {
    Node* front;  // Указатель на первый элемент дека
    Node* rear;   // Указатель на последний элемент дека
} Deque;

// Инициализация дека
// Выделяет память под дек и устанавливает его начало и конец в NULL
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Добавление элемента в конец дека
// Создаёт новый узел и добавляет его в конец
void pushBack(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node)); // Выделяем память под новый узел
    node->data = value;                      // Записываем значение
    node->next = NULL;                       // Следующего узла нет (он последний)
    node->prev = dq->rear;                   // Предыдущий — текущий последний
    if (dq->rear)
        dq->rear->next = node;               // Если дек не пуст, связываем старый последний с новым
    dq->rear = node;                         // Новый узел становится последним
    if (!dq->front)
        dq->front = node;                    // Если дек был пуст, новый узел — и первый тоже
}

// Вывод всех элементов дека слева направо
void printDeque(Deque* dq) {
    Node* curr = dq->front;                  // Начинаем с первого элемента
    while (curr) {                           // Пока не дошли до конца
        printf("%d ", curr->data);          // Печатаем значение
        curr = curr->next;                   // Переходим к следующему
    }
    printf("\n");
}

// Реверс дека (разворот порядка элементов)
void reverseDeque(Deque* dq) {
    Node* curr = dq->front;                  // Начинаем с первого элемента
    Node* temp = NULL;                       // Временная переменная для обмена указателей
    while (curr) {
        temp = curr->prev;                   // Сохраняем prev
        curr->prev = curr->next;             // Меняем местами prev и next
        curr->next = temp;
        curr = curr->prev;                   // Переходим к следующему (теперь это prev)
    }
    // После цикла temp указывает на предыдущий узел (NULL или последний обработанный)
    // Меняем местами front и rear дека
    if (temp) {
        temp = dq->front;
        dq->front = dq->rear;
        dq->rear = temp;
    }
}

// Очистка памяти, занятой деком
void freeDeque(Deque* dq) {
    Node* curr = dq->front;                  // Начинаем с первого элемента
    while (curr) {
        Node* next = curr->next;             // Сохраняем указатель на следующий
        free(curr);                          // Освобождаем память текущего
        curr = next;                         // Переходим к следующему
    }
    free(dq);                               // Освобождаем память под сам дек
}

//Ниже - визуализация (на зачёте не пишем)

int main() {
    Deque* dq = createDeque();               // Создаём пустой дек
    int n, x;
    printf("Введите количество элементов: ");
    scanf("%d", &n);                        // Вводим количество элементов
    printf("Введите элементы:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);                    // Вводим элемент
        pushBack(dq, x);                     // Добавляем в дек
    }
    printf("Дек до реверса: ");
    printDeque(dq);                          // Печатаем дек до реверса

    reverseDeque(dq);                        // Разворачиваем дек

    printf("Дек после реверса: ");
    printDeque(dq);                          // Печатаем дек после реверса

    freeDeque(dq);                           // Очищаем память
    return 0;
}

