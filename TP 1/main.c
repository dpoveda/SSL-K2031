/*
Daniela Poveda
1678322
*/
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main(){

	TOKEN token;	

	do{
		token = get_token();
		switch(token){
			case SEP:
				printf("Separador: ,\n");
				break;
			case CAD:
				printf("Cadena: %s\n", buffer);
				limpiar_buffer();
				break;
			case FDT:	
			default:
				printf("Fin de texto: \n");
				break;
		}
	}while(token != FDT);
	
	return EXIT_SUCCESS;
}
