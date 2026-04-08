//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section F - Binary Search Trees Questions
Purpose: Implementing the required functions for Question 4
한국어: 문제 4에서 요구하는 함수를 구현하는 것이 목적 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _bstnode{
	int item;
	struct _bstnode *left;
	struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode
			// 한국어: BSTNode의 정의는 변경하지 마세요

typedef struct _stackNode{
	BSTNode *data;
	struct _stackNode *next;
}StackNode; // You should not change the definition of StackNode
			// 한국어: StackNode의 정의는 변경하지 마세요

typedef struct _stack
{
	StackNode *top;
}Stack; // You should not change the definition of Stack
		// 한국어: Stack의 정의는 변경하지 마세요

///////////////////////// function prototypes ////////////////////////////////////
///////////////////////// 한국어: 함수 원형 선언 ////////////////////////////////////

// You should not change the prototypes of these functions
// 한국어: 이 함수들의 원형은 변경하지 마세요
void postOrderIterativeS1(BSTNode *node);

void insertBSTNode(BSTNode **node, int value);

// You may use the following functions or you may write your own
// 한국어: 아래 함수를 사용해도 되고, 직접 작성해도 됩니다
void push(Stack *stack, BSTNode *node);
BSTNode *pop(Stack *s);
BSTNode *peek(Stack *s);
int isEmpty(Stack *s);
void removeAll(BSTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
	int c, i;
	c = 1;

	//Initialize the Binary Search Tree as an empty Binary Search Tree
	// 한국어: 이진 탐색 트리를 빈 트리로 초기화
	BSTNode * root;
	root = NULL;

	printf("1: Insert an integer into the binary search tree;\n");
	printf("2: Print the post-order traversal of the binary search tree;\n");
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
			printf("The resulting post-order traversal of the binary search tree is: ");
			postOrderIterativeS1(root); // You need to code this function
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

void postOrderIterativeS1(BSTNode *root)
{
	/* add your code here */
	/* 한국어: 여기에 코드를 작성하세요 */

	// 요구사항: BST의 post-order 순회 결과를 반복형(iterative)으로 출력 (left -> right -> root)

	// 이 노드를 지금 출력해도 되는지를 판단하는 로직: 
	// 루트 -> 오른쪽 -> 왼쪽 순으로 집어 넣어서 마지막 노드(가장 큰 레벨의 가장 좌측 노드)까지 모두 스택에 넣음.
	/*
	동작 원리
	1) 왼쪽으로 계속 내려가며 스택에 push합니다.
	2) 더 내려갈 왼쪽이 없으면 스택 top을 봅니다.
	3) 그 노드의 오른쪽 자식이 아직 처리되지 않았다면 오른쪽으로 이동합니다.
	4) 왼쪽과 오른쪽이 모두 끝난 경우에만 그 노드를 출력하고 pop합니다.
	*/

	if (root == NULL) {
		return;
	}

	// 스택 초기화
	Stack s;
    s.top = NULL;

    BSTNode *curr = root;
    BSTNode *lastVisited = NULL;

	// 스택이 비어 있고 현재 노드도 없을 때까지 반복
	while (curr != NULL || !isEmpty(&s))
    {
		// 현재 노드가 있으면 왼쪽 자식으로 계속 내려가며 스택에 저장
        if (curr != NULL)
        {
            push(&s, curr);
            curr = curr->left;
        }
        else
        {
			// 스택 top 노드를 확인
            BSTNode *peekNode = peek(&s);

			// 오른쪽 자식이 아직 방문되지 않았다면 오른쪽 서브트리로 이동
            if (peekNode->right != NULL && lastVisited != peekNode->right)
            {
                curr = peekNode->right;
            }
            else
            {
				// 왼쪽과 오른쪽 서브트리 방문이 끝났으면 현재 노드 출력
                printf("%d ", peekNode->item);
                lastVisited = pop(&s);
            }
        }
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

void push(Stack *stack, BSTNode * node)
{
	StackNode *temp;

	temp = malloc(sizeof(StackNode));

	if (temp == NULL)
		return;
	temp->data = node;

	if (stack->top == NULL)
	{
		stack->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack->top;
		stack->top = temp;
	}
}


BSTNode * pop(Stack * s)
{
	StackNode *temp, *t;
	BSTNode * ptr;
	ptr = NULL;

	t = s->top;
	if (t != NULL)
	{
		temp = t->next;
		ptr = t->data;

		s->top = temp;
		free(t);
		t = NULL;
	}

	return ptr;
}

BSTNode * peek(Stack * s)
{
	StackNode *temp;
	temp = s->top;
	if (temp != NULL)
		return temp->data;
	else
		return NULL;
}

int isEmpty(Stack *s)
{
	if (s->top == NULL)
		return 1;
	else
		return 0;
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
