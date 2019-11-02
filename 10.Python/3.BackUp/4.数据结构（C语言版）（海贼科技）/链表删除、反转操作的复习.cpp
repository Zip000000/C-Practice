#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
	if(head == NULL) {
        printf("failed\n");
        return head;
    }
    if(index == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("success\n");
        return head;
    }
    
    
    Node* current_node = head;
    Node* delete_node = NULL;
    int count = 0;
    while(current_node != NULL && count != index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index-1) {
        if(current_node->next != NULL) {
            delete_node = current_node->next;
            current_node->next = delete_node->next;
			free(delete_node);
            printf("success\n");
            return head;
        }
    }
    printf("failed\n");
    return head;
}

LinkedList reverse(LinkedList head) {
    if(head == NULL) {
        return head;
    }
    
    Node* current_node = head->next;
    Node* next_node = NULL;
    head->next = NULL;
    while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;

}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
	int m;
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++) {
        int t;
        int a = 0, b = 0;
        scanf("%d", &t);
        switch(t){
            case 1:{
                scanf("%d %d", &a, &b);
                Node* node = (Node*)malloc(sizeof(Node));
                node->next = NULL;
                node->data = b;
                linkedlist = insert(linkedlist, node, a); break;}
            case 2:{
                output(linkedlist); break;}
            case 3:{
                scanf("%d", &a);
                linkedlist = delete_node(linkedlist, a); break;}
            case 4:{
                linkedlist = reverse(linkedlist); break;}
        }
    }
    
    
    return 0;
}