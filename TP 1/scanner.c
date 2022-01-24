#include <stdio.h>
#include <ctype.h>	//isspace()
#include <string.h>	//memset
#include "scanner.h"


/* Definición de funciones para el manejo del buffer */

char buffer[200] = {};
int bufferIndex = 0;

// agregar_caracter agrega el entrante al buffer
void agregar_caracter(char c)
{
    buffer[bufferIndex] = c;
    bufferIndex++;
}

// limpiar_buffer limpia el buffer utilizando memset
void limpiar_buffer()
{
    memset(buffer, 0, sizeof buffer);
    bufferIndex = 0;
}


TOKEN get_token(void){
	char ch;
	char nextCharacter;
	while((ch = getchar()) != EOF){
		if(ch!=',' && !isspace(ch)){
			agregar_caracter(ch);
			nextCharacter = getchar();
			if(nextCharacter!=',' && !isspace(nextCharacter)){
				ungetc(nextCharacter, stdin);
			}else{
				ungetc(nextCharacter, stdin);
				return CAD;
			}
		}else{
			if(ch == ','){
			return SEP;
			}
		}
	}
	return FDT;
}
