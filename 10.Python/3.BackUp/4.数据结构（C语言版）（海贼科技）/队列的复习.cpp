#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue{
    int *data;
    int head, tail, length;
}Queue;

void init(Queue *q, int length) {
    q->data = (int *) malloc(length * sizeof(int));
    q->length = length;
    q->head = 0;
	q->tail = -1;
}

int push(Queue *q, int element) {
    if(q->tail >= q->length - 1) return ERROR;
    q->data[++q->tail] = element;
    return OK;
}
void output(Queue *q) {
    for(int i = q->head; i <= q->tail; i++) {
        i == q->head || printf(" ");
        printf("%d", q->data[i]);
    }
    printf("\n");
}
int front(Queue *q) {
    if(empty(q)) return ERROR;
    return q->data[q->head];
}
void pop(Queue *q) {
    if(empty(q)) return;
    q->head++;
}

int empty(Queue *q) {
    return (q->head > q->tail);
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        push(queue, temp);
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        pop(queue);
    }
    printf("%d\n", front(queue));
    output(queue);
    
    return 0;
}
