#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1010

typedef struct Graph {
    int flag[MAX_N][MAX_N];
    int score[MAX_N];
    int n;
} graph;

graph *g_init(graph *g, int n) {
    memset(g->flag, 0, sizeof(g->flag));
    memset(g->score, 0, sizeof(g->score));
    g->n = n;
    return g;
}

int main() {
    graph *g = (graph *)malloc(sizeof(graph));
    int n, m;
    scanf("%d %d", &n, &m);
    g = g_init(g, n);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(g->flag[a][b] != 1) {
            g->flag[a][b] = 1;
            g->score[a]--;
            g->score[b]++;
        }
    }
    
    for(int i = 0; i < g->n; i++) {
        printf("%d\n", g->score[i]);
    }
    return 0;
}