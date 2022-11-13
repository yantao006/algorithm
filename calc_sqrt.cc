#include <iostream>
#include <cmath>

double calc_sqrt(int32_t input) {
    double low = 0;
    double up = input;
    double mid = low + (up - low) / 2; //0.00000001
    while (fabs(mid * mid - input) > 1e-8) {
        if (mid * mid < input) {
            low = mid;
            // low == 2.25
        } else {
            up = mid;
        }
        // low == 2.25, up == 4.5
        mid = (up + low) / 2;
        std::cout << "mid的中间状态:" << mid << std::endl;
    }
    return mid;
}

int main(int argc, char* argv[]) {
    int32_t input = 44;
    double output = calc_sqrt(input);
    std::cout << input << "的平方根是:" << output << std::endl;
    return 0;
}

// g++ -lstdc++ -std=c++11 calc_sqrt.cc -o calc_sqrt
