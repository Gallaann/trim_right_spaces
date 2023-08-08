//
// Created by gallann on 29.07.23.
//

#include <cctype>
#include <cstring>
#include <stdexcept>

namespace function
{
void TrimRight(char* s)
{
    if (!s)
    {
        throw std::invalid_argument("string is null");
    }

    auto length = strlen(s);

    while (length > 0 && isspace(s[length - 1]))
    {
        --length;
    }

    s[length] = '\0';
}
}  // namespace function
