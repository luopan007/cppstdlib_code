
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
using namespace std;


int main()
{
    // create a string
    string s("The zip code of Braunschweig in Germany is 38100");
    cout << "original: " << s << endl;

    // lowercase all characters
    transform (s.cbegin(), s.cend(),  // source
               s.begin(),             // destination
               [] (char c) {          // operation
                   return tolower(c);
               });
    cout << "lowered:  " << s << endl;

    // uppercase all characters
    transform (s.cbegin(), s.cend(),  // source
               s.begin(),             // destination
               [] (char c) {          // operation
                   return toupper(c);
               });
    cout << "uppered:  " << s << endl;

    // search case-insensitive for Germany
    string g("Germany");
    string::const_iterator pos;
    pos = search (s.cbegin(),s.cend(),     // source string in which to search
                  g.cbegin(),g.cend(),     // substring to search
                  [] (char c1, char c2) {  // comparison criterion
                      return toupper(c1) == toupper(c2);
                 });
    if (pos != s.cend()) {
        cout << "substring \"" << g << "\" found at index "
             << pos - s.cbegin() << endl;
    }
}

