#include "CoordinateDriver.h"

#include <iostream>

using namespace std;

void CoordinateDriver::testAssignmentOperator()
{
	cout << "===== " << __func__ << " =====\n";

	cout << "\tcopy assignment\t";

	Coordinate c(3, 4);

	Coordinate d = c;

	cout << c << " should equal " << d << '\n';

	cout << "\tmove assignment\t";

	Coordinate e = Coordinate(5, 6);

	cout << e << " should equal " << Coordinate(5, 6) << '\n';
}
