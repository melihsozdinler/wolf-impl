//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_ARRAY_H
#define WOLF_ARRAY_H

#include <vector>

#include "BipartiteGraph.h"

template<class T>
class Array : public std::vector<T>{
public:
    template<class U,class Y>
    Array(const GRAPH<U,Y> &graph) {

    }

    Array(size_t i) {
        this->resize(i);
    }

    size_t Length(){
        return this->size();
    }

    T& operator[](int);
};

template<class T>
using wolf_array = Array<T>;

#endif //WOLF_ARRAY_H
