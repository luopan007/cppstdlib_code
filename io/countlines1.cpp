
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>

int countLines (std::istream& in)
{
    return std::count(std::istreambuf_iterator<char>(in),
                      std::istreambuf_iterator<char>(),
                      '\n');
}

int main (int argc, char* argv[])
{
    int count;

    if (argc == 1) {
       // no argument => count lines of standard input
       count = countLines(std::cin);
    }
    else {
       // count number of lines of all files passed as argument
       std::ifstream in;
       count = 0;
       for (int i=1; i<argc; ++i) {
           std::ifstream file(argv[i]);
           if (!file) {
               std::cerr << "failed to open " << argv[i] << "\n";
           }
           else {
               count += countLines(file);
           }
       }
    }
    std::cout << count << std::endl;
}
