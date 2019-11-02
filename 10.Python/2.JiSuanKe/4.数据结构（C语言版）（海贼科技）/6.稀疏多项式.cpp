#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int* data;
    int size,length;
} Vector;

Vector* Init(Vector* v, int _size) {
    v = (Vector* )malloc(sizeof(Vector));
    v->size = _size;
    v->data = (int* )malloc(sizeof(int) * v->size);
    v->length = 0;
    return v;
}
Vector* add (Vector* v, int index) {
    v->data[(v->length)++] = index;
    return v;
}
int P (Vector* vc, Vector* ve, int m, int x0) {
    int ans = 0;
    for (int i =0; i < m; i++) {
        ans += (vc->data[i]) * pow(x0, ve->data[i]);
        //printf("C%d = %d    E%d = %d   ans = %d \n", i, vc->data[i], i, ve->data[i], ans);
    }
    return ans;
}
int main() {
    Vector* vc;
    Vector* ve;
    int m;
    scanf("%d", &m);
    vc = Init(vc, m);
    ve = Init(ve, m);
    for (int i = 0; i < m; i++) {
        int temp_c, temp_e;
        scanf("%d %d", &temp_c, &temp_e);
        vc = add(vc, temp_c);
        ve = add(ve, temp_e);
    }
    int x0;
    scanf("%d", &x0);
    int ans = P(vc, ve, m, x0);
    printf("%d\n", ans);
    
    
    return 0;
}