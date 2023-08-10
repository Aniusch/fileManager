#include "structs.h"
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void copyStr(char dest[], char src[], int start, int end);
Node* createNode(char* name, Type type);
Node* insertNode(Node* root, char* name, Type type);
void listNodes(Node* root);
void showPath(Node* root);
Node* changeFolder(Node* root, char* name);
void initializeStack(Stack *s);
void push(Stack *s, Node *p);
void folderOut(Stack *s)
void folderIn(Stack *s, char* name)
#endif