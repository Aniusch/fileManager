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
    List *foldersPath = (List*)malloc(sizeof(List));
    initializeList(foldersPath);
    root = insertNode(root,"raiz",fdr);
    push(foldersPath,root);

    do{
        showPath(foldersPath);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        copyStr(cmd,buffer,0,CMD_SIZE-1);
        copyStr(par,buffer,CMD_SIZE,MAX_INPUT_SIZE-1);   

        if(strcmp(cmd,"ls") == 0){
            listNodes(foldersPath->top->p);
        } else if(strcmp(cmd,"ma") == 0){
            foldersPath->top->p = insertNode(foldersPath->top->p,par,fl);
        } else if(strcmp(cmd,"mp") == 0){
            foldersPath->top->p = insertNode(foldersPath->top->p,par,fdr);
        } else if(strcmp(cmd,"cd") == 0){
            if(strcmp(par,"..") == 0){
                folderOut(foldersPath);
            } else {
                folderIn(foldersPath,par);
            }
        } else if(strcmp(cmd,"rm") == 0){
            foldersPath->top->p = removeNode(foldersPath->top->p,par);
        }

    } while (strcmp(cmd,"ex") != 0);

    while (foldersPath->top != NULL) {
    Folder *temp = foldersPath->top;
    foldersPath->top = foldersPath->top->next;
    free(temp);
    }
    free(foldersPath);

    return 0;
}

// fix remove
//fix alphabetical order