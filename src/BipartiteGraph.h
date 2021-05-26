//
// Created by Melih Sozdinler on 5/17/2021.
//

#ifndef WOLF_BIPARTITEGRAPH_H
#define WOLF_BIPARTITEGRAPH_H

#include <string>
#include <map>
#include <iostream>

#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "List.h"

using namespace std;
template<class T,class V>
class BipartiteGraph : public Graph<T,V> {

private:
    std::map<int, List<Node> > nodes;
    List<Edge> edges;
    atomic_uint nodeIdStore;
    atomic_uint nodeLayerAIdStore;
    atomic_uint nodeLayerBIdStore;
    atomic_uint edgeIdStore;

public:

    BipartiteGraph(){
        nodeIdStore = 0;
        edgeIdStore = 0;
        nodeLayerAIdStore = 0;
        nodeLayerBIdStore = 0;
    }

    Node new_layera_node() override;
    Node new_layerb_node() override;
    Node new_layera_node(T weight) override;
    Node new_layerb_node(T weight) override;
    Node new_node() override;
    Node new_node(T weight) override;
    List<Node> GetAllNodes() override;
    List<Edge> GetAllEdges() override;
    List<Edge> GetAdjEdges(Node input) override;
    Edge new_edge(Node source, Node target, V weight)  override;
    Edge new_edge(const Node source, const Node target) override;

    V& operator[](Edge input) override{
        V param_val = input.weight;
        return param_val;
    }

    void clear() {}


    List<Node> BipartiteGraph<T,V>::GetLayerNodesA(){
        return nodes[0];
    }

    List<Node> BipartiteGraph<T,V>::GetLayerNodesB(){
        return nodes[1];
    }
};

template<class T,class V>
using GRAPH = BipartiteGraph<T,V>;

#endif //WOLF_BIPARTITEGRAPH_H
