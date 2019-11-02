#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
	int* data;
    int top_index, max_size;
} Stack;

void init(Stack *s, int length) {
    s->data = (int *)malloc(sizeof(int) * length);
    s->top_index = -1;
    s->max_size = length;
}

int push(Stack *s, int index) {
    if(s->top_index >= s->max_size) return ERROR;
    s->data[++s->top_index] = index;
    return OK;
}

int pop(Stack *s) {
    if(s->top_index < 0) return ERROR;
    s->top_index--;
    return OK;
}

int top(Stack *s) {
    if(s->top_index < 0) return ERROR;
    return s->data[s->top_index];
}

int empty(Stack *s) {
    if(s->top_index < 0) return 1;
    return 0;
}

int precede(int a, int b, char opt) {
    if(opt == '+') return a + b;
    if(opt == '-') return a - b;
    if(opt == '*') return a * b;
    if(opt == '/') return a / b;
    return ERROR;
    //printf("precede error!\n");
}
int operate(char a, char b) {
    if(a == '*' && b == '+') return 1;
    if(a == '*' && b == '-') return 1;
    if(a == '/' && b == '+') return 1;
    if(a == '/' && b == '-') return 1;
    // if(a == '+' && b == '*') return -1;
    // if(a == '-' && b == '*') return -1;
    // if(a == '+' && b == '/') return -1;
    // if(a == '-' && b == '/') return -1;
    return 0;
    //printf("operate error!\n");
}
void calc(Stack *s, char opt) {
    int a = top(s);
    pop(s);
    int b = top(s);
    pop(s);
    //printf("%d %c %d = %d\n", b, opt, a, precede(b, a, opt));
    push(s, precede(b, a, opt));
}

void clear(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    int m;
    scanf("%d", &m);
    char *buf = (char *)malloc(m * sizeof(char));
    getchar();
    for(int i = 0; i < m; i++) {
        scanf("%c", buf + i);
    }
    //printf("%s\n", buf);
    
    Stack* num = (Stack *)malloc(sizeof(Stack));
    Stack* opt = (Stack *)malloc(sizeof(Stack));
    init(num, m);
    init(opt, m);
    for(int i = 0; i < m; i++) {
        if(isdigit(buf[i])) push(num, buf[i] - '0');
    	else {
            if(empty(opt) || operate(buf[i], top(opt)) == 1) {
                push(opt, buf[i]);
            } else {
                calc(num, top(opt));
                pop(opt);
                push(opt, buf[i]);
            }
        }
    }
    while(empty(opt) != 1) {
        calc(num, opt->data[opt->top_index]);
        pop(opt);
    }
    printf("%d\n", top(num));
    
    return 0;
}