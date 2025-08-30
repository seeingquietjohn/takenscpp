//
//  DelayEmbed.hpp
//  delayEmbeddingMethods
//
//  Created by Seungkyo Jeong on 8/28/25.
//

// delay embedding matrix structure and implementation

#ifndef DelayEmbed_hpp
#define DelayEmbed_hpp

#pragma once
#include <stdio.h>
#include <vector>
#include <cstddef>     // std::size_t
#include <type_traits> // std::is_floating_point_v
#include <stdexcept>   // std::invalid_argument
#include <limits>      // std::numeric_limits

namespace takens {

template <class T = double> // default double
class DelayMatrix {
    std::size_t rows = 0;
    std::size_t cols = 0;
    std::vector<T> data;
    
    DelayMatrix() = default; // default delay matrix is empty
    DelayMatrix(std::size_t r, std::size_t c) : rows(r), cols(c), data(r * c) {} // 1-D row-major
    
    // access elements in delay matrix
    // access elements (i, j)
    // allow modification
    T& operator()(std::size_t i, std::size_t j) {
        return data[i * cols + j];
    }
    // read-only
    const T& operator()(std::size_t i, std::size_t j) const {
        return data[i * cols + j];
    }
    
    // access row via delay vector (row) pointer
    T* dvec_ptr(std::size_t i) {
        return data.data() + i * cols;
    }
    const T* dvec_ptr(std::size_t i) const {
        return data.data() + i * cols;
    }
    
    std::size_t size() const {
        return data.size();
    }
};

template <class T = double>
DelayMatrix<T> delayEmbed(const std::vector<T>& seq, std::size_t dim, std::size_t delay) {
    if (dim == 0) throw std::invalid_argument("Dimension must be greater than 0!");
    if (delay == 0) throw std::invalid_argument("Delay must be greater than 0!");
    // we need at least (dim-1)*delay data points
    if (seq.size() <= (dim - 1) * delay) throw std::invalid_argument("Not enough data points!");
    
    // instantiate a delay matrix
    const std::size_t N = seq.size() - (dim - 1) * delay;
    DelayMatrix<T> X(N, dim);
    
    for (std::size_t i = 0; i < N; i++) {
        T* dvec = X.dvec_ptr(i);
        std::size_t idx = i;
        for (std::size_t j = 0; j < dim; j++) {
            dvec[i] = seq[idx];
            idx += delay;
        }
    }
    return X; 
}

}

#endif /* DelayEmbed_hpp */
