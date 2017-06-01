#if 0
#include <iostream>
#include "BasicLinkedList.h"

int main(void) {
	BLinkedList bL;
	InitBLinkedList(&bL);
	InsertBLinkedList(&bL, 1); InsertBLinkedList(&bL, 2);
	InsertBLinkedList(&bL, 3); InsertBLinkedList(&bL, 4);
	InsertBLinkedList(&bL, 5); InsertBLinkedList(&bL, 6);

	PrintBLinkedList(&bL); std::cout << std::endl;
	DeleteALLBLinkedList(&bL); std::cout << std::endl;
	PrintBLinkedList(&bL);

	return 0;
}
#endif