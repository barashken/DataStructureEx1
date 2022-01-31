#ifndef STACK_H
#define STACK_H

#include "itemType.h"

class Stack
{
private:
	ItemType* first;

public:
	Stack() : first(new ItemType()) { MakeEmpty(); }
	bool IsEmpty();
	void MakeEmpty();
	void Push(ItemType item);
	ItemType Pop(void);
	~Stack();

};

#endif // STACK.H