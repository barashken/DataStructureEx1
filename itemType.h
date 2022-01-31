#ifndef ITEMTYPE_H
#define ITEMTYPE_H

//enum line
enum class Line
{
	START = 1,
	AFTER_FIRST,
	AFTER_SECOND
};


class ItemType
{
private:
	int* arr;
	int n;
	int x;
	int y;
	Line line;
	ItemType* next;

public:
	//Ctor
	ItemType(int* _arr = nullptr, int _n = 0, int _x = 0, int _y = 0, Line _line = Line::START, ItemType* _next = nullptr)
		: arr(_arr), n(_n), x(_x), y(_y), line(_line), next(_next) {};

	//Copy Ctor
	ItemType(const ItemType& newItemType);
	
	//Getters
	int* get_arr();
	int get_n();
	int get_x();
	int get_y();
	Line getLine();
	ItemType* getNext();

	//Setters
	void set_arr(int* new_arr);
	void set_n(int new_n);
	void set_x(int new_x);
	void set_y(int new_y);
	void set_line(Line _line);
	void set_next(ItemType* _next);


};

#endif // ITEMTYPE.H

