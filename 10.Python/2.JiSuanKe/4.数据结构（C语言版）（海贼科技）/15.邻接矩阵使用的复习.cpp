#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500

typedef struct Graph {
    int mat[MAX_N][MAX_N];
    int n;
}Graph;

void init(Graph *g, int len) {
    // g = (Graph *)malloc(sizeof(Graph));
    memset(g->mat, 0, sizeof(g->mat));
    g->n = len;
}

void insert(Graph *g, int a, int x, int y) {
    if(x < 0 || x >= g->n || y < 0 || y >= g->n) return;
    switch(a) {
        case 1: g->mat[y][x] = 1;
        case 0: g->mat[x][y] = 1;
    }
}

void output(Graph *g) {
    for(int i = 0 ; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            j == 0 || printf(" ");
            printf("%d", g->mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Graph *g = NULL;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init(g, n);
    for(int i = 0; i < m; i++) {
        int a = 0, x = 0, y = 0;
        scanf("%d %d %d", &a, &x, &y);
        insert(g, a, x, y);
    }
    output(g);
    return 0;
}