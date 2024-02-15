#include "string_lib.h"

#include <stdio.h>
#include <stdlib.h>

String* string_create(char* data, int length) {
    String* str = malloc(sizeof(String));

    str->data = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        str->data[i] = data[i];
    }

    str->length = length;

    return str;
}

void string_destroy(String* str) {
    free(str->data);
    free(str);
}

void string_print(String* str) {
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

String* string_reverse(String* str) {
    String* temp = malloc(sizeof(String));

    temp->data = malloc(str->length * sizeof(char));
    temp->length = str->length;

    for (int i = 0; i < str->length; i++)
        temp->data[str->length-i-1] = str->data[i];

    return temp;
}

void string_append(String *str1, String* str2) {
    str1->data = realloc(str1->data, (str1->length + str2->length) * sizeof(char));

    for (int i = str1->length; i < (str1->length + str2->length); i++)
        str1->data[i] = str2->data[i-str1->length];

    str1->length += str2->length;
}