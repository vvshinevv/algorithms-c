#ifndef __LIST_BASED_STACK_H__
#define __LIST_BASED_STACK_H__

typedef int lbSData;

typedef struct _listBasedStackNode {
	lbSData data;
	struct _listBasedStackNode * next;
} ListBasedStackNode;


typedef struct _listBasedStack {
	ListBasedStackNode * top;
} ListBasedStack;

void InitListBasedStack(ListBasedStack * lbS);
bool IsListBasedStackEmpty(ListBasedStack * lbS);

void PushListBasedStack(ListBasedStack * lbS, lbSData data);
void PopListBasedStack(ListBasedStack * lbS);
lbSData PeekListBasedStack(ListBasedStack * lbS);


#endif