
#include <locale>
#include <iostream>
#include <string>

class germanBoolNames : public std::numpunct_byname<char> {
  public:
    germanBoolNames (const std::string& name)
      : std::numpunct_byname<char>(name) {
    }
  protected:
    virtual std::string do_truename () const {
        return "wahr";
    }
    virtual std::string do_falsename () const {
        return "falsch";
    }
};

int main()
{
    std::locale loc (std::locale(""), new germanBoolNames(""));
    std::cout.imbue(loc);
    std::cout << std::boolalpha << true << std::endl;
}
