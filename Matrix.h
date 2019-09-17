#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

template<typename T>
class Matrix : public std::vector<T>
{
public:
	Matrix();
	Matrix(size_t nRows, size_t nCols, const T & initializer);
	Matrix(size_t nRows, size_t nCols, const T && initializer = T());
	Matrix(const Matrix & matrix);
	Matrix(const Matrix && matrix);
	~Matrix();

	T & at(size_t row, size_t col);
	const T & at(size_t row, size_t col) const;

	size_t getNRows() const;
	size_t getNCols() const;

	void print(std::ostream & os = std::cout) const;

protected:
public://remove
	size_t map(size_t row, size_t col) const;
	//size_t colCoord(size_t index) const;
	//size_t rowCoord(size_t index) const;

protected:
	size_t nRows;
	size_t nCols;
};

// ================================= CONSTRUCTORS ========================

template<typename T>
Matrix<T>::Matrix() :
	std::vector<T>(1, T()),
	nRows(1),
	nCols(1) {}

template<typename T>
Matrix<T>::Matrix(size_t nRows, size_t nCols, const T & initializer) :
	std::vector<T>(nRows * nCols, initializer),
	nRows(nRows),
	nCols(nCols) {}

template<typename T>
Matrix<T>::Matrix(size_t nRows, size_t nCols, const T && initializer) :
	std::vector<T>(nRows * nCols, initializer),
	nRows(nRows),
	nCols(nCols) {}

template<typename T>
Matrix<T>::Matrix(const Matrix & matrix) :
	std::vector<T>(matrix),
	nRows(matrix.nRows),
	nCols(matrix.nCols) {}

template<typename T>
inline Matrix<T>::Matrix(const Matrix && matrix) :
	std::vector<T>(std::move(matrix)),
	nRows(matrix.nRows),
	nCols(matrix.nCols) {}

template<typename T>
Matrix<T>::~Matrix() {}

// ============================ METHODS =======================

template<typename T>
T & Matrix<T>::at(size_t row, size_t col)
{
	if (row > nRows)
	{
#if _DEBUG
		std::cerr << __FILE__
			<< " function " << __FILE__
			<< " row is out of bounds\n";
#endif
		return (*this)[0];
	}
	if (col > nCols)
	{
#if _DEBUG
		std::cerr << __FILE__
			<< " function " << __FILE__
			<< " col is out of bounds\n";
#endif
		return(*this)[0];
	}
	T temp = static_cast<std::vector<T>>(*this).at(map(row, col));

	return std::vector<T>::at(map(row, col));
}

template<typename T>
const T & Matrix<T>::at(size_t row, size_t col) const
{
	if (row > nRows)
	{
#if _DEBUG
		std::cerr << __FILE__
			<< " function " << __func__
			<< " row is out of bounds\n";
#endif
		return (*this)[0];
	}
	if (col > nCols)
	{
#if _DEBUG
		std::cerr << __FILE__
			<< " function " << __func__
			<< " col is out of bounds\n";
#endif
		return(*this)[0];
	}

	return std::vector<T>::at(map(row, col));
}

template<typename T>
inline size_t Matrix<T>::getNRows() const
{
	return this->nRows;
}

template<typename T>
inline size_t Matrix<T>::getNCols() const
{
	return this->nCols;
}

template<typename T>
void Matrix<T>::print(std::ostream & os) const
{
	for (size_t r = 0; r < nRows; r++) {
		for (size_t c = 0; c < nCols; c++) {
			os << std::setw(6) << at(r, c);
		}
		os << '\n';
	}
	os << '\n';
}

template<typename T>
inline size_t Matrix<T>::map(size_t row, size_t col) const
{
	return col + row * nCols;
}

template<typename T>
inline size_t Matrix<T>::colCoord(size_t index) const
{
	return index % nCols;
}

template<typename T>
inline size_t Matrix<T>::rowCoord(size_t index) const
{
	return index % nRows;
}



