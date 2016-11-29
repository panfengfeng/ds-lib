#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <iostream>
#include "node.h"

typedef char Lable;
const Label LEAF = '\0';  // terminal flag

struct Trie {
	vector<Node> nodes;
	vector<Lable> labels;

	Trie() { 	// super root
		labels.push_back(LEAF);
		nodes.push_back(Node());
	}

	size_t size() const {return nodes.size();}
	size_t nodeSize() const {return sizeof(Node) + sizeof(Lable);}

	void addNode(Lable label, Index next, Index child) {
		labels.push_back(label);
		nodes.push_back(Node(next, child));
	}

	bool insert(const string &key) {
		string key_(key);
		key_.push_back(LEAF);
		return insert(key_.begin(), key_.end(), 0);
	}

	bool insert(string::const_iterator begin, string::const_iterator end, Index current) {
		// search prefix
		while (begin != end) {
	
			while (true) {
				if (labels[current] == *begin) {
					break;	
}
				if (nodes[current].next == NOP) {
					
}
						
			}
		}
	}
	
};
