#include "basic_trie.h"

using namespace std;

int main() {

    basic_trie::Trie::Trie* trie = new basic_trie::Trie::Trie();
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
