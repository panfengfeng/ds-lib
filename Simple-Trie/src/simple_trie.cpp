#include "simple_trie.h"

namespace simple_trie {

bool Trie::insert(string::const_iterator begin, string::const_iterator end, Index current) {
    // search prefix
    while (begin != end) {
        // linear search
        while (true) {
            // found
            if (labels[current] == *begin) {
                break;
            }

            // not found
            if (nodes[current].next == NOP) {
                goto NEXT;
            }
                
            // go to next
            current = nodes[current].next;

        }
        begin++;
        current = nodes[current].child;
    }
    NEXT:
    if (begin == end)
        return false;

    // create new branch
    if ((size_t)current < nodes.size()) {
        addNode(*begin, nodes[current].next, NOP);
        nodes[current].next = nodes.size() - 1;
        current = nodes.size() - 1;
        begin++;
    }

    // insert suffix
    while (begin != end) {
        addNode(*begin, NOP, NOP);
        if ((size_t)current < nodes.size()) {
            nodes[current].child = nodes.size() - 1;
        }
        current = nodes.size() - 1;
        begin++;
    }

    return true;
}

Index Trie::lookup(string::const_iterator begin, string::const_iterator end, Index current) {
    while (begin != end) {
        while (true) {
            if (labels[current] == *begin)
                break;
            
            if (nodes[current].next == NOP)
                return NOP;
            
            current = nodes[current].next;
        }

        begin++;
        if (begin == end)
            return current;
        
        current = nodes[current].child;
    }

    return NOP;
}

void Trie::traverse(Index current, string str) {
    char label = labels.at(current);

    if (label == simple_trie::LEAF)
        cout << str << endl;

    if (nodes.at(current).child != NOP)
        traverse(nodes.at(current).child, str+label);

    if (nodes.at(current).next != NOP)
        traverse(nodes.at(current).next, str);
}


void Trie::save(const string &filename) {
    ofstream ofs(filename, ios::binary);
    ofs.write(labels.data(), labels.size() * sizeof(Label));
    ofs.write((Label*)nodes.data(), nodes.size() * sizeof(Node));
    ofs.close();
}

void Trie::load(const string &filename) {
    labels.clear();
    nodes.clear();
    ifstream ifs(filename, ios::binary);
    ifs.seekg(0, ifs.end);
    size_t size = ifs.tellg() / nodeSize();
    ifs.seekg(0, ifs.beg);

    labels.resize(size);
    nodes.resize(size);

    ifs.read(labels.data(), size * sizeof(Label));
    ifs.read((Label*)nodes.data(), size * sizeof(Node));
    ifs.close();
}

void Trie::read(const string &filename) {
    ifstream ifs(filename);
    string str;
    while (getline(ifs, str)) {
        insert(str);
    }
    ifs.close();
}

}
