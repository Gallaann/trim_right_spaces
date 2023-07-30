//
// Created by gallann on 31.07.23.
//

#include <gtest/gtest.h>

#include <cstring>

#include "TrimRight.h"

TEST(corner_situations_test, null_pointer)
{
    char *actual = nullptr;

    ASSERT_ANY_THROW(function::TrimRight(actual));
    ASSERT_EQ(nullptr, actual);
}

TEST(corner_situations_test, no_spaces)
{
    char actual[] = "text";

    function::TrimRight(actual);

    char expected[] = "text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(corner_situations_test, only_spaces)
{
    char actual[] = "                                          ";

    function::TrimRight(actual);

    char expected[] = "";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_middle_and_head)
{
    char actual[] = "                   text                                          text";

    function::TrimRight(actual);

    char expected[] = "                   text                                          text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_middle)
{
    char actual[] = "text                                          text";

    function::TrimRight(actual);

    char expected[] = "text                                          text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_middle_and_tail)
{
    char actual[] = "text                                          text                            ";

    function::TrimRight(actual);

    char expected[] = "text                                          text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_head_and_midle_and_tail)
{
    char actual[] = "                   text                                          text                            ";

    function::TrimRight(actual);

    char expected[] = "                   text                                          text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_head_and_tail)
{
    char actual[] = "                   text                            ";

    function::TrimRight(actual);

    char expected[] = "                   text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_tail)
{
    char actual[] = "text                            ";

    function::TrimRight(actual);

    char expected[] = "text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}

TEST(variant_text_test, spaces_in_the_head)
{
    char actual[] = "                   text";

    function::TrimRight(actual);

    char expected[] = "                   text";
    ASSERT_EQ(strlen(expected), strlen(actual));
}
