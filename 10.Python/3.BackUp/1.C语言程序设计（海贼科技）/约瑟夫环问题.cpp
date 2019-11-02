#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    return 0;
}

Node *circle_create(int n) {
    Node *temp, *new_node, *head;
    int i;

    // 创建第一个链表节点并加数据
    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // 创建第 2 到第 n 个链表节点并加数据
    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // 最后一个节点指向头部构成循环链表
    temp->next = head;

    return head;
}

void count_off(Node *head, int n, int k, int m) {
    Node* curr;
    Node* dele;
    curr=head;
    for(int j=0;j<k-1;j++)
    {
        curr=curr->next;
    }
    int i=1;
    if(m==1)
    {
    	int count=1;
        while(count<n)
        {
            printf("%d ",curr->data);
            curr=curr->next;
            count++;
        }
        printf("%d",curr->data);
    }
    else
    {
        
        while(curr->next != curr)
        {
            if(i==m-1)   //curr的下一个是要输出的
            {
                printf("%d ",curr->next->data);
                dele=curr->next;
                curr->next=dele->next;
                free(dele);
                curr=curr->next;
                i=1;
            }
            else
            {
                curr=curr->next;
                i++;
            }
        }
    printf("%d",curr->data);
    }
return;
}