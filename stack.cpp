#include "stack.h"


//Check if the stack is empty
bool Stack::IsEmpty()
{
	if (first == nullptr)
		return true;
	return false;
}

//Make empty stack
void Stack::MakeEmpty()
{
	first = nullptr;
}

//Push new ItemType to first
void Stack::Push(ItemType item)
{
	ItemType* temp = new ItemType(item);
	if (IsEmpty()){
		first = temp;
	}
	else {
		temp->set_next(first);
		first = temp;
	}

}

//Pop first ItemType (delete allocation)
ItemType Stack::Pop(void)
{
	if (IsEmpty())
	{
		return *first;
	}
	else
	{
		ItemType temp(*first);
		delete first;
		first = temp.getNext();

		return temp;
	}
}

//Distructor
Stack::~Stack()
{
	if (first == nullptr)
		return;
	else
		while (IsEmpty() == false)
		{
			Pop();
		}
}
