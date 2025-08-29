//
//  EmbeddingFunctions.cpp
//  delayEmbeddingMethods
//
//  Created by Seungkyo Jeong on 8/21/25.
// delay embedding and data transformation (for dimension reduction) applied time series (like PCA)

#include "EmbeddingFunctions.hpp"
#include <vector>
#include <Eigen/Dense>

// Delay embedding
std::vector<std::vector<double>> delay_embed(std::vector<double>& seq, int dim, int tau) {
    std::vector<std::vector<double>> embedded;
    int N = seq.size() - (dim - 1) * tau;
     
    for (int i = 0; i < N; i++) {
        std::vector<double> vec;
        for (int j = 0; j < dim; j++) {
            vec.push_back(seq[i + j*tau]);
        }
        embedded.push_back(vec);
    }
    return embedded;
}

// Principal component analysis
//std::vector<std::vector<double>> PCA(std::vector<std::vector<double>>& X, int k) {
//    
//    return
//}
