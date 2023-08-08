//
// Created by gallann on 29.07.23.
//

#include <cstring>
#include <iostream>

#include "TrimRight.h"

int main(int argc, char** argv)
{
    char* s = argv[1];

    std::cout << "Original text: \"" << s << "\"\n"
              << "Number of symbols: " << strlen(s) << "\n\n";

    function::TrimRight(s);

    std::cout << "Trimmed text: \"" << s << "\"\n"
              << "Number of symbols: " << strlen(s);

    return 0;
}
