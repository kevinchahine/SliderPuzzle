#include "MatrixDriver.h"

using namespace std;

int MatrixDriver::test()
{
	cout << "Full RValue\n";
	Matrix<uint16_t> m(4, 5, 12);
	
	m.print();

	cout << "Mutation\n";

	m.at(2, 4) = 123;
	m.at(0, 0) = 333;
	m.at(3, 4) = 99;

	m.print();

	cout << "def\n";
	Matrix<uint16_t> def;
	def.print();

	cout << "full LValue\n";
	uint16_t initializer = 8;
	Matrix<uint16_t> fullLValue(6, 1, initializer);
	fullLValue.print();

	cout << "copy\n";
	Matrix<uint16_t> copyMat(fullLValue);
	copyMat.print();

	cout << "move\n";
	Matrix<uint16_t> move(Matrix<uint16_t>(2, 2, initializer));
	move.print();
	
	return 0;
}

int MatrixDriver::testAssign()
{
	Matrix<int> m(3, 4);

	Matrix<int> n;

	cout << "m:\n";
	m.print();

	cout << "n:\n";
	n.print();

	cout << "===== n.assign(m) =====\n";
	n.assign(m);

	cout << "m:\n";
	m.print();

	cout << "n:\n";
	n.print();

	return 0;
}
