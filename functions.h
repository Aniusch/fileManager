#include "structs.h"
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void copyStr(char dest[], char src[], int start, int end);
Node* createNode(char* name, Type type);
Node* insertNode(Node* root, char* name, Type type);
void listNodes(Node* root);
void showPath(List* s);
Node* changeFolder(Node* root, char* name);
void initializeList(List *s);
void push(List *s, Node *p);
void folderOut(List *s);
Node* folderIn(List *s, char* name);
Node *removeNode(Node *p, char *name);
Node* removeFolder(Node* folder);
int isEmpty(List *s);
#endif