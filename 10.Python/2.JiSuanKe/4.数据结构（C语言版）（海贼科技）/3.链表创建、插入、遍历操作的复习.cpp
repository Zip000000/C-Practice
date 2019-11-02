#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
    struct Node* next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    //printf("已进入insert函数\n");
	if(head == NULL) {
        if(index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    
    Node* current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index-1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index-1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
	Node* current_node = head;
    while(current_node != NULL) {
        current_node == head || printf(" ");
        printf("%d",current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void clear(LinkedList head) {
	Node* current_node = head;
    while(current_node != NULL) {
        Node* delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    int p,q;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &p, &q);
        //printf("输入完毕  p_loc = %d ; q_data = %d\n", p, q);
        Node* node = (Node* )malloc(sizeof(Node));
        //printf("空间申请完毕\n");
        node->data = q;
        node->next = NULL;
        //printf("赋值完毕，准备插入\n");
        linkedlist = insert(linkedlist, node, p);
    	//printf("插入操作完毕\n");
    }
	output(linkedlist);
    return 0;
}