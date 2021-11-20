cmake_minimum_required(VERSION 3.19)
project(wolflib)

add_library(wolflib STATIC impl/WolfImpl.cpp model/graph/BipartiteGraph.cpp model/graph/Graph.cpp model/graph/Edge.cpp
        model/graph/Node.cpp model/combined/Matrix.cpp model/basic/Array.cpp model/combined/NodeArray.cpp model/basic/List.cpp)