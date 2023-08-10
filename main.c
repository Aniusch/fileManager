#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "structs.h"

int main(){
    char buffer[15], cmd[3], par[11];
    Node *root = NULL;
    Stack *folders = (Stack*)malloc(sizeof(Stack));
    initializeStack(folders);

    do{
        showPath(root);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        copyStr(cmd,buffer,0,2);
        copyStr(par,buffer,3,14);   

        if(strcmp(cmd,"ls") == 0){
            listNodes(folders->top->p);
        } else if(strcmp(cmd,"ma") == 0){
            folders->top->p = insertNode(folders->top->p,par,file);
        } else if(strcmp(cmd,"mp") == 0){
            folders->top->p = insertNode(folders->top->p,par,folder);
        } else if(strcmp(cmd,"cd") == 0){
            if(strcmp(par,"..") == 0){
                pop(folders);
            } else {
                folders->top = push(folders->top,par);
            }
        } else if(strcmp(cmd,"rm") == 0){

        }

    } while (strcmp(cmd,"ex") != 0);

    while (folders->top != NULL) {
    struct Node *temp = folders->top;
    folders->top = folders->top->next;
    free(temp);
    }
    free(folders);

    return 0;
}
