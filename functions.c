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
    Stack *temp;
    printf("-");
    do{
        if(aux->child){
            if(aux != root) printf("%s-",aux->name);
            aux = aux->child;
        }
        else if(aux->next){
            aux = aux->next;
        }
    }while(aux && (aux->child || aux->next));
    printf(">");
    
}

Node* insertNode(Node* p, char* name, Type type){
    Node* aux = p;
    Node* temp;
    if(!p){
        return createNode(name,type);
    } else {
        if(p->type == fdr){
            p->child = insertNode(p->child,name,type);
            return p;
        }
        else{
            while(aux->next != NULL && aux->next->name[0] < name[0]){
            aux = aux->next;
            }
            if(aux->next){
                temp = aux->next;
                aux->next = createNode(name,type);
                aux->next->next = temp;
            }
            else {aux->next = createNode(name,type);}
        }
            
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

void folderOut(Stack *s){
    if(!isEmpty(s)){
        Folder *aux = s->top;
        s->top = s->top->next;
        free(aux);
    }
}
void folderIn(Stack *s, char* name){
    Node* aux = s->top->p;
    while(aux && aux->next != NULL){
        if(strcmp(aux->name,name) == 0 && aux->type == fdr){
            push(s,aux);
            break;
        }
        aux = aux->next;
    }
}