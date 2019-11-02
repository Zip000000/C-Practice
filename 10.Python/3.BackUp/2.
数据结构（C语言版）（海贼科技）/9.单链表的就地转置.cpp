#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char data;
    struct Node* next;
} Node, *LinkedList;

LinkedList insert(LinkedList head, Node* node, int index) {
    if(head == NULL) {
        if(index == 0) return node;
        return head;
    }
    if(index == 0) {
        node->next = head;
        return node;
    }
    Node* cnode = head;
    int cnt = 0;
    while(cnode->next != NULL && cnt < index - 1) {
        cnode = cnode->next;
        cnt++;
    }
    if(cnt != index - 1) return head;
    node->next = cnode->next;
    cnode->next = node;
    return head;
}

void output(LinkedList head) {
    Node* cnode = head;
    while(cnode != NULL) {
        printf("%c", cnode->data);
        if(cnode->next != NULL) printf(" ");
        cnode = cnode->next;
    }
    //printf("\n");
}

LinkedList reverse(LinkedList head) {
    if(head == NULL || head->next == NULL) return head;
    if(head->next->next == NULL){
        Node* newhead = head->next;
        newhead->next = head;
        head->next = NULL;
        return newhead;
    }
    int cnt = 0; 
    Node* left_node = head;
	Node* mid_node = head->next;
	Node* right_node = head->next->next;
    while(right_node != NULL) {
        mid_node->next = left_node;
        left_node = mid_node;
        mid_node = right_node;
        right_node = right_node->next;
    }
    mid_node->next = left_node;
    head->next = NULL;
    return mid_node;
}


int main() {
	int n;
    scanf("%d", &n);
    LinkedList head = NULL;
    for(int i = 1; i <= n; i++) {
        char temp;
        getchar();
        scanf("%c", &temp);
        //getchar();
        //printf("%c\n", temp);
        Node* node = (Node*)malloc(sizeof(Node));
        node->next = NULL;
        node->data = temp;
        head = insert(head, node, i - 1);
    }
    //output(head);
    head = reverse(head);
    output(head);
    return 0;
}