#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "structs.h"

int main(){
    char buffer[15], cmd[3], par[11];
    Node *raiz = NULL, *aux;

    do{
        showPath(raiz);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        copyStr(cmd,buffer,0,2);
        copyStr(par,buffer,3,14);   

        if(strcmp(cmd,"ls") == 0){
            
        } else if(strcmp(cmd,"ma") == 0){

        } else if(strcmp(cmd,"mp") == 0){
        
        } else if(strcmp(cmd,"cd") == 0){

        } else if(strcmp(cmd,"rm") == 0){

        }

    } while (strcmp(cmd,"ex") != 0);
    return 0;
}
