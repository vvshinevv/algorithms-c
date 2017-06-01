#ifndef __ARRAY_BASED_STACK_H__
#define __ARRAY_BASED_STACK_H__

#define STACK_LEN 100

typedef int abSData;

typedef struct _arrayBasedStack {
	int top;
	abSData data[STACK_LEN];
} ArrayBasedStack;

void InitArrayBasedStack(ArrayBasedStack * abS);
bool IsEmptyArrayBasedStack(ArrayBasedStack * abS);

void PushArrayBasedStack(ArrayBasedStack * abS, abSData data);
void PopArrayBasedStack(ArrayBasedStack * abS);
abSData PeekArrayBasedStack(ArrayBasedStack * abS);

#endif