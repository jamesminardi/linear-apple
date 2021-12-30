#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
/*

Access an entry of array:
m(1,3) = matrix[1 + 3 * width]

*/
/*
 * Traversal (row major): m(row + (col * m_cols))
 *
 * Returning a vector from matrix:
 *	-	Make an array of pointers with each pointer pointing to the
 *		address of each matrix entry using some algorithm
 *	-	Wrap it in a stack-allocated vector class like matrix. (for destructor)
 *	-	This way, the values can be modified and affect the original matrix
 *	-	Also makes row operations easier? Not sure about that yet
 */

class Matrix
{
public:
	int m_rows;
	int m_cols;

	int* m_core;


	/// Destructor
	~Matrix();

	/// Default constructor: 0x0 matrix with null core
	Matrix();

	/// Construct a square matrix
	explicit Matrix(int size);

	/// Construct rows x cols matrix
	Matrix(int rows, int cols);


	/// Copy constructor (Copies the data)
	Matrix(const Matrix& other);

	/// Copy assignment
	Matrix& operator=(const Matrix& other);

	// Copies source to target using target's members
	static void CopyCore(const Matrix& target, const Matrix& source);


	/// move constructor (Reassigns the memory without copying the data)
	Matrix(Matrix&& other) noexcept;

	/// Move assignment (Move constructor but for assigning existing vars)
	Matrix& operator=(Matrix&& other) noexcept;


	/// Zero the matrix
	void Reset() const;

	/// Resize the matrix
	void Resize(const int rows, const int cols);
	void Resize(const int size);

	/*
	 * Access an entry in the matrix
	 *
	 *		1, 2, 3
	 *		4, 5, 6		Access 6 using m(1, 2);
	 *		7, 8, 9		
	 */
	int& operator()(const int& row, const int& col) const;

	Matrix& operator+=(const Matrix& other);
};

/// Returns copy of result of (lhs + rhs)
///	lhs is updated after (lhs += rhs) and returned as a copy
inline Matrix operator+(Matrix lhs, const Matrix& rhs)
{
	lhs += rhs;
	return lhs;
}
