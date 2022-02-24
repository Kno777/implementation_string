#include <iostream>
#include "string.h"

int main()
{
    Kno::string str;
    Kno::string tox;
    Kno::string miasin;
    tox.push_back('H');
    tox.push_back('e');
    tox.push_back('l');
    tox.push_back('l');
    tox.push_back('o');

    str.push_back('K');
    

    miasin = (str + tox);
    std::cout << miasin;
}