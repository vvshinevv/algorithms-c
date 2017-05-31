/**
p.47 재귀를 이용하여
연결리스트 정순 & 역순으로 출력하기
*/
#if 0
#include <iostream>
using namespace std;
typedef struct _linkedListNode {
	int data;
	struct _linkedListNode * next;
} Node;
typedef struct _List {
	Node * head;
	int listCnt;
} LinkedList;

void InitLinkedListNode(LinkedList * linkedList) {
	Node * dummyNode = (Node *)malloc(sizeof(Node));
	dummyNode->next = NULL;

	linkedList->head = dummyNode;
	linkedList->listCnt = 0;
}

void InsertData(LinkedList * linkedList, int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = linkedList->head->next;
	linkedList->head->next = newNode;
	linkedList->listCnt++;
}

void PrintLinkedListNode(LinkedList * linkedList, Node * cur) {
	if (cur == NULL) return;
	cout << cur->data << " ";
	PrintLinkedListNode(linkedList, cur->next);
}

void PrintLinkedListNodeReverse(LinkedList * linkedList, Node * cur) {
	if (cur == NULL) return;

	PrintLinkedListNodeReverse(linkedList, cur->next);
	cout << cur->data << " ";
}

int main(void) {
	LinkedList linkedList;
	InitLinkedListNode(&linkedList);

	for (int i = 0; i < 4670; i++) {
		InsertData(&linkedList, 10);
	}

	PrintLinkedListNode(&linkedList, linkedList.head->next);
	cout << endl;

	PrintLinkedListNodeReverse(&linkedList, linkedList.head->next);


	return 0;
}
#endif