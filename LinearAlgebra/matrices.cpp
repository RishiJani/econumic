#include <vector>
#include <iostream>

class Matrix {
public:
    size_t size;
    std::vector<double> data; // Contiguous block in memory

    Matrix(size_t n) : size(n), data(n * n, 0.0) {}

    // Inline 2D-to-1D index mapping: row-major order
    inline double& operator()(size_t row, size_t col) {
        return data[row * size + col];
    }

    inline const double& operator()(size_t row, size_t col) const {
        return data[row * size + col];
    }
};
