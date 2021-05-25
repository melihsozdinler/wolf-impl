//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_LIST_H
#define WOLF_LIST_H

#include <iostream>
#include <list>
#include "Node.h"

template<class T>
class List : public std::list<T>{
public:

    List(){

    }

    List(typename std::list<T>::iterator iteratorBegin,
            typename std::list<T>::iterator iteratorEnd) {
        this->push_back(*iteratorBegin);
    }

    T& operator[](typename std::list<T>::iterator iter){
        return *iter;
    }

    size_t Length(){
        return this->size();
    }

    typename std::list<T>::iterator Search(const Node n){
        return this->end();
    }

    typename std::list<T>::iterator GetItem(const int index){
        return this->end();;
    }

    void Print(){
        std::cout << "Implement print here" << std::endl;
    }
};

#endif //WOLF_LIST_H
