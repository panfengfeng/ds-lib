#include "simple_trie.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 3 || string(argv[1]) == "-h") {
        cerr << "Usage: build input output\n";
        return 0;
    }
    simple_trie::Trie trie;
    trie.read(argv[1]);
    trie.save(argv[2]);

    return 0;
}
