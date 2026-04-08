//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section F - Binary Search Trees Questions
Purpose: Implementing the required functions for Question 5
		 Implementing 'remove node' operation for BST*/
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
void postOrderIterativeS2(BSTNode *root);

void insertBSTNode(BSTNode **node, int value);

void push(Stack *stack, BSTNode *node);
BSTNode *pop(Stack *s);
BSTNode *peek(Stack *s);
int isEmpty(Stack *s);
void removeAll(BSTNode **node);
BSTNode* removeNodeFromTree(BSTNode *root, int value);

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
			postOrderIterativeS2(root); // You need to code this function
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

void postOrderIterativeS2(BSTNode *root)
{
	/* add your code here */
	/* 한국어: 여기에 코드를 작성하세요 */
	
	// 요구사항: 전위순회를 반복형으로 출력 (순서: Left -> Right -> Root)

	if (root == NULL) {
		return;
	}

	// 스택 초기화
	Stack s;
    s.top = NULL;

	BSTNode *cur = root;
	BSTNode *lastVisited = NULL;

	// 스택이 비어 있고 현재 노드도 없을 때까지 반복
	while(cur != NULL || !isEmpty(&s)) {
		// 현재 노드가 있으면 왼쪽 자식으로 계속 내려가며 스택에 저장
		if (cur != NULL) {
			push(&s, cur);
			cur = cur->left;
		} else {
			BSTNode *peekNode = peek(&s); // 스택 top 노드를 확인

			// 오른쪽 자식이 아직 방문되지 않았다면 오른쪽 서브트리로 이동
			if (peekNode->right != NULL && lastVisited != peekNode->right) {
				cur = peekNode->right;
			} else { // 왼쪽과 오른쪽 서브트리 방문이 끝났으면 현재 노드 출력
				printf("%d ", peekNode->item);
				lastVisited = pop(&s);
			}
		}
	}
}

/* Given a binary search tree and a key, this function
   deletes the key and returns the new root. Make recursive function. */
BSTNode* removeNodeFromTree(BSTNode *root, int value)
{
	/* add your code here */
	/* 한국어: 여기에 코드를 작성하세요 */

	// 요구사항: BST에서 특정 값을 가진 노드를 삭제하고, 새 루트를 반환하는 재귀 함수를 구현

	//  BST 성질을 이용해 삭제할 값을 찾아 내려가야 함.

	if (root == NULL) {
		return NULL;
	}

	if (value < root->item) {
		root->left = removeNodeFromTree(root->left, value); // 왼쪽으로 재귀. BST에서는 작은 값이 왼쪽에만 존재하기 때문
	}else if (value > root->item) {
		root->right = removeNodeFromTree(root->right, value); // 오른쪽으로 재귀. BST에서는 큰 값이 오른쪽에만 존재하기 때문
	}else { // 삭제 케이스 (value == root->item이면 이 노드를 삭제)
		
		if (root->left == NULL && root->right == NULL) { // 자식이 없는 경우: free 하고 NULL 반환
			free(root);
			return NULL;
		} 
		// 자식이 하나만 있는 경우: 그 자식을 새 루트처럼 올리고 현재 노드를 free
		else if (root->left == NULL) { 
			BSTNode *temp = root->right;
			free(root);
			return temp;
		} else if ( root->right == NULL) { 
			BSTNode *temp = root->left;
			free(root);
			return temp;
		} else { 
			// 자식이 두 개 있는 경우
			// temp에 오른쪽 서브트리의 최솟값을 저장
			BSTNode *temp = root->right; 
			while(temp->left != NULL) {
				temp = temp->left;
			}
			
			root->item = temp->item; // temp의 값을 루트의 값으로 치환
			/* root의 오른쪽 서브트리에서 temp->item 값을 삭제한 뒤, 
			삭제 결과로 바뀐 오른쪽 서브트리의 시작 노드를 다시 root->right에 저장 */
			// 새로운 오른쪽 서브트리 루트 = removeNodeFromTree(기존 오른쪽 서브트리 루트, 삭제할값);
			root->right = removeNodeFromTree(root->right, temp->item); 
		}
	}

	return root;
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
