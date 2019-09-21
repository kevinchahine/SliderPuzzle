#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

template<typename T, size_t N_ROWS, size_t N_COLS>
class Matrix : public std::array<std::array<T, N_COLS>, N_ROWS>
{
public:
	Matrix();
	Matrix(const T & initializer);
	Matrix(const T && initializer = T());
	Matrix(const Matrix & matrix);
	Matrix(const Matrix && matrix);
	~Matrix();

	T & at(size_t row, size_t col);
	const T & at(size_t row, size_t col) const;

	size_t getNRows() const;
	size_t getNCols() const;
	size_t getNElements() const;

	void print(std::ostream & os = std::cout) const;
};

// ================================= CONSTRUCTORS ========================

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::Matrix() :
	std::array<std::array<T, N_COLS>, N_ROWS>(T()) 
{}

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::Matrix(const T & initializer) :
	std::array<std::array<T, N_COLS>, N_ROWS>(initializer) 
{}

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::Matrix(const T && initializer) :
	std::array<std::array<T, N_COLS>, N_ROWS>(initializer) 
{}

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::Matrix(const Matrix & matrix) :
	std::array<std::array<T, N_COLS>, N_ROWS>(matrix) 
{}

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::Matrix(const Matrix && matrix) :
	std::array<std::array<T, N_COLS>, N_ROWS>(matrix)
{}

template<typename T, size_t N_ROWS, size_t N_COLS>
Matrix<T, N_ROWS, N_COLS>::~Matrix()
{}

// ============================ METHODS =======================

template<typename T, size_t N_ROWS, size_t N_COLS>
inline T & Matrix<T, N_ROWS, N_COLS>::at(size_t row, size_t col)
{
	return std::array<std::array<T, N_COLS>, N_ROWS>::at(row).at(col);
}

template<typename T, size_t N_ROWS, size_t N_COLS>
inline const T & Matrix<T, N_ROWS, N_COLS>::at(size_t row, size_t col) const
{
	return std::array<std::array<T, N_COLS>, N_ROWS>::at(row).at(col);
}

template<typename T, size_t N_ROWS, size_t N_COLS>
inline size_t Matrix<T, N_ROWS, N_COLS>::getNRows() const
{
	return N_ROWS;
}

template<typename T, size_t N_ROWS, size_t N_COLS>
inline size_t Matrix<T, N_ROWS, N_COLS>::getNCols() const
{
	return N_COLS;
}

template<typename T, size_t N_ROWS, size_t N_COLS>
inline size_t Matrix<T, N_ROWS, N_COLS>::getNElements() const
{
	return N_ROWS * N_COLS;
}

template<typename T, size_t N_ROWS, size_t N_COLS>
void Matrix<T, N_ROWS, N_COLS>::print(std::ostream & os) const
{
	for (size_t r = 0; r < N_ROWS; r++) {
		for (size_t c = 0; c < N_COLS; c++) {
			os << std::setw(6) << at(r, c);
		}
		os << '\n';
	}
	os << '\n';
}
