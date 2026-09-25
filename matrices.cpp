#include <iostream>
#include <vector>

class Matrix {
public:
    size_t size;
    std::vector<double> data;

    // Constructor: initializes size and fills vector with zeros
    Matrix(size_t n) : size(n), data(n * n, 0.0) {}

    // Multi-dimensional operator[] (C++23) for non-const access
    double& operator[](size_t row, size_t col) {
        return data[row * size + col];
    }

    // Const version for read-only access
    const double& operator[](size_t row, size_t col) const {
        return data[row * size + col];
    }
};

// Matrix Multiplication Function: C = A * B
Matrix multiply(const Matrix& A, const Matrix& B) {
    size_t n = A.size;
    Matrix C(n); // Resulting matrix initialized to zeros

    // Standard O(N^3) matrix multiplication algorithm
    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 0; k < n; ++k) {
            for (size_t j = 0; j < n; ++j) {
                C[i, j] += A[i, k] * B[k, j];
            }
        }
    }
    return C;
}
Matrix add(const Matrix& A, const Matrix& B) {
    size_t n = A.size;
    Matrix C(n);

    // Elements are added position by position: C[i, j] = A[i, j] + B[i, j]
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            C[i, j] = A[i, j] + B[i, j];
        }
    }
    return C;
}

// Helper function to display a matrix
void printMatrix(const Matrix& m, const std::string& name) {
    std::cout << name << ":\n";
    for (size_t i = 0; i < m.size; ++i) {
        for (size_t j = 0; j < m.size; ++j) {
            std::cout << m[i, j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    size_t n = 2; // Create 2x2 matrices

    Matrix A(n);
    Matrix B(n);

    // Populate Matrix A
    A[0, 0] = 1.0;  A[0, 1] = 2.0;
    A[1, 0] = 3.0;  A[1, 1] = 4.0;

    // Populate Matrix B
    B[0, 0] = 5.0;  B[0, 1] = 6.0;
    B[1, 0] = 7.0;  B[1, 1] = 8.0;

    // Multiply matrices: C = A * B
    Matrix C = multiply(A, B);
    Matrix D = add(A, B);
    // Print all matrices
    printMatrix(A, "Matrix A");
    printMatrix(B, "Matrix B");
    printMatrix(C, "Result Matrix C (A * B)");
    printMatrix(D, "Result Matrix D (A + B)");

    return 0;
}