//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_GRAPH_H
#define WOLF_GRAPH_H

#include <string>
#include <map>
#include <iostream>

#include "Node.h"
#include "Edge.h"
#include "List.h"

using namespace std;

template<class T,class V>
class Graph {

public:
    Node source(const Edge e){
        // TODO
        return Node();
    }

    Node target(const Edge e){
        // TODO
        return Node();
    }

    virtual Node new_layera_node() = 0;
    virtual Node new_layerb_node() = 0;
    virtual Node new_layera_node(T weight) = 0;
    virtual Node new_layerb_node(T weight) = 0;
    virtual Node new_node() = 0;
    virtual Node new_node(T weight) = 0;
    virtual V& operator[](Edge input) = 0;
    virtual List<Node> GetAllNodes() = 0;
    virtual List<Edge> GetAllEdges() = 0;
    virtual List<Edge> GetAdjEdges(Node input) = 0;
    virtual Edge new_edge(const Node source, const Node target, V weight) = 0;
    virtual Edge new_edge(const Node source, const Node target) = 0;
};

#endif //WOLF_GRAPH_H
