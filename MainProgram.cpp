#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

// ================================
// GROUP 1
// ================================
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// ================================
// GROUP 2
// ================================
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// ================================
// GROUP 3
// ================================
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    Pair(A first, B second)
        : first_(first), second_(second) {}

    A getFirst() const { return first_; }
    B getSecond() const { return second_; }

    void setFirst(A value) { first_ = value; }
    void setSecond(B value) { second_ = value; }

    void swapValues() {
        std::swap(first_, second_);
    }
};

// ================================
// GROUP 4
// ================================
template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    void add(const T& item) {
        items_.push_back(item);
    }

    int size() const {
        return static_cast<int>(items_.size());
    }

    T get(int index) const {
        if (index < 0 || index >= static_cast<int>(items_.size())) {
            throw std::out_of_range("Index out of range");
        }
        return items_[index];
    }

    T total() const {
        if (items_.empty()) return T();
        T sum = items_[0];
        for (size_t i = 1; i < items_.size(); i++) {
            sum = sum + items_[i];
        }
        return sum;
    }
};

// ================================
// GROUP 5
// ================================
template <typename T>
int describe(const T& value) {
    return 1;
}

// Full specialization for std::string
template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.size());
}

// ================================
// GROUP 6
// ================================
template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    FixedArray() {
        for (int i = 0; i < N; i++) {
            data_[i] = T();
        }
    }

    int capacity() const {
        return N;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }
        data_[index] = value;
    }

    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
};

// ================================
// MAIN
// ================================
int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";

    std::cout << "addValues(3, 4.5) = " << addValues(3, 4.5) << "\n";

    Pair<int, int> p(10, 20);
    p.swapValues();
    std::cout << "Pair after swap: " << p.getFirst() << ", " << p.getSecond() << "\n";

    Box<int> box;
    box.add(5);
    box.add(10);
    box.add(15);
    std::cout << "Box total = " << box.total() << "\n";

    std::cout << "describe(10) = " << describe(10) << "\n";
    std::cout << "describe(string) = " << describe(std::string("hello")) << "\n";

    FixedArray<int, 5> arr;
    arr.set(0, 42);
    std::cout << "FixedArray at 0 = " << arr.at(0) << "\n";

    return 0;
}
