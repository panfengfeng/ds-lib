#include <iostream>
#include <vector>

using namespace std;

class Node {
	private:
		char mContent;
		bool mMarker;
		vector<Node*> mChildren;
	public:
		Node() {mContent = ' '; mMarker = false;}
		~Node() {}
		char content() {return mContent;}
		void setContent(char c) {mContent = c;}
		bool marker() {return mMarker;}
		void setMarker() {mMarker = true;}
		Node* findChild(char c);
		void appendChild(Node* child) {mChildren.push_back(child);}
		vector<Node*> children() {return mChildren;}
};

class Trie {
	private:
		Node* root;
	public:
		Trie();
		~Trie();
		void addWord(string s);
		bool searchWord(string s);
		void deleteWord(string s);
};

Node* Node::findChild(char c) {
	for (int i=0; i<mChildren.size(); i++) {
		Node* tmp = mChildren.at(i);
		if (tmp->content() == c) {
			return tmp;
		}
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

	for (int i=0; i<s.length(); i++) {
		Node* child = current->findChild(s[i]);
		if (child != NULL) {
			current = child;
		} else {
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}

		if (i == s.length()-1)
			current->setMarker();
	}
}

bool Trie::searchWord(string s) {
	Node* current = root;

	while (current != NULL) {
		for (int i=0; i<s.length(); i++) {
			Node* tmp = current->findChild(s[i]);
			if (tmp == NULL)
				return false;
			current = tmp;
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

int main() {
	Trie* trie = new Trie();
	trie->addWord("Hello");
	trie->addWord("Balloon");
	trie->addWord("Ball");
	
	if (trie->searchWord("Hell"))
		cout << "found Hell" <<endl;
	else
		cout << "not found Hell" <<endl;
		
	if (trie->searchWord("Hello"))
		cout << "found Hello" <<endl;
	else
		cout << "not found Hello" <<endl;
	
	if (trie->searchWord("Helloo"))
		cout << "found Helloo" <<endl;
	else
		cout << "not found Helloo" <<endl;
	
	if (trie->searchWord("Ball"))
		cout << "found Ball" <<endl;
	else
		cout << "not found Ball" <<endl;
	
	if (trie->searchWord("Balloon"))
		cout << "found Balloon" <<endl;
	else
		cout << "not found Balloon" <<endl;
	
	delete trie;
	return 0;
}
