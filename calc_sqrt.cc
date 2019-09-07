
#include <iostream>
#include <cmath>

double calc_sqrt(int32_t input) {
    double low = 0;
    double up = input;
    double mid = low + (up - low) / 2;
    while (fabs(mid * mid - input) > 1e-8) {
        if (mid * mid < input) {
            low = mid;
        } else {
            up = mid;
        }
        mid = low + (up - low) / 2;
    }
    return mid;
}

int main(int argc, char* argv[]) {
    std::cout << "hello, world:" << calc_sqrt(10) << std::endl;
    return 0;
}

// g++ -lstdc++ -std=c++11 calc_sqrt.cc -o calc_sqrt
