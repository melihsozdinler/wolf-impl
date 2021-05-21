//
// Created by Melih Sozdinler on 5/16/2021.
//

#include "NodeArray.h"

int &NodeArray::operator[](const Node node) {
    return temp.at(node);
}
