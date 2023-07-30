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
        return;
    }

    auto len = strlen(s);
    auto original_len = len;

    while (len > 0 && isspace(s[len - 1]))
    {
        --len;
    }

    s[len] = '\0';
}
}  // namespace function
