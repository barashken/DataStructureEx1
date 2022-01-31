using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <iomanip>

#include "stack.h"
#include "itemType.h"


//Functions declaration
void itFunc(int* arr, int n, int x);
void recFunc(int* arr, int n, int x, int y);
void stackFunc(int* arr, int n, int x, int y);
void itMeasure(int* arr, int n, int x);
void recMeasure(int* arr, int n, int x);
void stMeasure(int* arr, int n, int x);

//#define MAXSIZE 7000


int main(int argc, char* argv[])
{
	int n, x;

	cin >> n;
	if (n <= 0)
	{
		cout << "wrong input";
		exit(1);
	}
	int* arr = new int[n];


	for (int i = 0; i < n; i++)
	{
		if (cin.eof())
		{
			cout << "wrong input";
			exit(1);
		}

		cin >> arr[i];
		if (arr[i] <= 0)
		{
			cout << "wrong input";
			exit(1);
		}
	}

	if (cin.eof())
	{
		cout << "wrong input";
		exit(1);
	}

	cin >> x;
	if (x <= 0)
	{
		cout << "wrong input";
		exit(1);
	}

	if (!cin.eof())
	{
		cout << "wrong input";
		exit(1);
	}



	itMeasure(arr, n, x);
	recMeasure(arr, n, x);
	stMeasure(arr, n, x);


	delete[] arr;
	return 0;
}



//Prints to file the run time of the iterative function
void itMeasure(int* arr, int n, int x)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	//Iterative function
	cout << "Iterative:" << endl;
	itFunc(arr, n, x);
	cout << endl;

	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt",ios::out|ios::trunc); // The name of the file
	myfile << "Time taken by function <itFunc> is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

//Prints to file the run time of the recursive function
void recMeasure(int* arr, int n, int x)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	//Recursive function
	cout << "Recursive:" << endl;
	recFunc(arr, n, x, 0);
	cout << endl;

	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::out | ios::app); // The name of the file
	myfile << "Time taken by function <recFunc> is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

//Prints to file the run time of the recursion implemented using stack:
void stMeasure(int* arr, int n, int x)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	//Using stuck function
	cout << "Recursion implemented using stack:" << endl;
	stackFunc(arr, n, x, 0);
	cout << endl;

	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::out|ios::app); // The name of the file
	myfile << "Time taken by function <stFunc> is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}


//Iterative function
void itFunc(int* arr, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x == arr[i] + arr[j])
				cout << arr[i] << " " << arr[j]<<endl;
		}
	}
}

//Recursive function
void recFunc(int* arr, int n, int x, int y)
{
	if (n == 1 && y != 0)
	{
		if (x == arr[0] + y)
			cout << y << " " << arr[0] << endl;
		return;
	}
	if (n == 1 && y == 0)
		return;

	else //n!=1
	{
		if (y != 0)
		{
			if (x == arr[n-1] + y)
				cout << arr[n - 1] << " " << y << endl;
			recFunc(arr, n - 1, x, y);
		}
		else //y==0
		{
			recFunc(arr, n - 1, x, arr[n-1]);
			recFunc(arr, n - 1, x, 0);
		}
	}
}

// Recursion implemented using stack
void stackFunc(int* arr, int n, int x, int y)
{
	Stack S;
	ItemType curr(arr, n, x, y, Line::START, nullptr);
	ItemType next;

	S.Push(curr);

	while (!S.IsEmpty())
	{
		curr = S.Pop();
		if (curr.getLine() == Line::START)
		{
			if (curr.get_n() == 1 && curr.get_y() != 0)
			{
				if (curr.get_x() == curr.get_arr()[0] + curr.get_y())
					cout << curr.get_y() << " " << curr.get_arr()[0] << endl;

				continue;
			}
			else if (curr.get_n() == 1 && curr.get_y() == 0)
			{
				continue;
			}
			else //if (n!=1)
			{
				if (curr.get_y() != 0)
				{
					if (curr.get_x() == curr.get_arr()[curr.get_n() - 1] + curr.get_y())
						cout << curr.get_arr()[curr.get_n() - 1] << " " << curr.get_y() << endl;
				}
				curr.set_line(Line::AFTER_FIRST);
				S.Push(curr);

				next.set_arr(curr.get_arr());
				next.set_n(curr.get_n() - 1);
				next.set_x(curr.get_x());
				next.set_y(curr.get_y());
				next.set_line(Line::START);
				next.set_next(&curr);

				S.Push(next);

			}
		}
		else if (curr.getLine() == Line::AFTER_FIRST)
		{
			if(curr.get_y()==0)
			{
				curr.set_line(Line::AFTER_SECOND);
				S.Push(curr);

				next.set_arr(curr.get_arr());
				next.set_n(curr.get_n() - 1);
				next.set_x(curr.get_x());
				next.set_y(curr.get_arr()[curr.get_n() - 1]);
				next.set_line(Line::START);
				next.set_next(&curr);

				S.Push(next);
			}
		}
		else// if (curr.getLine() == Line::AFTER_SECOND)
		{
			continue;
			
		}
	}
}
