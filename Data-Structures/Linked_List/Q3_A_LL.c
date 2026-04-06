//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 3
한국어: 문제 3에서 요구하는 함수를 구현하는 것이 목적 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode
					// 한국어: ListNode의 정의는 변경하지 마세요

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList
						// 한국어: LinkedList의 정의는 변경하지 마세요


//////////////////////// function prototypes /////////////////////////////////////
//////////////////////// 한국어: 함수 원형 선언 /////////////////////////////////////

// You should not change the prototype of this function
// 한국어: 이 함수의 원형은 변경하지 마세요
void moveOddItemsToBack(LinkedList *ll);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	// 한국어: 연결 리스트 1을 빈 연결 리스트로 초기화
	ll.head = NULL;
	ll.size = 0;


	printf("1: Insert an integer to the linked list:\n");
	printf("2: Move all odd integers to the back of the linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			moveOddItemsToBack(&ll); // You need to code this function
									// 한국어: 이 함수는 직접 구현해야 합니다
			printf("The resulting linked list after moving odd integers to the back of the linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void moveOddItemsToBack(LinkedList *ll)
{
	/* add your code here */
	/* 한국어: 여기에 코드를 작성하세요 */

	// 짝수는 앞에 남기고 홀수는 뒤로 보내기

	// 풀이 1) 포인터만 써서 노드 재연결 - 새 노드를 만들지 않고, 기존 노드를 짝수 리스트와 홀수 리스트로 나눈 뒤 마지막에 붙임
	ListNode *cur = ll->head;
	ListNode *nextNode = NULL;
    ListNode *evenHead = NULL, *evenTail = NULL; // 짝수를 담은 연결 리스트 노드
    ListNode *oddHead = NULL, *oddTail = NULL;   // 홀수를 담은 연결 리스트 노드

	if (ll == NULL || ll->head == NULL)
        return;

	while (cur != NULL) {
        nextNode = cur->next; // 다음 노드 미리 탐색
        cur->next = NULL; // 현재 노드와 다음 노드와의 연결 끊기 - 세그폴트 방지용

		if (cur->item % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = cur;
                evenTail = cur;
            } else {
                evenTail->next = cur; // 현재 노드 cur를 even 리스트의 맨 뒤에 붙인다.
                evenTail = cur; // evenTail도 현재 노드로 갱신
            }
        } else {
            if (oddHead == NULL) {
                oddHead = cur;
                oddTail = cur;
            } else {
                oddTail->next = cur;
                oddTail = cur;
            }
        }
		cur = nextNode; // 다음 노드 검토
	}

	if (evenHead == NULL) {
        ll->head = oddHead;
    } else {
        evenTail->next = oddHead;
        ll->head = evenHead;
    }
}
/*
// 풀이 2) 제공된 findNode / removeNode / insertNode만 쓰는 인덱스 방식
void moveOddItemsToBack(LinkedList *ll) {
	int originalSize, oddCount, i;
    int value;

	if (ll == NULL || ll->size == 0)
        return;

	originalSize = ll->size; // 처음 리스트 길이
    oddCount = 0;
    i = 0;

	while (i < originalSize - oddCount) { // originalSize - oddCount 는 검사할 구간의 길이(아직 앞쪽에서 검사해야 하는 원소 개수)
        value = findNode(ll, i)->item;

        if (value % 2 == 1) {
            removeNode(ll, i); // 홀수 제거
            insertNode(ll, ll->size, value);  // 홀수를 맨 뒤에 넣는다.
            oddCount++; // 홀수를 뒤로 보낼 때마다 oddCount를 1 늘린다.
        } else {
            i++;
        }
    }
}
*/


///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	// 한국어: 리스트가 비어 있거나 첫 노드를 삽입하는 경우 head 포인터를 갱신해야 함
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	// 한국어: 목표 위치의 이전 노드와 해당 위치의 노드를 찾음
	// 한국어: 새 노드를 만들고 링크를 다시 연결함
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	// 한국어: 제거할 수 있는 가장 큰 인덱스는 size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	// 한국어: 첫 노드를 제거하는 경우 head 포인터를 갱신해야 함
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	// 한국어: 목표 위치의 이전 노드와 이후 노드를 찾음
	// 한국어: 대상 노드를 해제하고 링크를 다시 연결함
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
