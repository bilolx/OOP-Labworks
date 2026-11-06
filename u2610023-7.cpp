// u2610023 Karimov Bilol 06/11/26
// lab assignment 7
// descriptions of programs are writen inside main() function
#include<iostream>
using namespace std;

// 1
double parkingFee(int hours, double ratePerHour = 3000, double serviceFee = 1000);

// 2
int visitors = 0;
void registerGroup(int visitors) 
{
	::visitors += visitors;
	cout << "Group size (local): " << visitors << ", Total so far (global): " << ::visitors << endl;
}

// 3
double const PI = 3.14159;
int volume(int side) 
{
	return side * side * side;
}
int volume(int length, int width, int height) 
{
	return length * width * height;
}
double volume(double radius, double height)
{
	return PI * radius * radius * height;
}

// 4
template <typename T>
T maxOf(T a, T b)
{
	return (a > b) ? a : b;
}
template <typename T>
T minOf(T a, T b)
{
	return (a < b) ? a : b;
}

int main()
{	
	// 1 Task (program which calculates parking fee, one function is defined, but using default parameteres we can call it in 3 cases to gradually get arguments.)
	cout << "=== TASK 1: Parking Fee Calculator ===" << endl;
	int hours;
	double ratePerHour, serviceFee;

	cout << "Enter hours: ";
	cin >> hours;
	cout << "Parking fee: " << parkingFee(hours) << " sum" << endl;

	cout << "Enter rate: ";
	cin >> ratePerHour;
    cout << "Parking fee: " << parkingFee(hours, ratePerHour) << " sum" << endl;

	cout << "Enter fee: ";
	cin >> serviceFee;
	cout << "Parking fee: " << parkingFee(hours, ratePerHour, serviceFee) << " sum\n" << endl;
	

	// 2 Task (program which counts visitors in the museum, total visitors and visitors for each approach, global scope unary operator :: is used for global variable.)
	cout << "=== TASK 2: Visitors Counter ===" << endl;
	int visitors;
	for (int i = 1; i <= 3; i++) {
		cout << "Enter group size: ";
		cin >> visitors;
		registerGroup(visitors);
	}
	cout << "Total visitors: " << ::visitors << endl << endl;


	// 3 Task (program which shows menu-bar (switch + do while) to find volume of 3 different shapes (cube, parallelepiped and cylinder), functions overload are used.)
	cout << "=== TASK 3: Volume of Shapes ===" << endl;
	int shape, side, length, width, heightBox;
	double radius, heightCylinder;
	cout << "1. Cube\n"
			"2. Box\n"
			"3. Cylinder\n";
	do {
		cout << "Choose a shape: ";
		cin >> shape;
		switch (shape) {
		case 1: cout << "Enter side: "; cin >> side;
		cout << "Volume: " << volume(side) << endl; break;
		case 2: cout << "Enter length, width and height: "; cin >> length >> width >> heightBox;
		cout << "Volume: " << volume(length, width, heightBox) << endl; break;
		case 3: cout << "Enter radius and height: "; cin >> radius >> heightCylinder;
		cout << "Volume: " << volume(radius, heightCylinder) << endl; break;
		default: cout << "Error, choose correct shape!" << endl;
		}
	}  while (shape < 1 || shape > 3 );
	cout << endl;


	// 4 Task (program which inputs two any fundamental data types (integers, decimals and characters) and outputs maximum and minimum one, template typename T is used to unify all of them in one function.)
	cout << "=== TASK 4: Maximum and Minimum Numbers ===" << endl;
	int x, y;
	double m, n;
	char j, k;

	cout << "Enter two integers: ";
	cin >> x >> y;
	cout << "Max: " << maxOf(x, y) << ", Min: " << minOf(x, y) << endl;

	cout << "Enter two decimal numbers: ";
	cin >> m >> n;
	cout << "Max: " << maxOf(m, n) << ", Min: " << minOf(m, n) << endl;

	cout << "Enter two characters: ";
	cin >> j >> k;
	cout << "Max: " << maxOf(j, k) << ", Min: " << minOf(j, k) << endl;

	return 0;
}

// 1
double parkingFee(int hours, double ratePerHour, double serviceFee) 
{
	return hours * ratePerHour + serviceFee;
}

