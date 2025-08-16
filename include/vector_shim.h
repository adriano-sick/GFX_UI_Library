#ifndef VECTOR_SHIM_H
#define VECTOR_SHIM_H

#if defined(__AVR__)
// Implementação mínima para AVR
namespace std {
    template<typename T> class vector {
    public:
        void push_back(const T&);
        T& operator[](size_t);
        size_t size() const;
    };
}
#else
#include <vector>
#endif

#endif