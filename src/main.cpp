//
//  main.cpp
//  delayEmbeddingMethods
//
//  Created by Seungkyo Jeong on 8/20/25.
//

#include <iostream>
#include <vector>

std::vector<std::vector<double>> delay_embed(std::vector<double>& seq, int dim, int tau) {
    std::vector<std::vector<double>> embedded;
    int N = seq.size() - (dim - 1)*tau;
     
    for (int i = 0; i < N; i++) {
        std::vector<double> vec;
        for (int j = 0; j < dim; j++) {
            vec.push_back(seq[i + j*tau]);
        }
        embedded.push_back(vec);
    }
    return embedded;
}

std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& X) {
    if (X.empty()) return {};   // handle empty case
    
    int rows = X.size();
    int cols = X[0].size();
    
    std::vector<std::vector<double>> XT(cols, std::vector<double>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            XT[j][i] = X[i][j];  // swap row/col
        }
    }
    
    return XT;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<double> nums{1, 2, 3, 4, 5, 6};
//    nums.push_back(0.83247);
//    for (double a : nums) {
//        std::cout << a << " ";
//    }
//    std::cout << "\n";
    std::vector<std::vector<double>> embnums = delay_embed(nums, 3, 1);
    std::cout << embnums.size() << "\n";
    
    for (int r = 0; r < embnums.size(); r++) {
        for (int c = 0; c < embnums[0].size(); c++) {
            std::cout << embnums[r][c] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    std::vector<std::vector<double>> embnumsT = transpose(embnums);
    for (int k = 0; k < embnumsT.size(); k++) {
        for (int m = 0; m < embnumsT[0].size(); m++) {
            std::cout << embnumsT[k][m] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    return 0;
}
