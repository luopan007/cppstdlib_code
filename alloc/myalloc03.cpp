
#include "myalloc03.hpp"
#include <vector>
#include <map>
#include <string>
#include <functional>

int main()
{
    // a vector with special allocator
    std::vector<int,MyAlloc<int> > v;

    // an int/float map with special allocator
    std::map<int,float,std::less<int>,
             MyAlloc<std::pair<const int,float> > > m;

    // a string with special allocator
    std::basic_string<char,std::char_traits<char>,MyAlloc<char> > s;


    // special string type that uses special allocator
    typedef std::basic_string<char,std::char_traits<char>,
                              MyAlloc<char> > MyString;

    // special string/string map type that uses special allocator
    typedef std::map<MyString,MyString,std::less<MyString>,
                     MyAlloc<std::pair<const MyString,MyString> > > MyMap;
    // create object of this type
    MyMap mymap;
    //...
}
