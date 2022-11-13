#include <iostream>

template<typename T> // 只声明不定义
class TD;            // TD （Type Display）的简称

int main() {
    const int a = 42;
    auto x = a;
    auto y = &a;
    // 编译期输出
    TD<decltype(x)> xType;
    TD<decltype(y)> yType;

    // 运行期输出
    // 不可靠，且不够直观
    // std::cout << typeid(x).name() << std::endl;
    // std::cout << typeid(y).name() << std::endl;
    return 0;
}
