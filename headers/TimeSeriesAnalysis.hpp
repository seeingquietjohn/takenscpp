//
//  TimeSeriesAnalysis.hpp
//  delayEmbeddingMethods
//
//  Created by Seungkyo Jeong on 8/26/25.
//

#ifndef TimeSeriesAnalysis_hpp
#define TimeSeriesAnalysis_hpp

#include <stdio.h>
#include <vector>

class TimeSeries {
private:
    std::vector<double> X;
public:
    
    double getEntropy;
    double getDimension;
    double getMutualInf;
};

#endif /* TimeSeriesAnalysis_hpp */
