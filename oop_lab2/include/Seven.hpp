#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

class Seven {
private:
    size_t sz = 0;
    unsigned char *arr;

public:
    Seven();
    ~Seven();

    Seven& operator=(const Seven &other);
    Seven(const Seven &other);
    Seven(const std::initializer_list<unsigned char> &init);
    explicit Seven(const std::string &x);
    Seven(Seven&& other) noexcept;
    void shrink_to_fit();

    bool operator>(const Seven &other) const;
    bool operator<(const Seven &other) const;
    bool operator==(const Seven &x);
    bool operator!=(const Seven &x);

    Seven& operator+=(const Seven &other);
    Seven operator+(const Seven& other) const;

    Seven& operator-=(const Seven &other);
    Seven operator-(const Seven&other) const;

    friend std::ostream& operator<<(std::ostream &out, const Seven &x);

};

#endif
