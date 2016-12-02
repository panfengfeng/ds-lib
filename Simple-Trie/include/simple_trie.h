#ifndef SIMPLE_TRIE_H
#define SIMPLE_TRIE_H

#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <iostream>
#include "node.h"

namespace simple_trie {
    
    typedef char Label;
    const Label LEAF = '\0';

    class Trie {
        public:
            Trie() {
                nodes.push_back(Node());
                labels.push_back(LEAF);   
            }

            ~Trie() {
            }

            size_t size() const {return nodes.size();}
            size_t nodeSize() const {return sizeof(Node) + sizeof(Label);}
            void printLabels() {
                cout << "labels size " << labels.size() << endl;
                for (int i = 0; i < labels.size(); i++) {
                    cout << labels[i] << endl;
                }
            }

            void addNode(Label label, Index next, Index child) { 
                nodes.push_back(Node(next, child));
                labels.push_back(label);
            }

            bool insert(const string &key) {
                string key_(key);
                key_.push_back(LEAF);
                return insert(key_.begin(), key_.end(), 0);
            }

            bool insert(string::const_iterator begin, string::const_iterator end, Index current);

            Index lookup(const string &key) {
                string key_(key);
                key_.push_back(LEAF);
                return lookup(key_.begin(), key_.end(), 0);
            }

            Index lookup(string::const_iterator begin, string::const_iterator end, Index current);
            void traverse(Index current, string str);
            void save(const string &filename);
            void load(const string &filename);
            void read(const string &filename);

        private:
            vector<Node> nodes;
            vector<Label> labels;

    };

}

#endif

