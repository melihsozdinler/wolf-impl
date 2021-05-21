#include <iostream>
#include "src/BipartiteGraph.h"
#include "src/NodeArray.h"

int main() {
    BipartiteGraph<int,int> G;
    Node source = G.new_node();
    Node target = G.new_node();
    Edge edge = G.new_edge(source,target);
    std::cout << G[edge] << std::endl;
    NodeArray store(G);
    store[source] = 1;
    std::cout << store[source] << std::endl;
    return 0;
}
