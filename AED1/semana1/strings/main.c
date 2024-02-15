#include <stdio.h>
#include "string_lib.h"

int main(void) {
    char* data1 = "abc";
    int len1 = 3;
    char* data2 = "def";
    int len2 = 3;
    String* str1 = string_create(data1, len1);
    String* str2 = string_create(data2, len2);
    string_append(str1, str2);
    string_print(str1);
    string_destroy(str1);
    string_destroy(str2);
    return 0;
}