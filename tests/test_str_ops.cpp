#include <gtest/gtest.h>

#include "str_ops.h"

TEST(StrLen, CountsRegularString) {
    EXPECT_EQ(str_len("Hello, Mai"), 10U);
}

TEST(StrLen, NullptrHasZeroLength) {
    EXPECT_EQ(str_len(nullptr), 0U);
}

TEST(StrAlloc, CreatesCorrectCopy) {
    char* copy = str_alloc("Hello");

    ASSERT_NE(copy, nullptr);
    EXPECT_STREQ(copy, "Hello");

    str_delete(copy);
}

TEST(StrAlloc, CreatesIndependentMemory) {
    char* source = str_alloc("cat");
    char* copy = str_alloc(source);

    ASSERT_NE(source, nullptr);
    ASSERT_NE(copy, nullptr);
    EXPECT_NE(source, copy);

    source[0] = 'b';

    EXPECT_STREQ(source, "bat");
    EXPECT_STREQ(copy, "cat");

    str_delete(source);
    str_delete(copy);
}

TEST(StrCopy, CopiesIntoAllocatedBuffer) {
    char* source = str_alloc("Hello");
    char* destination = new char[str_len(source) + 1];

    str_copy(destination, source);

    EXPECT_STREQ(destination, "Hello");

    str_delete(source);
    str_delete(destination);
}

TEST(StrDelete, SetsPointerToNullptr) {
    char* text = str_alloc("text");

    str_delete(text);

    EXPECT_EQ(text, nullptr);
}

TEST(StrToUpper, ConvertsLowercaseLetters) {
    char* text = str_alloc("hello");

    str_to_upper(text);

    EXPECT_STREQ(text, "HELLO");

    str_delete(text);
}

TEST(StrToUpper, DoesNotChangeDigitsOrSymbols) {
    char* text = str_alloc("aZ9, b!");

    str_to_upper(text);

    EXPECT_STREQ(text, "AZ9, B!");

    str_delete(text);
}

TEST(StrCountChar, CountsSeveralMatches) {
    char* text = str_alloc("banana");

    EXPECT_EQ(str_count_char(text, 'a'), 3U);
    EXPECT_EQ(str_count_char(text, 'n'), 2U);

    str_delete(text);
}

TEST(StrCountChar, ReturnsZeroWhenNotFound) {
    char* text = str_alloc("banana");

    EXPECT_EQ(str_count_char(text, 'x'), 0U);

    str_delete(text);
}

TEST(StrCountChar, IsCaseSensitive) {
    char* text = str_alloc("Hello");

    EXPECT_EQ(str_count_char(text, 'l'), 2U);
    EXPECT_EQ(str_count_char(text, 'L'), 0U);

    str_delete(text);
}

TEST(EmptyString, VariantFunctionsWorkCorrectly) {
    char* text = str_alloc("");

    str_to_upper(text);

    EXPECT_STREQ(text, "");
    EXPECT_EQ(str_count_char(text, 'a'), 0U);

    str_delete(text);
}

// TEST(StrNCopy, CopiesWhenBufferIsLargeEnough) {
//     char* buffer = new char[6];
//
//     EXPECT_TRUE(str_n_copy(buffer, "Hello", 6));
//     EXPECT_STREQ(buffer, "Hello");
//
//     str_delete(buffer);
// }
//
// TEST(StrNCopy, TruncatesWhenBufferIsTooSmall) {
//     char* buffer = new char[4];
//
//     EXPECT_FALSE(str_n_copy(buffer, "Hello", 4));
//     EXPECT_STREQ(buffer, "Hel");
//
//     str_delete(buffer);
// }