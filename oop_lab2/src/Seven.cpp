#include <memory>
#include <stdexcept>
#include <iostream>
#include "../include/Seven.hpp"


Seven::Seven() {
    arr = new unsigned char[sizeof(unsigned char)];
}

void Seven::shrink_to_fit() {
    size_t right_bound = sz;
    for (size_t i = sz; i > 0; --i) {
        if (arr[i - 1] != '0') {
            right_bound = i;
            break;
        }
        right_bound = i;
    }

    if (right_bound == 0) {
        delete[] arr;
        arr = new unsigned char[1];
        sz = 1;
        return;
    }

    auto *tmp_arr = new unsigned char[right_bound];
    for (size_t i{0}; i < right_bound; ++i)
        tmp_arr[i] = arr[i];

    delete[] arr;
    arr = tmp_arr;
    sz = right_bound;
}

Seven::Seven(const Seven &other) {
    sz = other.sz;
    auto *new_arr = new unsigned char[sz * sizeof(unsigned char)];

    try {
        std::uninitialized_copy(other.arr, other.arr + other.sz, new_arr);
    } catch (...) {
        delete[] new_arr;
        throw;
    }
    arr = new_arr;
}

Seven::Seven(const std::initializer_list<unsigned char> &init) {
    arr = new unsigned char[init.size()];
    size_t i = 0;
    for (auto c: init) {
        if (c - '0' >= 7) {
            delete[] arr;
            throw std::logic_error("Not a number in the septenary number system");
        }
        arr[i] = c;
        ++i;
    }
    sz = init.size();
    shrink_to_fit();
}


bool Seven::operator==(const Seven &x) {
    if (sz != x.sz)
        return false;
    for (size_t i = 0; i < sz; ++i) {
        if (arr[i] != x.arr[i]) {
            return false;
        }
    }
    return true;
}


bool Seven::operator!=(const Seven &x) {
    return not(*this == x);
}


Seven::~Seven() {
    delete[] arr;
}


Seven &Seven::operator=(const Seven &other) {
    if (this == &other) {
        return *this;
    }

    arr = new unsigned char[sz];
    for (size_t i = 0; i < sz; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;
}

Seven::Seven(Seven &&other) noexcept {
    sz = other.sz;
    arr = other.arr;

    other.sz = 0;
    other.arr = nullptr;
    shrink_to_fit();
}

std::ostream &operator<<(std::ostream &out, const Seven &x) {
    for (size_t i = x.sz; i > 0; --i)
        out << x.arr[i - 1];
    return out;
}

Seven::Seven(const std::string &x) {
    arr = new unsigned char[x.size()];
    size_t curr_pos = 0;
    for (size_t i = x.size(); i > 0; --i) {
        if (x[i - 1] - '0' >= 7) {
            delete[] arr;
            throw std::logic_error("Not a number in the septenary number system");
        }
        arr[curr_pos] = static_cast<unsigned char>(x[i - 1]);
        ++curr_pos;
    }

    sz = x.size();
    shrink_to_fit();
}

bool Seven::operator>(const Seven &other) const {
    if (sz > other.sz)
        return true;
    if (sz < other.sz)
        return false;

    for (size_t i = sz; i > 0; --i) {
        if (arr[i - 1] > other.arr[i - 1])
            return true;
        if (arr[i - 1] < other.arr[i - 1])
            return false;
    }

    return false;
}

bool Seven::operator<(const Seven &other) const {
    if (sz > other.sz)
        return false;
    if (sz < other.sz)
        return true;

    for (size_t i = sz; i > 0; --i) {
        if (arr[i - 1] > other.arr[i - 1])
            return false;
        if (arr[i - 1] < other.arr[i - 1])
            return true;
    }

    return false;
}

Seven Seven::operator+(const Seven &other) const {
    Seven tmp(*this);
    tmp += other;
    return tmp;
}

Seven &Seven::operator+=(const Seven &other) {
    size_t max_sz = std::max(sz, other.sz);
    auto *tmp_arr = new unsigned char[max_sz + 1];
    tmp_arr[max_sz] = '0';
    int64_t remainder = 0;

    for (size_t i = 0; i < max_sz; ++i) {
        if (i < sz) {
            remainder += arr[i] - '0';
        }
        if (i < other.sz) {
            remainder += other.arr[i] - '0';
        }
        tmp_arr[i] = (remainder % 7) + '0';
        remainder /= 7;
    }
    if (remainder != 0) {
        tmp_arr[max_sz] = remainder + '0';
    }

    delete[] arr;
    sz = max_sz + 1;
    arr = tmp_arr;
    shrink_to_fit();

    return *this;
}

Seven &Seven::operator-=(const Seven &other) {
    if (*this < other)
        throw std::logic_error("'Seven' class can only operate with non-negative numbers");

    int64_t getting = 0;
    for (size_t i = 0; i < other.sz; ++i) {
        int64_t curr_digit = arr[i] - other.arr[i] - getting;
        if (curr_digit < 0) {
            curr_digit = (7 + curr_digit) % 7;
            getting = 1;
        } else {
            getting = 0;
        }
        arr[i] = curr_digit + '0';
    }
    for (size_t i = other.sz; i < sz; ++i) {
        int64_t curr_digit = arr[i] - getting - '0';
        if (curr_digit < 0) {
            curr_digit = (7 + curr_digit) % 7;
            getting = 1;
        } else {
            getting = 0;
        }
        arr[i] = curr_digit + '0';
    }

    if (getting > 0)
        throw std::logic_error("'Seven' class can only operate with non-negative numbers");

    shrink_to_fit();
    return *this;
}

Seven Seven::operator-(const Seven &other) const {
    Seven tmp(*this);
    tmp -= other;
    return tmp;
}
