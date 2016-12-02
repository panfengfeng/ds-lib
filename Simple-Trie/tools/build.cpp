#include "simple_trie.h"

int main(int argc, char **argv) {
    if (argc < 3 || string(argv[1]) == "-h") {
        cerr << "Usage: build input output\n";
        return 0;
    }
    simple_trie::Trie* trie = new simple_trie::Trie::Trie();
    trie->read(argv[1]);
    trie->save(argv[2]);

    cout << "Node number: " << trie->size() << endl;
    cout << "Node size: " << trie->nodeSize() << endl;
    cout << "Total size: " << trie->size() * trie->nodeSize() << " bytes" << endl;

    delete trie;
    return 0;
}
