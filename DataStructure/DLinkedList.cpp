#include <iostream>
#include "DLinkedList.h"
using namespace std;
void lLInit(LinkedList * lL) {
	DNode * dNode = (DNode *)malloc(sizeof(DNode));
	dNode->next = NULL;

	lL->head = dNode;
	lL->comp = NULL;
	lL->numOfData = 0;
}

void lLInsert(LinkedList * lL, LData data) {
	if (lL->comp == NULL) {
		DNode * newNode = (DNode *)malloc(sizeof(DNode));
		newNode->data = data;

		newNode->next = lL->head->next;
		lL->head->next = newNode;
		(lL->numOfData)++;
	} else {
		lLInsertByPrecede(lL, data);
	}
}

void lLInsertByPrecede(LinkedList * lL, LData data) {
	DNode * newNode = (DNode *)malloc(sizeof(DNode));
	newNode->data = data;
	lL->cur = lL->head;

	while (lL->cur->next != NULL && lL->comp(data, lL->cur->next->data) != 0) {
		lL->cur = lL->cur->next;
	}

	newNode->next = lL->cur->next;
	lL->cur->next = newNode;
	(lL->numOfData)++;
}

// 삭제 반환 없음
// Dummy를 사용하는 이유
// 삭제 시 일관성 유지
void lLRemove(LinkedList * lL, LData data) {
	if (lL->head->next == NULL) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	lL->before = lL->head;
	lL->cur = lL->head->next;

	while (lL->cur != NULL) {
		if (lL->cur->data == data) {
			DNode * delNode = lL->cur;

			lL->cur = delNode->next;
			lL->before->next = lL->cur;

			(lL->numOfData)--;
			free(delNode);
		} else {
			lL->before = lL->cur;
			lL->cur = lL->cur->next;
		}
	}
}

int lLSize(LinkedList * lL) {
	return lL->numOfData;
}

void lLPrint(LinkedList * lL) {
	lL->cur = lL->head->next;

	while (lL->cur != NULL) {
		cout << lL->cur->data << " ";
		lL->cur = lL->cur->next;
	}
}

void SetSortRule(LinkedList * lL, int(*comp)(LData d1, LData d2)) {
	lL->comp = comp;
}