#include "itemType.h"

//Copy Ctor
ItemType::ItemType(const ItemType& newItemType)
{
	arr = newItemType.arr;
	n = newItemType.n;
	x = newItemType.x;
	y = newItemType.y;
	line = newItemType.line;
	next = newItemType.next;
}


//Getters

int* ItemType::get_arr()
{
	return arr;
}

int ItemType::get_n()
{
	return n;
}

int ItemType::get_x()
{
	return x;
}

int ItemType::get_y()
{
	return y;
}

Line ItemType::getLine()
{
	return line;
}

ItemType* ItemType::getNext()
{
	return next;
}


//Setters

void ItemType::set_arr(int* new_arr)
{
	arr = new_arr;
}

void ItemType::set_n(int new_n)
{
	n = new_n;
}

void ItemType::set_x(int new_x)
{
	x = new_x;
}

void ItemType::set_y(int new_y)
{
	y = new_y;
}

void ItemType::set_next(ItemType* new_next)
{
	next = new_next;
}

void ItemType::set_line(Line new_line)
{
	line = new_line;
}