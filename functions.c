#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyStr(char dest[], char src[], int start, int end){
    int i = 0, tam = strlen(src);
    while(i+start<tam & i<end-start && src[i+start]!='\0'& src[i+start]!='\n'){
        dest[i] = src[i+start];
        i++;
    }
    dest[i] = '\0';
}

Node* createNode(char* name, Type type){
    Node* p = (Node*)malloc(sizeof(Node));
    p->name = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(p->name,name);
    p->type = type;
    p->next = NULL;
    p->child = NULL;
    return p;
}

void showPath(Node *raiz){
    Node *aux = raiz;
    printf("-");
    while(aux->next || aux->child){
        if(aux->child){
            printf("%s-",aux->name);
            aux = aux->child;
        } else if(aux->type == file){
            printf("%s-",aux->name);
            aux = aux->next;
        } else if(aux->next){
            aux = aux->next;
        }
    }
    printf(">");
}