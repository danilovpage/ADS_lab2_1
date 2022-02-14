#include <iostream>
#include "Polyline.h"
using namespace std;
using namespace Polylines;

int type_menu()
{
	int type = 0;
	std::cout << "Choose the type you will work with?" << endl;
	std::cout << "\n1.Work with INTPOINT2\n2.Work with DOUBLE POINT 3\n3.Work with COMPLEX<DOUBLE>\n4.Exit\n";
	std::cout << "Select an item:";
	std::cin >> type;
	while (true)
	{
		if (type >= 1 && type <= 4)
			return type;
		else
			return 0;
	}
}

int first_menu()
{
	std::system("cls");
	int choice = 0;
	std::cout << "Class Polyline" << endl;
	std::cout << "n (x1;y1) (x2;y2) ... (xn;yn)" << endl;
	std::cout << "**The first menu item is requred for further use of the program**";
	std::cout << "\n\n";
	std::cout << " 1.Create 2 polylines\n 2.Print polylines\n 3.Adding two polylines(concatenation)\n";
	std::cout << " 4.Adding a vertex\n 5.Polyline length\n 6.Compare two polylines\n 7.Exit" << endl;
	std::cout << "Select the menu item to continue: ";
	std::cin >> choice;
	while (true)
	{
		if (choice >= 1 && choice <= 7)
			return choice;
		else
			return 0;
	}
}

void polyline_int_p2()
{
	Polyline<IntPoint2> p1;
	Polyline<IntPoint2> p2;
	IntPoint2 vertex;

	int var = 0;
	int option = 0;
	bool again = true;
	while (again)
	{
		int choice = first_menu();
		try
		{
			switch (choice)
			{
			case 1:
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (x;y) via enter" << endl;
				std::cin >> p1;
				std::cout << "Polyline 2" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (x;y) via enter" << endl;
				std::cin >> p2;
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
			case 2:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
			case 3:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					std::cin.get();
					std::system("cls");
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "Result:" << endl;
				std::cout << p1 + p2;
				std::cin.get();
				std::system("cls");
				break;
			case 4:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "Which polyline will we work with?\nEnter the polyline number: ";
				std::cin >> var;
				std::cout << "Add a vertex to the beginning or end of a polyline?\n1.To the beginning\n2.To the end\nSelect the menu item to continue: ";
				std::cin >> option;
				std::cout << "Enter the coordinates of the vertex like this (x;y)" << endl;
				std::cin.get();
				std::cin >> vertex;
				if (var == 1)
				{
					if (option == 1) p1 < vertex;
					if (option == 2) p1 > vertex;
					std::cout << p1;
				}
				if (var == 2)
				{
					if (option == 1) p2 < vertex;
					if (option == 2) p2 > vertex;
					std::cout << p2;
				}
				std::cin.get();
				std::system("cls");
				break;
			case 5:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "What is the polyline to calculate the length?\nEnter the polyline number: ";
				std::cin >> var;
				if (var == 1)
				{
					std::cout << "\nPolyline " << var << "length: " << p1.Distance() << endl;
					std::cout << "Return type: " << typeid(p1.Distance()).name() << endl;
				}
				else
				{
					std::cout << "\nPolyline " << var << "length: " << p2.Distance() << endl;
					std::cout << "Return type: " << typeid(p2.Distance()).name() << endl;
				}
				std::cin.get();
				std::cin.get();
				std::system("cls");
				break;
			case 6:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				if ((p1 == p2) == true)
				{
					std::cout << "The polylines are equal!";
				}
				else
				{
					std::cout << "Polylines are unequal!";
				}
				break;
			case 7:
				again = false;
				break;
			}
		}
		catch (exception& e)
		{
			std::cout << e.what() << endl;
			std::cin.get();
			std::system("cls");
		}
		catch (const char* err)
		{
			std::cout << err;
			std::cin.get();
			std::system("cls");
		}
	}

}

