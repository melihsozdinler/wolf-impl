//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_NODE_H
#define WOLF_NODE_H

#include <string>

class Node {
    public:
        const std::string ToString() const;
        std::string label;
        uint32_t uniqueId;
        uint32_t uniqueIdLayer;
        double weight = 1.0;

    friend bool operator== (const Node& lhs, const Node& rhs){
        return lhs.uniqueId == rhs.uniqueId;
    }
    friend bool operator!= (const Node& lhs, const Node& rhs){
        return !(lhs.uniqueId == rhs.uniqueId);
    }

    bool operator <(const Node& rhs) const
    {
        return uniqueId < rhs.uniqueId;
    }
};

using node = Node;

#endif //WOLF_NODE_H
