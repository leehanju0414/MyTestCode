#include <stdio.h>
#include <stdlib.h>

// 연결리스트 노드 구조체
struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL; // 연결리스트의 시작을 나타내는 노드 포인터
    struct node* curr = NULL; // 현재 노드를 나타내는 노드 포인터
    struct node* new_node = NULL; // 새로운 노드를 만들 때 사용하는 노드 포인터
    int i, rand_num;

    // 랜덤 시드 초기화
    srand(1);

    // 100개의 난수 생성 및 연결리스트에 삽입
    for (i = 0; i < 100; i++) {
        rand_num = rand(); // 0부터 RAND_MAX 사이의 난수 생성
        new_node = (struct node*)malloc(sizeof(struct node)); // 새로운 노드 할당
        new_node->data = rand_num;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node; // 연결리스트가 비어있다면 새로운 노드를 시작 노드로 지정
        }
        else {
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node; // 현재 노드의 다음 노드로 새로운 노드 삽입
        }
    }

    // 연결리스트 출력
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}