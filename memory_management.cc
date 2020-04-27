#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/time.h>
#include <memory>

void using_std_vector() {
    timeval start, end; 
    gettimeofday(&start, NULL);

    std::vector<int64_t> int64_vec;
    int32_t size = 300000000;
    int64_vec.reserve(size);
    for (int i = 0; i < size; i++) {
        int64_vec.push_back(i);
    }
    gettimeofday(&end, NULL);
    std::cout << "using_std_vector_ms push:" << 1000*(end.tv_sec - start.tv_sec) + 
        (end.tv_usec - start.tv_usec)/1000 << std::endl;

    timeval start2, end2; 
    gettimeofday(&start2, NULL);
    int64_t tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp = int64_vec[i];
    }
    gettimeofday(&end2, NULL);
    std::cout << "using_std_vector_ms get:" << 1000*(end2.tv_sec - start2.tv_sec) + 
        (end2.tv_usec - start2.tv_usec)/1000 << std::endl;
}

void using_array() {
    timeval start, end; 
    gettimeofday(&start, NULL);

    std::vector<int64_t> int64_vec;
    int32_t size = 300000000;
    int64_t* int64_vec_p = new int64_t[size];
    for (int i = 0; i < size; i++) {
        int64_vec_p[i] = i;
    }
    gettimeofday(&end, NULL);
    std::cout << "using_array_ms push:" << 1000*(end.tv_sec - start.tv_sec) + 
        (end.tv_usec - start.tv_usec)/1000 << std::endl;

    timeval start2, end2; 
    gettimeofday(&start2, NULL);
    int64_t tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp = int64_vec_p[i];
    }
    gettimeofday(&end2, NULL);
    std::cout << "using_array_ms get:" << 1000*(end2.tv_sec - start2.tv_sec) + 
        (end2.tv_usec - start2.tv_usec)/1000 << std::endl;
    delete []int64_vec_p;
}

void using_reserve() {
    timeval start, end; 
    gettimeofday(&start, NULL);

    std::vector<int64_t> int64_vec;
    int32_t size = 1000000;
    int64_vec.reserve(size); // using reserve
    for (int i = 0; i < size; i++) {
        int64_vec.push_back(i);
    }

    gettimeofday(&end, NULL);
    std::cout << "using_reserve_ms:" << 1000*(end.tv_sec - start.tv_sec) + 
        (end.tv_usec - start.tv_usec)/1000 << std::endl;
}

void no_using_reserve() {
    timeval start, end; 
    gettimeofday(&start, NULL);

    std::vector<int64_t> int64_vec;
    int32_t size = 1000000;
    for (int i = 0; i < size; i++) {
        int64_vec.push_back(i);
    }

    gettimeofday(&end, NULL);
    std::cout << "no_using_reserve_ms:" << 1000*(end.tv_sec - start.tv_sec) +
        (end.tv_usec - start.tv_usec)/1000 << std::endl;
}

void memory_leak_1() {
    // p is stack memory, *p is heap memory
    int32_t* p = new int32_t[5];
    for (int i = 0; i < 5; i++) {
        *(p + i) = i * 2;
    }
    delete p; // error!! should be delete[] p;
}

void memory_leak_2() {
    int32_t* p = new int32_t();
}

void using_shared_ptr() {
    std::shared_ptr<int32_t> p = std::make_shared<int32_t>();
    *p = 2;
    std::cout << "p value is:" << *p << std::endl;
}

void stack_address() {
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    int32_t arr[3] = {0};
    for(int i = 0; i < 3; i++) {
        arr[i] = 0;
        std::cout << "the address of arr[" << i << "] is:"
                  << &arr[i] << std::endl;
    }
    std::cout << "the address of a is:" << &a << std::endl;
    std::cout << "the address of b is:" << &b << std::endl;
    std::cout << "the address of c is:" << &c << std::endl;
}

void heap_address() {
    int* p1 = new int();
    int* p2 = new int();
    std::cout << "the address of p1 is:" << p1 << std::endl;
    std::cout << "the address of p2 is:" << p2 << std::endl;
}

void memory_overread() {
    int i = 0;
    int arr[3] = {0};
    for(; i <= 3; i++) {
        arr[i] = 0;
        std::cout << "hello, world" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    //std::cout << "hello, world" << std::endl;
    using_std_vector();
    using_array();
    //using_reserve();
    //no_using_reserve();
    //memory_leak_1();
    //memory_leak_2();
    //using_shared_ptr();
    //stack_address();
    //heap_address();
    //memory_overread();
    return 0;
}
