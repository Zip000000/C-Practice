#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size,length;
    int* data;
} Vector;

void init(Vector* vector, int _size) {
	vector->size = _size;
    vector->length = 0;
    vector->data = (int* )malloc(sizeof(int) * vector->size); 
}

void expand(Vector* vector) {
	int* old_data = vector->data;
    vector->size *= 2;
    vector->data = (int* )malloc(sizeof(int) * vector->size);
    for(int i = 0; i <= vector->length; i++) {
        vector->data[i] = old_data[i];
    }
}

void insert(Vector* vector, int loc, int val) {
    if(loc > vector->length) {
        printf("failed\n");
        return ;
    }
    if(vector->length >= vector->size) {
        expand(vector);
    }
    for(int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i-1];
    }
    vector->data[loc] = val;
    vector->length++;
    printf("success\n");

}

void search(Vector* vector, int val) {
    for(int i=0; i < vector->length; i++) {
        if(vector->data[i] == val) {
            printf("success\n");
            return ;
        }
    }
    printf("failed\n");
}

void delete_node(Vector* vector, int loc) {
    if(loc > vector->length)
    {
        printf("failed\n");
        return ;
    }
    for(int i = loc; i < vector->length; i++) {
        vector->data[i] = vector->data[i+1];
    }
    vector->length--;
    printf("success\n");
}

void print(Vector* vector) {
	for(int i = 0; i < vector->length; i++) {
        i==0 || printf(" ");
        printf("%d", vector->data[i]);
    }
    //printf(" size=%d length=%d", vector->size, vector->length);
    printf("\n");
}

void clear(Vector* vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int times;
    scanf("%d", &times);
    int m, n;
    for(int i=0; i<times; i++) {
        int t;
    	scanf("%d", &t);
        switch(t) {
            case 1: scanf("%d", &m);
                    scanf("%d", &n);
                    insert(a, m, n); break;
            case 2: scanf("%d", &m);
                    delete_node(a, m); break;
            case 3: scanf("%d", &m);
                    search(a, m); break;
            case 4: print(a); break;
        }
            //print(a);
    }
    return 0;
}
