# linear-apple
First c++ project: Simple linear algebra library


## Matrices
- Wraps a one dimensional `char *` array
- 0 indexed, row-major traversal using `()` operator
```
Matrix A(3);                        // A 3x3, 0 matrix

A(1, 2) = 8;                        // Sets entry at row 1, column 2 equal to 8

std::cout << A(1,2) << std::endl    // Outputs 8
```
- Copy and Move constructors & assignments
- Supports addition of similar sized matrices using `+` or `+=`

### Features to add:
- Matrix Arithmetic operators: `-` `*` `/` `%` and `-=` `*=` `/=` `%=`
- Matrix Boolean algebra: `==` `!=`
- Row and column operations
- Get modifiable column and row vectors from a matrix
- Vector wrapper for 0xM or Nx0 matrices
