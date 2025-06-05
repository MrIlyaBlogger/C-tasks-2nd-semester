#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

void Push(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (queue->tail) {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    if (!queue->head) {
        queue->head = newNode;
    }
}

int Pop(Queue *queue) {
    if (!queue->head) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = queue->head;
    int value = temp->value;
    queue->head = queue->head->next;
    if (!queue->head) {
        queue->tail = NULL;
    }
    free(temp);
    return value;
}

int main() {
    FILE *file = fopen("matrix.txt", "r");
    int rows = 4, cols = 5; // Размеры матрицы
    int matrix[rows][cols];

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                perror("Error reading matrix");
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);

    // Использование очереди для транспонирования
    Queue queue = {NULL, NULL};

    // Заполнение очереди элементами транспонированной матрицы
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            Push(&queue, matrix[j][i]);
        }
    }

    // Извлечение и вывод элементов из очереди
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", Pop(&queue));
        }
        printf("\n");
    }

	return 0;
}

