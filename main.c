#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "structs.h"

#define MAX_INPUT_SIZE 15
#define CMD_SIZE 3
#define PAR_SIZE MAX_INPUT_SIZE - CMD_SIZE - 1

int main(){
    char buffer[MAX_INPUT_SIZE], cmd[CMD_SIZE], par[PAR_SIZE];
    Node *root = NULL;
    Stack *folders = (Stack*)malloc(sizeof(Stack));
    initializeStack(folders);
    root = insertNode(root,"raiz",folder);

    do{
        showPath(root);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        copyStr(cmd,buffer,0,CMD_SIZE-1);
        copyStr(par,buffer,CMD_SIZE,MAX_INPUT_SIZE-1);   

        if(strcmp(cmd,"ls") == 0){
            listNodes(folders->top->p);
        } else if(strcmp(cmd,"ma") == 0){
            folders->top->p = insertNode(folders->top->p,par,file);
        } else if(strcmp(cmd,"mp") == 0){
            folders->top->p = insertNode(folders->top->p,par,folder);
        } else if(strcmp(cmd,"cd") == 0){
            if(strcmp(par,"..") == 0){
                folderOut(folders);
            } else {
                folderIn(folders,par);
            }
        } else if(strcmp(cmd,"rm") == 0){
            folders->top->p = removeNode(folders->top->p,par);
        }

    } while (strcmp(cmd,"ex") != 0);

    while (folders->top != NULL) {
    Stack *temp = folders->top;
    folders->top = folders->top->next;
    free(temp);
    }
    free(folders);

    return 0;
}
