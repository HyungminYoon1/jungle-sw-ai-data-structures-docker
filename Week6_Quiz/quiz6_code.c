#include <stddef.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
} LinkedList;

ListNode * findNode(LinkedList *ll, int index){
    
    ListNode *temp;

    // 입력값 검증 코드
    if (ll == NULL || ll->head == NULL || index < 0 || index >= ll->size) {
        return NULL;
    }

    // temp 초기화
    temp = ll->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp;
}