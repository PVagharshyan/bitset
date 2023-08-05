//main
#include <iostream>
#include <cassert>

class bitset {
private:
    int* m_encompassing_array;
    int m_size;
public:
    bitset(int);
    void set(int);
    //void reset(int);
    void print_bitset() const;
    //~bitset();
};

int main() {
    bitset b(100);
    b.set(350);
    b.print_bitset();
    return 0;
}

//functions

bool size_is_acceptable (int size) {
    if (size <= 0) {
        return false;
    }
    return true;
}

int size_determination(int size) {
    return ((size/(sizeof(int)*8)) + 1);
}

int pow_2 (int n) {
    int result = 1;
    for (int i = 0;i < n;++i) {
        result *= 2;
    }
    return result;
}

//bitset

bitset::bitset(int size)
{
    assert(size_is_acceptable(size));
    if (size_is_acceptable(size)) {
        m_size = size;
    }
    m_encompassing_array = new int[size_determination(size)]{0};
}

void bitset::print_bitset() const {
    for (int i = 0;i < size_determination(m_size);++i) {
        std::cout << m_encompassing_array[i] << std::endl;
    }
}

void bitset::set(int possition) {
    assert(possition < m_size);
    int possition_int = (possition + 1)/(sizeof(int)*8);
    int possition_bit = possition - possition_int*(sizeof(int)*8) - 1; 
    m_encompassing_array[possition_int] |= pow_2(possition_bit); 
}










