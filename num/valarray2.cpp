
#include <iostream>
#include <valarray>
using namespace std;

// print valarray
template <typename T>
void printValarray (const valarray<T>& va)
{
    for (int i=0; i<va.size(); i++) {
        cout << va[i] << ' ';
    }
    cout << endl;
}

int main()
{
    // create and initialize valarray with nine elements
    valarray<double> va(9);
    for (int i=0; i<va.size(); i++) {
        va[i] = i * 1.1;
    }

    // print valarray
    printValarray(va);

    // double values in the valarray
    va *= 2.0;

    // print valarray again
    printValarray(va);

    // create second valarray initialized by the values of the first plus 10
    valarray<double> vb(va+10.0);

    // print second valarray
    printValarray(vb);

    // create third valarray as a result of processing both existing valarrays
    valarray<double> vc(9);
    vc = sqrt(va) + vb/2.0 - 1.0;
    
    // print third valarray
    printValarray(vc);
}
