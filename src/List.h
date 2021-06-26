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
        for (std::list<T>::iterator it = this->begin(); it != this->end(); ++it){
            if ((*it) == n)
                return it;
        }
        return this->end();
    }

    typename std::list<T>::iterator GetItem(const int index){
        int count = 0;
        for (std::list<T>::iterator it = this->begin(); it != this->end(); ++it, count++){
            if (count == index)
                return it;
        }
        return this->end();
    }

    void Print(){
        std::cout << "Implement print here" << std::endl;
    }
};

#endif //WOLF_LIST_H
