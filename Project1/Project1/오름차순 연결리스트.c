#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 구조체 정의
typedef struct node {
    int data;
    struct node* next;
} Node;

// 새로운 노드를 생성하는 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트를 출력하는 함수
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 오름차순으로 정렬된 연결 리스트에 새로운 노드를 삽입하는 함수
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

    // 난수 생성 및 연결 리스트에 삽입
    for (i = 0; i < 100; i++) {
        data = rand() % 1000;
        head = insertInOrder(head, data);
    }

    // 오름차순으로 정렬된 연결 리스트 출력
    printList(head);

    return 0;
}