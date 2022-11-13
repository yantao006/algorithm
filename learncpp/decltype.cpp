#include <iostream>

template<typename T> // 只声明不定义
class TD;            // TD （Type Display）的简称

int main() {
    const int a = 42;
    auto x = a;
    auto y = &a;
    TD<decltype(x)> xType;
    TD<decltype(y)> yType;
    return 0;
}
