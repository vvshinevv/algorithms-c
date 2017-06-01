#ifndef __B_LINKED_LIST_H__
#define __B_LINKED_LIST_H__

typedef int Data;

typedef struct _bLinkedListNode {
	Data data;
	struct _bLinkedListNode * next;
} BNode;

typedef struct _bLinkedList {
	BNode * head;
	BNode * tail;
} BLinkedList;

void InitBLinkedList(BLinkedList * bL);
void InsertBLinkedList(BLinkedList * bL, Data data);
void PrintBLinkedList(BLinkedList * bL);
void DeleteALLBLinkedList(BLinkedList * bL);


#endif
