//
// Created by Melih Sozdinler on 5/17/2021.
//

#include "BipartiteGraph.h"

template class BipartiteGraph<int,int>;

template<class T,class V>
Node BipartiteGraph<T,V>::new_layera_node(){
    Node *n = new Node();
    n->uniqueId = std::atomic_fetch_add(&nodeLayerAIdStore, 1);
    nodesA[0].push_back(*n);
    return *n;
}

template<class T,class V>
Node BipartiteGraph<T,V>::new_layera_node(T weight){
    Node *n = new_layera_node();
    n->weight = weight;
    return *n;
}

template<class T,class V>
Node BipartiteGraph<T,V>::new_layerb_node(){
    Node *n = new Node();
    n->uniqueId = std::atomic_fetch_add(&nodeLayerBIdStore, 1);
    nodes[1].push_back(*n);
    return *n;
}

template<class T,class V>
Node BipartiteGraph<T,V>::new_layerb_node(T weight){
    Node *n = new_layerb_node();
    n->weight = weight;
    return *n;
}

template<class T,class V>
Node BipartiteGraph<T,V>::new_node(){
    Node *n = new Node();
    n->uniqueId = std::atomic_fetch_add(&nodeIdStore, 1);
    nodes[0].push_back(*n);
    return *n;
}

template<class T,class V>
Node BipartiteGraph<T,V>::new_node(T weight){
    Node *n = new Node();
    n->uniqueId = std::atomic_fetch_add(&nodeIdStore, 1);
    n->weight = weight;
    nodes[0].push_back(*n);
    return *n;
}

template<class T,class V>
List<Node> BipartiteGraph<T,V>::GetAllNodes() {
    List<Node> temp;
    temp.merge(nodes[0]);
    temp.merge(nodes[1]);
    return temp;
}

template<class T,class V>
List<Edge> BipartiteGraph<T,V>::GetAllEdges() {
    return List<Edge>();
}

template<class T,class V>
List<Edge> BipartiteGraph<T,V>::GetAdjEdges(Node input){
    return List<Edge>();
}

template<class T,class V>
Edge BipartiteGraph<T,V>::new_edge(Node source, Node target, V weight) {
    Edge *edge = new Edge();
    edge->source = source;
    edge->target = target;
    edge->weight = weight;
    edge->uniqueId = std::atomic_fetch_add(&edgeIdStore, 1);
    edges.push_back(*edge);
    return *edge;
}

template<class T,class V>
Edge BipartiteGraph<T,V>::new_edge(const Node source, const Node target) {
    Edge *edge = new Edge();
    edge->source = source;
    edge->target = target;
    edge->weight = 1.0;
    edge->uniqueId = std::atomic_fetch_add(&edgeIdStore, 1);
    edges.push_back(*edge);
    return *edge;
}