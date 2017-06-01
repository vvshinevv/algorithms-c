#include <iostream>
#include "BasicLinkedList.h"
using namespace std;
void InitBLinkedList(BLinkedList * bL) {
	bL->head = bL->tail = NULL;
}

void InsertBLinkedList(BLinkedList * bL, Data data) {
	BNode * newNode = (BNode *)malloc(sizeof(BNode));
	newNode->next = NULL;
	newNode->data = data;

	if (bL->head == NULL && bL->tail == NULL) 
		bL->head = newNode;
	 else 
		bL->tail->next = newNode;
	
	bL->tail = newNode;
}

//반환값 없이 모든 노드 삭제
void DeleteALLBLinkedList(BLinkedList * bL) {
	if (bL->head == NULL && bL->tail == NULL) {
		cout << "List Is Empty!" << endl;
		exit(-1);
	}
	
	////////////////////////////////////////////
	BNode * delNode = bL->head;
	while (delNode != NULL) {
		BNode * tmpNode = delNode;
		cout << delNode->data << " ";

		delNode = delNode->next;
		free(tmpNode);
	}
	////////////////////////////////////////////

	bL->head = bL->tail = NULL;
}

void PrintBLinkedList(BLinkedList * bL) {
	if (bL->head == NULL && bL->tail == NULL) {
		cout << "List Is Empty!" << endl;
		exit(-1);
	}

	BNode * curNode = bL->head;
	while (curNode != NULL) {
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
}