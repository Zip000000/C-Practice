#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
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
    Node* current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index - 1) {
     	current_node = current_node->next;   
        count++;
    }
    if(count != index - 1) return head;
    node->next = current_node->next;
    current_node->next = node;
    return head;
}

LinkedList delete(LinkedList head, int index) {
    Node* delete_node = NULL;
    if(index == 0) {
    	delete_node = head;
        head = head->next;
        free(delete_node);
        return head;
    }
    
    Node* current_node = head;
    int cnt = 0;
    while(current_node->next != NULL && cnt < index - 1) {
        current_node = current_node->next;
        cnt++;
    }
    if(cnt != index - 1) return head;
    delete_node = current_node->next;
    current_node->next = delete_node->next;
    free(delete_node);
    return head;
}
LinkedList get_node(LinkedList head, int index) {
    Node* current_node = head;
    int cnt = 0;
    while(current_node->next != NULL && cnt < index) {
        current_node = current_node->next;
        cnt++;
    }
    if(cnt != index) return head;
    return current_node;
}

void output(LinkedList head) {
    Node* current_node = head;
    while(current_node != NULL) {
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    LinkedList head = NULL;
    
    for(int i = 1; i <= N; i++) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        head = insert(head, node, i - 1);
    }
    //printf("插入成功\n");
    //delete(head, 2);
    int delete_num = 0;
    int temp;
    for(int i = 0; i < M; i++) {
        scanf("%d", &temp);
        head = delete(head, temp - 1);
		delete_num++;
    }
    int mid = (N - delete_num) / 2;
    printf("%d\n", get_node(head, mid)->data);
    //output(get_node(head, mid));
    
    return 0;
}