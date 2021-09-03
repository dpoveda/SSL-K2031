#include <stdio.h>
#include <stdlib.h> //system()
#include "scanner.h"

int main(){
    get_token(); 

    /*FILE *entrada;
    entrada = fopen("entrada.txt", "r");

    if (entrada == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
        get_token();
    }

    fclose(entrada);*/

    system("pause");
    return 0;
}