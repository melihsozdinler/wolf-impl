//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_EDGE_H
#define WOLF_EDGE_H

#include <string>
#include "Node.h"

class Edge {
    const std::string ToString();

public:
    Node source;
    Node target;
    std::string label;
    uint32_t uniqueId;
    double weight = 1.0;
};

using edge = Edge;

#endif //WOLF_EDGE_H
