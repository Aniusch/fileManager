#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void showPath(Node *root){
    Node *aux = root;
    printf("-");
    while(root && (aux->next != NULL || aux->child != NULL)){
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

Node* insertNode(Node* p, char* name, Type type){
    Node* aux = p;
    Node* temp;
    if(!p){
        return createNode(name,type);
    } else {
        while(aux->next != NULL && aux->next->name[0] < name[0]){
            aux = aux->next;
        }
        if(aux->next){
            temp = aux->next;
            aux->next = createNode(name,type);
            aux->next->next = temp;
        }
        else {aux->next = createNode(name,type);}
        
        return p;
    }
}

void listNodes(Node* p){
    Node* aux = p;
    while(aux){
        if(aux->type == folder){
            printf("%s-\n",aux->name);
        } else {
            printf("%s\n",aux->name);
        }
        aux = aux->next;
    }
}

Node* changeFolder(Node* root, char* name){
    Node* aux = root;
    while(aux){
        if(strcmp(aux->name,name) == 0){
            return aux;
        }
        aux = aux->next;
    }
    return root;
}

void initializeStack(Stack *s){
    s->top = NULL;
}

int isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, Node *p){
    Folder *aux = (Folder*)malloc(sizeof(Folder));
    aux->p = p;
    aux->next = s->top;
    s->top = aux;
}

Node* folderOut(Stack *s){
    Folder *temp;
    if(isEmpty(s)){
        return NULL;
    } else {
        
        Folder *aux = s->top;
        s->top = s->top->next;
        temp = aux;
        free(aux);
        return temp->p;
    }
}
Node* folderIn(Stack *s, Node *p){
    push(s,p);
    return p;
}