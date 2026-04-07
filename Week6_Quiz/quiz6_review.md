# 문제
6. 다음은 링크드리스트에서 특정 위치의 Node를 찾는 코드이다. 구조체의 내용을 참고하여. 빈 칸의 코드를 작성하시오. 

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

    // 코드 작성

    return temp;
}


---

# 답변

    // 입력값 검증 코드
    if (ll == NULL || ll->head == NULL || index < 0 || index >= ll->size) {
        return NULL;
    }

    // temp 초기화
    temp = ll->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }


---

# 정답
    
    if (ll == NULL || index < 0 || index >= ll->size) {
        return NULL;
    }

    temp = ll->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

