//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_NODEARRAY_H
#define WOLF_NODEARRAY_H

#include <map>

#include "BipartiteGraph.h"

class NodeArray {

private:
    std::map<Node, int> temp;
public:

    template<class U, class Y>
    NodeArray(GRAPH<U, Y> &graph) {
        for (auto const &nodeTemp : graph.GetAllNodes()) {
            temp.insert(std::pair<Node, int>(nodeTemp,0));
        }
    }

    bool operator()(const Node& node1, const Node& node2) const
    {
        return node1.uniqueId > node2.uniqueId;
    }

    int& operator[] (const Node node);
};

#endif //WOLF_NODEARRAY_H
