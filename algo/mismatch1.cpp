
#include "algostuff.hpp"
using namespace std;

int main()
{
    vector<int> coll1 = { 1, 2, 3, 4, 5, 6 };
    list<int>   coll2 = { 1, 2, 4, 8, 16, 3 };

    PRINT_ELEMENTS(coll1,"coll1: ");
    PRINT_ELEMENTS(coll2,"coll2: ");

    // find first mismatch
    auto values = mismatch (coll1.cbegin(), coll1.cend(),  // first range
                            coll2.cbegin());               // second range
    if (values.first == coll1.end()) {
        cout << "no mismatch" << endl;
    }
    else {
        cout << "first mismatch: "
             << *values.first  << " and "
             << *values.second << endl;
    }

    // find first position where the element of coll1 is not
    // less than the corresponding element of coll2
    values = mismatch (coll1.cbegin(), coll1.cend(),       // first range
                       coll2.cbegin(),                     // second range
                       less_equal<int>());                 // criterion
    if (values.first == coll1.end()) {
        cout << "always less-or-equal" << endl;
    }
    else {
        cout << "not less-or-equal: "
             << *values.first << " and "
             << *values.second << endl;
    }
}
