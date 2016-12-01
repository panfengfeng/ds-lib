#ifndef NODE_H
#define NODE_H

namespace simple_trie {

using namespace std;

typedef uint32_t Index;
const Index NOP = -1;

struct Node {
    Index next;   // brothers
    Index child;  // children

    Node() : next(NOP), child(NOP) {}
    Node(Index next, Index child) {next = next; child = child;}

    bool operator==(const Node &node) const {
        return next == node.next &&
                child == node.child;
    }

    bool operator!=(const Node &node) const {
        return !(*this == node);
    }
};

}

#endif

