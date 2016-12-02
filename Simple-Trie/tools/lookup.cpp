#include "simple_trie.h"

int main(int argc, char **argv) {
    if (argc < 2 || string(argv[1]) == "-h") {
        cerr << "Usage: lookup trie\n";
        return 0;
    }

    simple_trie::Trie* trie = new simple_trie::Trie::Trie();
    trie->load(argv[1]);
    string query;
    while (cin >> query) {
        simple_trie::Index result = trie->lookup(query);
        if (result == simple_trie::NOP)
            cout << "not found" << endl;
        else 
            cout << result <<  "  " << query << endl;
    }

    delete trie;
    return 0;
}
