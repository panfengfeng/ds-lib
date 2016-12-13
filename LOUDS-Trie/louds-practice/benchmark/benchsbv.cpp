#include "louds.h"

using namespace std;

int main() {
    louds::SuccinctBitVector::SuccinctBitVector* sbv = new louds::SuccinctBitVector::SuccinctBitVector();
    sbv->push(1);
    sbv->push(0);
    sbv->push(1);
    sbv->push(0);
    sbv->push(0);

    cout << "1 0 1 0 0" << endl;

    cout << "rank1(3) " << sbv->rank1(3) << endl;
    cout << "rank0(3) " << sbv->rank0(3) << endl;
    cout << "select1(3) " << sbv->select1(3) << endl;
    cout << "select0(3) " << sbv->select0(3) << endl;

    return 0;
}
