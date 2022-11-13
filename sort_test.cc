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

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Merge(std::vector<int32_t>& vec, int begin, int mid, int end) {
    std::vector<int32_t> tmp;
    int i = begin;
    int j = mid+1;
    while (i <= mid && j <= end) { // 这种情况下用while循环比用for循环思路要好很多
        if (vec[i] <= vec[j]) {
            tmp.push_back(vec[i++]);
        } else {
            tmp.push_back(vec[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(vec[i++]);
    }
    while (j <= end) {
        tmp.push_back(vec[j++]);
    }
    for (int k = 0; k < tmp.size(); k++) {
        vec[begin++] = tmp[k];
    }
}

void MergeSortCore(std::vector<int32_t>& vec, int begin, int end) {
    if (begin >= end) { return; }
    int mid = begin + (end - begin) / 2;
    MergeSortCore(vec, begin, mid);
    MergeSortCore(vec, mid+1, end);
    Merge(vec, begin, mid, end);
}

void MergeSort(std::vector<int32_t> vec) {
    timeval s,e;
    gettimeofday(&s, NULL);
    MergeSortCore(vec, 0, vec.size() -1);
    gettimeofday(&e, NULL);
    std::cout << "merge sort cost:" << (e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000 << std::endl;
    //print(vec);
}

int Partition(std::vector<int32_t>& vec, int begin, int end) {
    int pivot = end; // 每次选区间的最后一个元素作为分区点，有优化空间
    int i = begin;
    for (int j = begin; j < end; j++) {
        if (vec[j] < vec[pivot]) {
            swap(vec[j], vec[i]);
            i++;
        }
    }
    swap(vec[i], vec[pivot]);
    return i;
}

void QuickSortCore(std::vector<int32_t>& vec, int begin, int end) {
    if (begin >= end) { return; }
    int pivot = Partition(vec, begin, end);
    QuickSortCore(vec, begin, pivot - 1);
    QuickSortCore(vec, pivot + 1, end);
}

void QuickSort(std::vector<int32_t> vec) {
    timeval s,e;
    gettimeofday(&s, NULL);
    QuickSortCore(vec, 0, vec.size() - 1);
    gettimeofday(&e, NULL);
    std::cout << "quick sort cost:" << (e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000 << std::endl;
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
    //std::vector<int32_t> input = {3, 2, 8, 10, 6, 5, 9};
    //std::vector<int32_t> input = {3, 2};
    std::vector<int32_t> input;
    for (int i = 0; i < 10; i++) {
        input.push_back(rand()%10);
    }
    print(input);

    //BubbleSort(input);
    //InsertSort(input);
    //SelectionSort(input);
    //MergeSort(input);
    QuickSort(input);
    return 0;
}

/*
 * vec.size() == 10000
 * bubble sort cost:1615
 * insert sort cost:352
 * selection sort cost:656
 * merge sort cost:27
 * quick sort cost:5
 */

// compile command: g++ -lstdc++ -std=c++11 sort_test.cc -o test -lm
