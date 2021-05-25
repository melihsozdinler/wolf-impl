#include <iostream>
#include "src/BipartiteGraph.h"
#include "src/NodeArray.h"
#include "src/WolfImpl.h"

int main() {
    BipartiteGraph<int,int> G;
    Node sourceA1 = G.new_layera_node();
    Node targetB1 = G.new_layerb_node();
    Node sourceA2 = G.new_layera_node();
    Node targetB2 = G.new_layerb_node();
    Node sourceA3 = G.new_layera_node();
    Node targetB3 = G.new_layerb_node();
    Node sourceA4 = G.new_layera_node();
    Node targetB4 = G.new_layerb_node();
    Edge edge = G.new_edge(sourceA1,targetB3);
    edge = G.new_edge(sourceA2,targetB3);
    edge = G.new_edge(sourceA1,targetB4);
    edge = G.new_edge(sourceA2,targetB4);
    edge = G.new_edge(sourceA3,targetB1);
    edge = G.new_edge(sourceA4,targetB1);
    edge = G.new_edge(sourceA3,targetB2);
    edge = G.new_edge(sourceA4,targetB2);
    std::cout << G[edge] << std::endl;
    NodeArray store(G);
    WolfImpl wolf;
    List<Node> newAList = wolf.Run(G);
    store[sourceA1] = 1;
    std::cout << store[sourceA1] << std::endl;
    return 0;
}
