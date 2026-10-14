#ifndef LAB1_STR_OPS_H
#define LAB1_STR_OPS_H
#include <cstddef>


char* str_alloc(const char* src);
std::size_t str_len(const char* s);
void str_copy(char* dst, const char* src);
void str_delete(char*& s);
void str_print(const char* s);

// bool str_n_copy(char* dst, const char* src, std::size_t dst_capacity);

void str_to_upper(char* s);
std::size_t str_count_char(const char* s, char ch);

#endif