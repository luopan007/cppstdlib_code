
#include "algostuff.hpp"
using namespace std;

int main()
{
    vector<int> coll = { 17, -3, 22, 13, 13, -9 };
    PRINT_ELEMENTS(coll,"coll:     ");

    // convert into relative values
    adjacent_difference (coll.cbegin(), coll.cend(),  // source
                         coll.begin());               // destination
    PRINT_ELEMENTS(coll,"relative: ");
     
    // convert into absolute values
    partial_sum (coll.cbegin(), coll.cend(),          // source
                 coll.begin());                       // destination
    PRINT_ELEMENTS(coll,"absolute: ");
}
