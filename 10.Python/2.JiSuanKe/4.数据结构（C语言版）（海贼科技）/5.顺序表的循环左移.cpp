#include <stdio.h>
#include <stdlib.h>
typedef struct Vector {
    int length, size;
    int* data;
}Vector;

Vector* Vec_Init(int _size) {
    Vector* vector;
    vector = (Vector* )malloc(sizeof(Vector));
    vector->size = _size;
    vector->length = 0;
    vector->data = (int* )malloc(sizeof(int) * vector->size);
    return vector;
}

void show(Vector* vector) {
    for(int i = 0; i < vector->length; i++) {
        i == 0 || printf(" ");
        printf("%d", vector->data[i]);
    }
}

Vector* left_move(Vector* vector, int k) {
    Vector* temp;
    temp = Vec_Init(k);
    for(int i = 0; i < k; i++) {
        temp->data[i] = vector->data[i];
        temp->length++;
    }
    for(int i = 0; i < (vector->length-k); i++) {
        vector->data[i] = vector->data[i+k];
    }
    int j=0;
    for(int i = vector->length-k; i < vector->length; i++) {
        vector->data[i] = temp->data[j];
        j++;
    }
    return vector;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Vector* vector;
    vector = Vec_Init(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vector->data[i]);
        vector->length++;
    }
    vector = left_move(vector, k);
    show(vector);
    return 0;
}