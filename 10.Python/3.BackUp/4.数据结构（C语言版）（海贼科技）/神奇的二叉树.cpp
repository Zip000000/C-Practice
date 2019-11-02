#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lc;
    struct Node *rc;
} Node;

Node *init(char val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->lc = NULL;
    n->rc = NULL;
    return n;
}

Node *build(char pre_str[], char in_str[], int len) {
    Node *root = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if(pos > 0) root->lc = build(pre_str + 1, in_str, pos);
    if(len - pos - 1) root->rc = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    return root;
}

void post_order(Node *root) {
    if(root->lc != NULL) post_order(root->lc);
    if(root->rc != NULL) post_order(root->rc);
    printf("%c", root->data);
}

Node *mirror(Node *root) {
    if(root->lc) root->lc = mirror(root->lc);
    if(root->rc) root->rc = mirror(root->rc);
    Node *tmp = root->lc;
    root->lc = root->rc;
    root->rc = tmp;
    return root;
}

int main() {
    char pre_str[60];
    char in_str[60];
    scanf("%s", pre_str);
    scanf("%s", in_str);
    
    Node *root = build(pre_str, in_str, strlen(pre_str));
    
    post_order(root);
    printf("\n");
    Node *root2 = mirror(root);
    post_order(root2);
    printf("\n");
    return 0;
}