void polyline_double_p3()
{
	Polyline<DoublePoint3> p1;
	Polyline<DoublePoint3> p2;
	DoublePoint3 vertex;

	int var = 0;
	int option = 0;
	bool again = true;
	while (again)
	{
		int choice = first_menu();
		try
		{
			switch (choice)
			{
			case 1:
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (x;y;z) via enter" << endl;
				std::cin >> p1;
				std::cout << "Polyline 2" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (x;y;z) via enter" << endl;
				std::cin >> p2;
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
			case 2:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
			case 3:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					std::cin.get();
					std::system("cls");
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "Result:" << endl;
				std::cout << p1 + p2;
				std::cin.get();
				std::system("cls");
				break;
			case 4:
				std::cin.get();
				std::system("cls");
				std::cout << p1;
				std::cout << p2;
				std::cout << "Which polyline will we work with?\nEnter the polyline number: ";
				std::cin >> var;
				std::cout << "Add a vertex to the beginning or end of a polyline?\n1.To the beginning\n2.To the end\nSelect the menu item to continue: ";
				std::cin >> option;
				std::cout << "Enter the coordinates of the vertex like this (x;y;z)" << endl;
				std::cin.get();
				std::cin >> vertex;
				if (var == 1)
				{
					if (option == 1) p1 < vertex;
					if (option == 2) p1 > vertex;
					std::cout << p1;
				}
				if (var == 2)
				{
					if (option == 1) p2 < vertex;
					if (option == 2) p2 > vertex;
					std::cout << p2;
				}
				std::cin.get();
				std::system("cls");
				break;
			case 5:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "What is the polyline to calculate the length?\nEnter the polyline number: ";
				std::cin >> var;
				if (var == 1)
				{
					std::cout << "\nPolyline " << var << "length: " << p1.Distance() << endl;
					std::cout << "Return type: " << typeid(p1.Distance()).name() << endl;
				}
				else
				{
					std::cout << "\nPolyline " << var << "length: " << p2.Distance() << endl;
					std::cout << "Return type: " << typeid(p2.Distance()).name() << endl;
				}
				std::cin.get();
				std::cin.get();
				std::system("cls");
				break;
			case 6:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					std::cin.get();
					std::system("cls");
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				if ((p1 == p2) == true)
				{
					std::cout << "The polylines are equal!";
				}
				else
				{
					std::cout << "Polylines are unequal!";
				}
				std::cin.get();
				std::cin.get();
				std::system("cls");
				break;
			case 7:
				again = false;
				break;
			}
		}
		catch (exception& e)
		{
			std::cout << e.what() << endl;
			std::cin.get();
			std::system("cls");
		}
		catch (const char* err)
		{
			std::cout << err;
			std::cin.get();
			std::system("cls");
		}
	}
}

void polyline_comp_d()
{
	Polyline<complex<double>> p1;
	Polyline<complex<double>> p2;
	complex<double> vertex;

	int var = 0;
	int option = 0;
	bool again = true;
	while (again)
	{
		int choice = first_menu();
		try
		{
			switch (choice)
			{
			case 1:
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (real part; image part) via enter" << endl;
				std::cin>> p1;
				std::cout << "Polyline 2" << endl;
				std::cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (real part; image part) via enter" << endl;
				std::cin >> p2;
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
				break;
			case 2:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cin.get();
				std::system("cls");
				break;
			case 3:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					std::cin.get();
					std::system("cls");
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "Result:" << endl;
				std::cout << p1 + p2;
				std::cin.get();
				std::system("cls");
				break;
			case 4:
				std::cin.get();
				std::system("cls");
				std::cout << p1;
				std::cout << p2;
				std::cout << "Which polyline will we work with?\nEnter the polyline number: ";
				std::cin >> var;
				std::cout << "Add a vertex to the beginning or end of a polyline?\n1.To the beginning\n2.To the end\nSelect the menu item to continue: ";
				std::cin >> option;
				std::cout << "Enter the coordinates of the vertex like this (real part; image part)" << endl;
				std::cin.get();
				std::cin >> vertex;
				if (var == 1)
				{
					if (option == 1) p1 < vertex;
					if (option == 2) p1 > vertex;
					std::cout << p1;
				}
				if (var == 2)
				{
					if (option == 1) p2 < vertex;
					if (option == 2) p2 > vertex;
					std::cout << p2;
				}
				std::cin.get();
				std::system("cls");
				break;
			case 5:
				std::cin.get();
				std::system("cls");
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				std::cout << "What is the polyline to calculate the length?\nEnter the polyline number: ";
				std::cin >> var;
				if (var == 1)
				{
					std::cout << "\nPolyline " << var << "length: " << p1.Distance() << endl;
					std::cout << "Return type: " << typeid(p1.Distance()).name() << endl;
				}
				else
				{
					std::cout << "\nPolyline " << var << "length: " << p2.Distance() << endl;
					std::cout << "Return type: " << typeid(p2.Distance()).name() << endl;
				}
				std::cin.get();
				std::cin.get();
				std::system("cls");
				break;
			case 6:
				std::cin.get();
				std::system("cls");
				if (p1.get_vertex() == 0 && p2.get_vertex() == 0)
				{
					std::cout << "Oops, you haven't created polylines. Select item 1 in the menu" << endl;
					std::cin.get();
					std::system("cls");
					break;
				}
				std::cout << "Polyline 1" << endl;
				std::cout << p1;
				std::cout << "Polyline 2" << endl;
				std::cout << p2;
				if ((p1 == p2) == true)
				{
					std::cout << "The polylines are equal!";
				}
				else
				{
					std::cout << "Polylines are unequal!";
				}
				std::cin.get();
				std::cin.get();
				std::system("cls");
				break;
			case 7:
				again = false;
				break;
			}
		}
		catch (exception& e)
		{
			std::cout << e.what() << endl;
			std::cin.get();
			std::system("cls");
		}
		catch (const char* err)
		{
			std::cout << err;
			std::cin.get();
			std::system("cls");
		}
	}
}

int main()
{
	int m = 0;
	bool again = true;
	while (again)
	{
		system("cls");
		m = type_menu();
		if (m == 1) polyline_int_p2();
		if (m == 2) polyline_double_p3();
		if (m == 3) polyline_comp_d();
		if (m == 4) again = false;
	}
	return 0;
}