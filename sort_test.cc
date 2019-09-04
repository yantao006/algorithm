#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/time.h>

void print(std::vector<int32_t>& vec) {
    std::string aaa;
    for (auto& it : vec) {
        aaa.append(std::to_string(it)).append("|");
    }
    std::cout << aaa << std::endl;
}

void BubbleSort(std::vector<int32_t> vec) {
    timeval s,e;
    gettimeofday(&s, NULL);
    if (vec.size() <= 1) { return; }
    for (int i = 0; i < vec.size(); i++) {
        bool flag = false;
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int32_t tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
                flag = true;
            }
        }
        if (flag == false) { break; }
    }
    gettimeofday(&e, NULL);
    std::cout << "bubble sort cost:" << (e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000 << std::endl;
    //print(vec);
}

void InsertSort(std::vector<int32_t> vec) {
    timeval s,e;
    gettimeofday(&s, NULL);
    if (vec.size() <= 1) { return; }
    for (int i = 1; i < vec.size(); i++) {
        int32_t value = vec[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (vec[j] > value) {
                vec[j+1] = vec[j];
            } else {
                break;
            }
        }
        vec[j+1] = value;
    }
    gettimeofday(&e, NULL);
    std::cout << "insert sort cost:" << (e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000 << std::endl;
    //print(vec);
}

void SelectionSort(std::vector<int32_t> vec) {
    timeval s,e;
    gettimeofday(&s, NULL);
    if (vec.size() <= 1) { return; }
    for (int i = 0; i < vec.size(); i++) {
        int min_index = i;
        for (int j = i; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        int tmp = vec[min_index];
        vec[min_index] = vec[i];
        vec[i] = tmp;
    }
    gettimeofday(&e, NULL);
    std::cout << "selection sort cost:" << (e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000 << std::endl;
    //print(vec);
}

// 测试
int main(int argc, char* argv[]) {
    std::vector<int32_t> input = {3, 2, 8, 6, 5, 9};
    for (int i = 0; i < 10000; i++) {
        input.push_back(rand()%100000);
    }
    //print(input);

    BubbleSort(input);
    InsertSort(input);
    SelectionSort(input);
    //print(input);
    return 0;
}

/*
 * vec.size() == 10000
 * bubble sort cost:107499
 * insert sort cost:26993
 * selection sort cost:48511
 */

// compile command: g++ -lstdc++ -std=c++11 sort_test.cc -o test -lm
