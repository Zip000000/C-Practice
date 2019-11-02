#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{
    long long *num;
    int head, tail, length;
}Queue, *PQ;

void init(PQ q, int length) {
    q->num = (long long *)malloc(length * sizeof(long long));
    q->head = 0;
    q->tail = -1;
    q->length = length;
}

int push(PQ q, long long num) {
    if(q->tail >= q->length) return -1;
    q->num[++(q->tail)] = num;
    return 0;
}

void output(PQ q, int i) {
        printf("%lld", q->num[i]);
}
void pop(PQ q) {
    q->tail--;
}

int main() {
    Queue *q0, *q1, *q2;
    q0 = (Queue *)malloc(sizeof(Queue));
    q1 = (Queue *)malloc(sizeof(Queue));
    q2 = (Queue *)malloc(sizeof(Queue));
    init(q0, 10);
    init(q1, 10);
    init(q2, 10);
    
    for(int i = 0; i < 10; i++) {
        int flag;
        scanf("%d", &flag);

        long long tmp;
        scanf("%lld", &tmp);
        //printf("-----------------------------------------%lld\n", tmp);
        
        if(flag == 0) push(q0, tmp);        
        if(flag == 1) push(q1, tmp);        
        if(flag == 2) push(q2, tmp);        
    }
    
    for(int i = 0; i < 10; i++) {
        output(q0, i);
        pop(q0);
        printf(" ");
        output(q1, i);
        pop(q1);
        printf(" ");
        output(q2, i);
        pop(q2);
        printf("\n");
    }
    
    
    return 0;
}
