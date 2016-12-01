#include "simple_trie.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2 || string(argv[1]) == "-h") {
        cerr << "Usage: lookup trie\n";
        return 0;
    }

    simple_trie::Trie trie;
    trie.load(argv[1]);
    string query;
    while (cin >> query) {
        simple_trie::Index result = trie.lookup(query);
        cout << result << endl;
    }

    return 0;
}
