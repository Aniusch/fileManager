#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef enum type{   fdr = 1,
                fl} Type;

typedef struct node{
    char* name;
    Type type; // 1 for folder, 2 for file;
    struct node *next;
    struct node *child;
} Node;

typedef struct folder{
    struct node *p;
    struct folder *next;
} Folder;

typedef struct stack{
    struct folder *top;
} Stack;

#endif