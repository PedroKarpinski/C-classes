#include "string_lib.h"

#include <stdio.h>

int main(void) {
    char* data1 = "abc";
    int len1 = 3;
    char* data2 = "def";
    int len2 = 3;

    String* str1 = string_create(data1, len1);
    String* str2 = string_create(data2, len2);
    printf("String 1: "); string_print(str1);
    printf("String 2: "); string_print(str2);

    string_append(str1, str2);
    printf("String 1 + String 2: "); string_print(str1);

    string_reverse(str1);
    printf("String 1 + String 2 invertida: "); string_print(str1);

    string_destroy(str1);
    string_destroy(str2);
    return 0;
}