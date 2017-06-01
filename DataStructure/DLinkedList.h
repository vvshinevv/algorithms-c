#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

/**
* ���� ���°� ���� �������� ���� �Ǵ� '�ܼ� ���� ����Ʈ' �ۼ�
* ��带 �Ӹ��� �߰��ϴ� ������� ���Ḯ��Ʈ�� ����
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