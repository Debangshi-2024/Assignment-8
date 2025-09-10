#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (struct Node**) malloc(capacity * sizeof(struct Node*));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct Queue* queue = createQueue(1000);
    enqueue(queue, root);

    int** result = (int**) malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*) malloc(1000 * sizeof(int));
    int levelCount = 0;

    while (!isEmpty(queue)) {
        int levelSize = queue->size;
        int* levelNodes = (int*) malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(queue);
            levelNodes[i] = node->data;
            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }
        result[levelCount] = levelNodes;
        (*returnColumnSizes)[levelCount] = levelSize;
        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}

