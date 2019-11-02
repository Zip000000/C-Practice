#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

typedef struct Node {
    int vertex;
    struct Node *next;
} Node, *LinkedList;

LinkedList insert_node(LinkedList head, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = index;
    node->next = head;
    head = node;
    return head;
}

typedef struct Graph {
    LinkedList l[MAX_N];
    int num;
} Graph;

void init(Graph *g, int n) {
    g->num = n;
    for(int i = 0; i < n; i++) {
        g->l[i] = NULL;
    }
}

void insert(Graph *g, int a, int x, int y) {
	if(x < 0 || x >= g->num || y < 0 || y >= g->num) return;
    switch(a) {
        case 1: g->l[y] = insert_node(g->l[y], x);
        case 0: g->l[x] = insert_node(g->l[x], y);
    }
}

void output(Graph *g) {
    for(int i = 0; i < g->num; i++) {
        printf("%d:", i);
        Node *cnode = g->l[i];
        while(cnode) {
            printf(" %d", cnode->vertex);
        	cnode = cnode->next;
        }
        printf("\n");
    }
}

void clear(Graph *g) {
    
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init(g, n);
    
    for(int i = 0; i < m; i++) {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        insert(g, a, x, y);
		//printf("%d %d %d 如下\n ", a, x, y);
        //output(g);
    }
    output(g);
    return 0;
}