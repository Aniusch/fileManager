#include <stdio.h>
#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef enum type{   folder = 1,
                file} Type;

typedef struct node{
    char* name;
    Type type; // 1 for folder, 2 for file;
    struct node *next;
    struct node *child;
} Node;

#endif