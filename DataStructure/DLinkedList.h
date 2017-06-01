#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

/**
* 연결 형태가 한쪽 방향으로 전개 되는 '단순 연결 리스트' 작성
* 노드를 머리에 추가하는 방식으로 연결리스트를 구현
*/

typedef int LData;

typedef struct _dNode {
	LData data;
	struct _dNode * next;
} DNode;

typedef struct _dLinkedList {
	DNode * head;
	DNode * cur;
	DNode * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} dLinkedList;

typedef dLinkedList LinkedList;

void lLInit(LinkedList * lL);
void lLInsert(LinkedList * lL, LData data);
void lLInsertByPrecede(LinkedList * lL, LData data);

void lLRemove(LinkedList * lL, LData data);
int lLSize(LinkedList * lL);

void lLPrint(LinkedList * lL);
void SetSortRule(LinkedList * lL, int(*comp)(LData d1, LData d2));
#endif