#include <iostream>
#include "str_ops.h"

char* str_alloc(const char* src) {
    if (src == nullptr) {
        return nullptr;
    }

    char* result = new char[str_len(src) + 1];
    str_copy(result, src);

    return result;
}

std::size_t str_len(const char* s) {
    if (s == nullptr) {
        return 0;
    }

    std::size_t len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

void str_copy(char* dst, const char* src) {
    if (dst == nullptr || src == nullptr) {
        return;
    }

    std::size_t i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        ++i;
    }

    dst[i] = '\0';
};

// Безопасное копирование. Если src длинее выделенного буффера dst, то в dst окажется оберзанная версия src, вернется false.
// bool str_n_copy(char* dst, const char* src, std::size_t dst_capacity) {
//     if (dst == nullptr || dst_capacity == 0) {
//         return false;
//     }
//
//     if (src == nullptr) {
//         dst[0] = '\0';
//         return false;
//     }
//
//     std::size_t i = 0;
//
//     while (i + 1 < dst_capacity && src[i] != '\0') {
//         dst[i] = src[i];
//         ++i;
//     }
//
//     dst[i] = '\0';
//
//     return src[i] == '\0';
// }

void str_delete(char*& s) {
    delete[] s;
    s = nullptr;
}

void str_to_upper(char* s) {
    if (s == nullptr) {
        return;
    }

    for (std::size_t i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - ('a' - 'A');
        }
    }
}

std::size_t str_count_char(const char* s, char ch) {
    if (s == nullptr) {
        return 0;
    }

    std::size_t count = 0;

    for (std::size_t i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ch) {
            ++count;
        }
    }

    return count;
}

void str_print(const char* s) {
    if (s == nullptr) {
        std::cout << "(пустая строка)";
        return;
    }

    std::cout << s;
}