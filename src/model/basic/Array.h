//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_ARRAY_H
#define WOLF_ARRAY_H

#include <vector>

#include "../graph/BipartiteGraph.h"

template<class T>
class Array{
private:
    std::vector<T> temp;
public:
    template<class U,class Y>
    Array(const GRAPH<U,Y> &graph) {
        for (auto const &nodeTemp : graph.GetAllNodes()) {
            temp.push_back(nodeTemp);
        }
    }

    Array(size_t i) {
        temp.resize(i);
    }

    size_t size(){
        return temp.size();
    }

    size_t Length(){
        return temp.size();
    }

    T& operator[](int index){
        return temp.at(index);
    }
};

#endif //WOLF_ARRAY_H
