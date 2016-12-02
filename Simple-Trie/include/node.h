#ifndef NODE_H
#define NODE_H

using namespace std;

namespace simple_trie {

typedef uint32_t Index;
const Index NOP = -1;

struct Node {
    Index next;   // branch
    Index child;  // children

    Node() : next(NOP), child(NOP) { }
    Node(Index next, Index child) : next(next), child(child) { }
    ~Node() { }

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

