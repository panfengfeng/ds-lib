#ifndef _BASIC_TRIE_H_
#define _BASIC_TRIE_H_

#include <iostream>
#include <vector>


namespace basic_trie {

using namespace std;

class Node {
    public:
        Node() {Content = ' '; Marker = false;};
        ~Node() {};
        char content() {return Content;}
        void setContent(char c) {Content = c;}
        bool marker() {return Marker;}
        void setMarker() {Marker = true;}
        Node* findChild(char c);
        void appendChild(Node* child) {Children.push_back(child);}
        vector<Node*> children() {return Children;}
    private:
        char Content;
        bool Marker;
        vector<Node*> Children;
};

class Trie {
    public:
        Trie();
        ~Trie();
        void addWord(string s);
        bool searchWord(string s);
        void deleteWord(string s);
    private:
        Node* root;
};

}

#endif
