
//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section F - Binary Search Trees Questions
Purpose: Implementing the required functions for Question 1
한국어: 문제 1에서 요구하는 함수를 구현하는 것이 목적 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
///////////////////////////////////////////////////////////////////////////////////

typedef struct _bstnode{
	int item;
	struct _bstnode *left;
	struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode
			// 한국어: BSTNode의 정의는 변경하지 마세요

typedef struct _QueueNode {
	BSTNode *data;
	struct _QueueNode *nextPtr;
}QueueNode; // You should not change the definition of QueueNode
			// 한국어: QueueNode의 정의는 변경하지 마세요


typedef struct _queue
{
	QueueNode *head;
	QueueNode *tail;
}Queue; // You should not change the definition of queue
		// 한국어: queue의 정의는 변경하지 마세요

///////////////////////////////////////////////////////////////////////////////////

// You should not change the prototypes of these functions
// 한국어: 이 함수들의 원형은 변경하지 마세요
void levelOrderTraversal(BSTNode *node);

void insertBSTNode(BSTNode **node, int value);

BSTNode* dequeue(QueueNode **head, QueueNode **tail);
void enqueue(QueueNode **head, QueueNode **tail, BSTNode *node);
int isEmpty(QueueNode *head);
void removeAll(BSTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
	int c, i;
	c = 1;

	//Initialize the Binary Search Tree as an empty Binary Search Tree
	// 한국어: 이진 탐색 트리를 빈 트리로 초기화
	BSTNode *root;
	root = NULL;

	printf("1: Insert an integer into the binary search tree;\n");
	printf("2: Print the level-order traversal of the binary search tree;\n");
	printf("0: Quit;\n");


	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the Binary Search Tree: ");
			scanf("%d", &i);
			insertBSTNode(&root, i);
			break;
		case 2:
			printf("The resulting level-order traversal of the binary search tree is: ");
			levelOrderTraversal(root); // You need to code this function
										// 한국어: 이 함수는 직접 구현해야 합니다
			printf("\n");
			break;
		case 0:
			removeAll(&root);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}

	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void levelOrderTraversal(BSTNode* root)
{
	/* add your code here */
	/* 한국어: 여기에 코드를 작성하세요 */

	if (root == NULL) {
		return;
	}
	QueueNode *head = NULL;
	QueueNode *tail = NULL;

	enqueue(&head, &tail, root);

	while(!isEmpty(head)) {
		BSTNode *cur = dequeue(&head, &tail);

		printf("%d ", cur -> item);

		if (cur->left != NULL) {
			enqueue(&head, &tail, cur->left);
		};

		if (cur->right != NULL) {
			enqueue(&head, &tail, cur->right);
		};
	}
}

///////////////////////////////////////////////////////////////////////////////

void insertBSTNode(BSTNode **node, int value){
	if (*node == NULL)
	{
		*node = malloc(sizeof(BSTNode));

		if (*node != NULL) {
			(*node)->item = value;
			(*node)->left = NULL;
			(*node)->right = NULL;
		}
	}
	else
	{
		if (value < (*node)->item)
		{
			insertBSTNode(&((*node)->left), value);
		}
		else if (value >(*node)->item)
		{
			insertBSTNode(&((*node)->right), value);
		}
		else
			return;
	}
}

//////////////////////////////////////////////////////////////////////////////////

// enqueue node
// 한국어: 큐에 노드 삽입
void enqueue(QueueNode **headPtr, QueueNode **tailPtr, BSTNode *node)
{
	// dynamically allocate memory
	// 한국어: 동적으로 메모리 할당
	QueueNode *newPtr = malloc(sizeof(QueueNode));

	// if newPtr does not equal NULL
	// 한국어: newPtr가 NULL이 아니면
	if (newPtr != NULL) {
		newPtr->data = node;
		newPtr->nextPtr = NULL;

		// if queue is empty, insert at head
		// 한국어: 큐가 비어 있으면 head에 삽입
		if (isEmpty(*headPtr)) {
			*headPtr = newPtr;
		}
		else { // insert at tail
				// 한국어: tail에 삽입
			(*tailPtr)->nextPtr = newPtr;
		}

		*tailPtr = newPtr;
	}
	else {
		printf("Node not inserted");
	}
}

BSTNode* dequeue(QueueNode **headPtr, QueueNode **tailPtr)
{
	BSTNode *node = (*headPtr)->data;
	QueueNode *tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL) {
		*tailPtr = NULL;
	}

	free(tempPtr);

	return node;
}

int isEmpty(QueueNode *head)
{
	return head == NULL;
}

void removeAll(BSTNode **node)
{
	if (*node != NULL)
	{
		removeAll(&((*node)->left));
		removeAll(&((*node)->right));
		free(*node);
		*node = NULL;
	}
}
