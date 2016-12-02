#include "simple_trie.h"

int main(int argc, char **argv) {
    if (argc < 2 || string(argv[1]) == "-h") {
        cerr << "Usage: traverse trie\n";
        return 0;
    }

    int times = argc > 2 ? atoi(argv[2]) : 1;
    simple_trie::Trie* trie = new simple_trie::Trie::Trie();
    trie->load(argv[1]);
    string str;
    trie->traverse(0, str);
    delete trie;
    return 0;
}
