cmake_minimum_required(VERSION 3.19)
project(wolflib)

add_library(wolflib STATIC WolfImpl.cpp BipartiteGraph.cpp Graph.cpp Edge.cpp
        Node.cpp Matrix.cpp Array.cpp NodeArray.cpp List.cpp)