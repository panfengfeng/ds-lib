#include "basic_trie.h"

namespace basic_trie {

Node* Node::findChild(char c) {
    for (int i = 0; i < Children.size(); i++) {
        Node* temp = Children.at(i);
        if (temp->content() == c)
            return temp;
    }

    return NULL;
}


Trie::Trie() {
    root = new Node();
}

Trie::~Trie() {
    // free memory
}

void Trie::addWord(string s) {
    Node* current = root;

    if (s.length() == 0) {
        current->setMarker();
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        Node* child = current->findChild(s[i]);
        if (child != NULL) {
            current = child;
        } else {
            Node* temp = new Node();
            temp->setContent(s[i]);
            current->appendChild(temp);
            current = temp;
        }

        if (i == s.length()-1)
            current->setMarker();
    }
}

bool Trie::searchWord(string s) {
   Node* current = root;

   while (current != NULL) {
    for (int i = 0; i < s.length(); i++) {
        Node* temp = current->findChild(s[i]);
        if (temp == NULL)
            return false;
        current = temp;
    }
    if (current->marker()) 
        return true;
    else
        return false;
   }

   return false;
}

void Trie::deleteWord(string s) {
}

}

