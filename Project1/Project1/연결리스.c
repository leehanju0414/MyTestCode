#include <stdio.h>
#include <stdlib.h>

// ���Ḯ��Ʈ ��� ����ü
struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL; // ���Ḯ��Ʈ�� ������ ��Ÿ���� ��� ������
    struct node* curr = NULL; // ���� ��带 ��Ÿ���� ��� ������
    struct node* new_node = NULL; // ���ο� ��带 ���� �� ����ϴ� ��� ������
    int i, rand_num;

    // ���� �õ� �ʱ�ȭ
    srand(1);

    // 100���� ���� ���� �� ���Ḯ��Ʈ�� ����
    for (i = 0; i < 100; i++) {
        rand_num = rand(); // 0���� RAND_MAX ������ ���� ����
        new_node = (struct node*)malloc(sizeof(struct node)); // ���ο� ��� �Ҵ�
        new_node->data = rand_num;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node; // ���Ḯ��Ʈ�� ����ִٸ� ���ο� ��带 ���� ���� ����
        }
        else {
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node; // ���� ����� ���� ���� ���ο� ��� ����
        }
    }

    // ���Ḯ��Ʈ ���
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}