#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack* CreateStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void Push(Stack *stack, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int Pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

void FreeStack(Stack *stack) {
    while (stack->top != NULL) {
        Pop(stack);
    }
}

void ReverseStack(Stack *stack) {
    Stack tempStack;
    tempStack.top = NULL;

    while (stack->top != NULL) {
        Push(&tempStack, Pop(stack));
    }

    stack->top = tempStack.top;
    FreeStack(&tempStack);
}

Stack* Merge(Stack *stack1, Stack *stack2) {
    Stack *result = CreateStack();

    while (stack1->top != NULL) {
        Push(result, Pop(stack1));
    }

    while (stack2->top != NULL) {
        Push(result, Pop(stack2));
    }
    ReverseStack(result);
    return result;
}

int StackSize(Stack *stack) {
    int size = 0;
    Node *current = stack->top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void merge_sort(Stack **stack) {
    if (StackSize(*stack) > 1) {
        int l = StackSize(*stack) / 2;
        Stack *a, *b;
        CreateStack(&a);
        CreateStack(&b);
        for (int i = 0; i < l; i++) {
            Push(a, Pop(*stack));
        }
        while ((*stack)->top != NULL) {
            Push(b, Pop(*stack));
        }
        merge_sort(&a);
        merge_sort(&b);
        *stack = Merge(a, b);
        FreeStack(a);
        FreeStack(b);
    }

}
