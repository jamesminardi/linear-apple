// Uncomment to remove asserts
// #define NDEBUG


#include <iostream>
#include "Matrix.h"

void Function()
{
	Matrix m1(3, 2);
	//m1.Reset();
	int count = 0;
	for (int i = 0; i < m1.m_rows; i++)
	{
		for (int j = 0; j < m1.m_cols; j++)
		{
			m1(i, j) = count;
			count++;
		}
	}
	std::cout << "A:" << std::endl;
	std::cout << m1(0, 0) << " " << m1(0, 1) << std::endl;
	std::cout << m1(1, 0) << " " << m1(1, 1) << std::endl;
	std::cout << m1(2, 0) << " " << m1(2, 1) << std::endl;
	std::cout << std::endl;

	const Matrix m2(3, 2);
	count = 1;
	for (int i = 0; i < m2.m_rows; i++)
	{
		for (int j = 0; j < m2.m_cols; j++)
		{
			m2(i, j) = count;
			count++;
		}
	}

	std::cout << std::endl;
	std::cout << "B:" << std::endl;
	std::cout << m2(0, 0) << " " << m2(0, 1) << std::endl;
	std::cout << m2(1, 0) << " " << m2(1, 1) << std::endl;
	std::cout << m2(2, 0) << " " << m2(2, 1) << std::endl;

	std::cout << std::endl;
	m1 += m2;
	std::cout << "A+B:" << std::endl;
	std::cout << m1(0, 0) << " " << m1(0, 1) << std::endl;
	std::cout << m1(1, 0) << " " << m1(1, 1) << std::endl;
	std::cout << m1(2, 0) << " " << m1(2, 1) << std::endl;
	std::cout << std::endl;
}

int main()
{
	Function();
	std::cin.get();
}
