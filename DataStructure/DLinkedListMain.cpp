#if 1
#include <iostream>
#include "DLinkedList.h"
using namespace std;

int WhoIsPrecede(LData d1, LData d2) {
	if (d1 > d2)
		return 1;
	else
		return 0;
}

int main(void) {
	LinkedList lL;

	lLInit(&lL);
	SetSortRule(&lL, WhoIsPrecede); // 차례로 삽입

	lLInsert(&lL, 2); lLInsert(&lL, 2);
	lLInsert(&lL, 3); lLInsert(&lL, 4);
	lLInsert(&lL, 5); lLInsert(&lL, 2);

	lLPrint(&lL);

	cout << endl;
	cout << lLSize(&lL) << endl;

	lLRemove(&lL, 2); // 2인 것을 모두 지워라

	lLPrint(&lL);

	cout << endl;
	cout << lLSize(&lL) << endl;


	return 0;
}
#endif