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

void showPath(List *s){
    Folder *aux;
    printf("-");
    if(!isEmpty(s)){
        aux = s->bottom;
        aux = aux->next; // skip root
        while(aux != NULL){
            printf("%s-",aux->p->name);
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
    } else if(p->child){
        aux = p->child;
        while(aux->next != NULL && aux->next->name[0] > name[0]){
            aux = aux->next;
        }
        if(aux->next){
            temp = aux->next;
            aux->next = createNode(name,type);
            aux->next->next = temp;
            return p;
            
        } else {
            aux->next = createNode(name,type);
            return p;
        }
    }else {
        p->child = createNode(name,type);
        return p;
    }
}

Node *removeNode(Node *p, char *name){
    Node *aux = p;
    Node *temp;
    if(!p){
        return NULL;
    } else {
        while(aux->next != NULL && strcmp(aux->next->name,name) != 0){
            aux = aux->next;
        }
        if(aux->next){
            if(aux->next->type == fdr){
                temp = aux->next;
                aux->next = aux->next->next;
                temp = removeFolder(temp->child);
                free(temp);
                
            }
            else{
                temp = aux->next;
                aux->next = aux->next->next;
                free(temp);
            }
        }
        return p;
    }
}
Node* removeFolder(Node* folder){
    Node* aux = folder;
    Node* temp;
    while(aux){
        if(aux->type == fdr && aux->child){
            aux->child = removeFolder(aux->child);
        }
        temp = aux;
        aux = aux->next;
        free(temp);
    }
    return NULL;
}

void listNodes(Node* p){
    Node* aux = NULL;
    if(p->child){
        aux = p->child;
    }
    while(aux){
        if(aux->type == fdr){
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

void initializeList(List *s){
    s->top = NULL;
    s->bottom = NULL;
}

int isEmpty(List *s){
    return s->bottom == NULL;
}

void push(List *s, Node *p){
    Folder *aux = (Folder*)malloc(sizeof(Folder));
    aux->p = p;
    aux->next = NULL;
    if(isEmpty(s)){
        s->top = aux;
        s->bottom = aux;
    } else {
        s->top->next = aux;
        aux->prev = s->top;
        s->top = aux;
    }
}

void folderOut(List *s){
    Folder *aux, *temp;
    if(!isEmpty(s)){
        aux = s->top;
        s->top = s->top->prev;
        if(s->top){
            s->top->next = NULL;
        } else {
            s->bottom = NULL;
        }
        free(aux);   
    }
}
void folderIn(List *s, char* name){
    Node *aux;
    if(!isEmpty(s)){
        aux = s->top->p;
        aux = aux->child;
        while(aux != NULL && strcmp(aux->name,name) != 0){
            aux = aux->next;
        }
        if(aux){
            push(s,aux);
        }
    }
}