#include "Matrix.h"

/// Destructor
Matrix::~Matrix()
{
	delete m_core;
	std::cout << "Deleted matrix" << std::endl;
}

Matrix::Matrix() : Matrix(0, 0) {}

Matrix::Matrix(const int size) : Matrix::Matrix(size, size) {}

Matrix::Matrix(const int rows, const int cols) : m_rows(rows), m_cols(cols)
{
	if (rows || cols)
	{
		m_core = new int[rows * cols];
	}
	else
	{
		m_core = nullptr; // Matrix is 0 x 0
	}
	std::cout << "Created matrix" << std::endl;

	Reset();
}


// Copy constructor
Matrix::Matrix(const Matrix& other) : Matrix(other.m_rows, other.m_cols)
{
	if (m_core != nullptr)
	{
		CopyCore(*this, other);
	}
	std::cout << "Copy constructor" << std::endl;
}

/// Copy assignment
Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) // no-op for self assignment
	{
		this->Resize(other.m_rows, other.m_cols);

		CopyCore(*this, other);
	}
	std::cout << "Copy assignment" << std::endl;
	return *this;
}

void Matrix::CopyCore(const Matrix& target, const Matrix& source)
{
	for (int row = 0; row < target.m_rows; row++)
	{
		for (int col = 0; col < target.m_cols; col++)
		{
			target(row, col) = source(row, col); // 'this' returns pointer
		}
	}
}


/// Move constructor
Matrix::Matrix(Matrix&& other) noexcept : m_rows(other.m_rows),
                                          m_cols(other.m_cols),
                                          m_core(other.m_core)
{
	other.m_rows = 0;
	other.m_cols = 0;
	other.m_core = nullptr;
	std::cout << "Move constructor" << std::endl;
}

/// Move assignment
Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	if (this != &other) // no-op for self assignment
	{
		delete m_core;

		m_rows = other.m_rows;
		m_cols = other.m_cols;
		m_core = other.m_core;

		other.m_rows = 0;
		other.m_cols = 0;
		other.m_core = nullptr;
	}
	std::cout << "Move assignment" << std::endl;
	return *this;
}


/// Reset to 0 matrix
void Matrix::Reset() const
{
	if (m_core != nullptr)
	{
		std::memset(m_core, 0, sizeof(int) * m_rows * m_cols); // From cstring lib?
	}
	std::cout << "Reset matrix" << std::endl;
	//for (int entry = 0; entry < m_rows * m_cols; entry++)
	//{
	//	m_core[entry] = 0;
	//}
}

void Matrix::Resize(const int rows, const int cols)
{
	m_rows = rows;
	m_cols = cols;

	delete m_core;
	m_core = new int[m_rows * m_cols]; // Implicit widening
	std::cout << "Resized matrix." << std::endl;
}

void Matrix::Resize(const int size)
{
	Resize(size, size);
}


int& Matrix::operator()(const int& row, const int& col) const
{
	return m_core[col + (row * m_cols)];
}

//int Matrix::operator()(int row, int col) const { // const is confusing
//	return matrix[col + (row * m_cols)];
//}

Matrix& Matrix::operator+=(const Matrix& other)
{
	assert(this->m_cols == other.m_cols && this->m_rows == other.m_rows);

	for (int row = 0; row < m_rows; row++) {
		for (int col = 0; col < m_cols; col++) {
			(*this)(row, col) = (*this)(row, col) + other(row, col); // 'this' returns pointer
		}
	}

	return *this;

}
