
#include <iostream>
#include <vector>

void print(std::vector<int32_t>& vec) {
    std::string aaa;
    for (auto& it : vec) {
        aaa.append(std::to_string(it)).append("|");
    }
    std::cout << aaa << std::endl;
}

// 二分查找算法
// 默认数据按**从小到大**排列
int32_t binary_search(std::vector<int32_t>& vec, int32_t v) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) { // 注意1：low <= high，而非low < high
        int mid = low + ((high - low) >> 1); // 注意2：不要写mid = (low + high) / 2，防止数值超限
        if (vec[mid] == v) { return mid; }
        if (vec[mid] > v) {
            high = mid - 1; // 注意3：high 和 low的更新，一定要变更，不要写成high=mid或low=mid，容易死循环
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// 以下是二分查找的变形问题
// 查找第一个值等于给定值的元素
int32_t bs_first_equal(std::vector<int32_t>& vec, int32_t v) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (vec[mid] > v) {
            high = mid - 1;
        } else if (vec[mid] < v) {
            low = mid + 1;
        } else {
            if (mid == 0 || vec[mid - 1] != v) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// 查找最后一个值等于给定值的元素
int32_t bs_last_equal(std::vector<int32_t>& vec, int32_t v) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (vec[mid] > v) {
            high = mid - 1;
        } else if (vec[mid] < v) {
            low = mid + 1;
        } else {
            if (mid == vec.size() - 1 || vec[mid + 1] != v) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

// 查找第一个值大于等于给定值的元素
int32_t bs_first_ge(std::vector<int32_t>& vec, int32_t v) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (vec[mid] < v) {
            low = mid + 1;
        } else if (vec[mid] >= v && mid != 0 && vec[mid - 1] < v) {
            return mid;
        } else if (vec[mid] >= v && mid == 0) {
            return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
// 查找最后一个值小于等于给定值的元素
int32_t bs_last_le(std::vector<int32_t>& vec, int32_t v) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (vec[mid] > v) {
            high = mid - 1;
        } else if (vec[mid] <= v && mid != vec.size() -1 && vec[mid + 1] > v) {
            return mid;
        } else if (vec[mid] <= v && mid == vec.size() -1) {
            return mid;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    std::vector<int32_t> input = {3,4,4,5,5,7,8,9};
    print(input);
    int v = 1;

    //int pos = binary_search(input, v);
    //int pos = bs_first_equal(input, v);
    //int pos = bs_last_equal(input, v);
    int pos = bs_first_ge(input, v);
    //int pos = bs_last_le(input, v);

    if (pos == -1) {
        std::cout << "fail to find value:" << v << " in vec" << std::endl;
    } else {
        std::cout << "succ to find value:" << v << " in vec, pos:" << pos << std::endl;
    }
    return 0;
}
