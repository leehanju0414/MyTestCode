#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ�� ��� ����ü ����
typedef struct node {
    int data;
    struct node* next;
} Node;

// ���ο� ��带 �����ϴ� �Լ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ���� ����Ʈ�� ����ϴ� �Լ�
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ������������ ���ĵ� ���� ����Ʈ�� ���ο� ��带 �����ϴ� �Լ�
Node* insertInOrder(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL || data < head->data) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    int i, data;

    // ���� ���� �� ���� ����Ʈ�� ����
    for (i = 0; i < 100; i++) {
        data = rand() % 1000;
        head = insertInOrder(head, data);
    }

    // ������������ ���ĵ� ���� ����Ʈ ���
    printList(head);

    return 0;
}