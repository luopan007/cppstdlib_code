
#include <locale>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include "wstring2string.hpp"
#include "wstring2utf8.hpp"

int main()
{
    try {
#ifdef _MSC_VER
        // string with German umlaut and euro symbol (in Windows encoding):
        std::string s = "nj: \ae + \x80 1";

        // convert to wide-character string (using Windows encoding):
        std::wstring ws = to_wstring(s,std::locale("deu_DEU.1252"));
#else
        // string with German umlaut and euro symbol (in ISO Latin-9 encoding):
        std::string s = "nj: \ae + \xA4 1";

        // convert to wide-character string (using ISO Latin-9 encoding):
        std::wstring ws = to_wstring(s,std::locale("de_DE.ISO-8859-15"));
#endif

        // print string as UTF-8 sequence:
        std::cout << wstring_to_utf8(ws) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
