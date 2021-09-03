#include <stdio.h>
#include <string.h> //memset
#include <stdlib.h> //exit
#include <ctype.h>  //isspace()
#include "scanner.h"

// Definición de estados
typedef enum
{
    Q0_inicial,
    Q1_cadena,
    Q2_separador,
    Q3_finDeTexto
} ESTADO;

/* Prototipos para el manejo del buffer */
char buffer[200] = {};
void agregar_caracter(char); //Agrega caracter al buffer
void limpiar_buffer();       //Limpia el buffer
int bufferIndex = 0;

/* Prototipos de funciones privadas */
// Prototipo para la creación de TOKENs
typedef TOKEN tipoDeToken;
TOKEN crear_token(tipoDeToken);
//Prototipo para función ActionState_Qx
TOKEN ActionState_Qx(ESTADO, char *, tipoDeToken);
static TOKEN tokenActual;

TOKEN get_token()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        ESTADO estadoActual = Q0_inicial;
        switch (estadoActual)
        {
        case Q0_inicial:
            if (c == ',')
            {
                estadoActual = Q2_separador;
                break;
            }
            else if (c == '#')
            {
                estadoActual = Q3_finDeTexto;
                break;
            }
            else if (!isspace(c) && c != '\n' && c != '\t')
            {
                estadoActual = Q1_cadena;
                break;
            }
            else
            {
                ungetc(c, stdin);
            }
            
        case Q1_cadena:
            agregar_caracter(c);
            break;
        case Q2_separador:
            if (tokenActual == CAD)
            {
                return ActionState_Qx(estadoActual, buffer, CAD);
            }
            agregar_caracter(c);
            return ActionState_Qx(estadoActual, buffer, SEP);
            break;
        case Q3_finDeTexto:
            printf("\nFin De Texto: \n\n");
            break;
        }
    }
    exit(1);
}

/* Definición de funciones para el manejo del buffer */
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

/* Definición de funciones para el manejo de TOKENs. */
//  devuelve un TOKEN con su data y tipo correspondiente.
TOKEN crear_token(tipoDeToken tipo)
{
    tokenActual = tipo;
    return tokenActual;
}

// ActionState_Qx simplifica el "reseteo" al estado inicial y retorno del TOKEN.
TOKEN ActionState_Qx(ESTADO state, char *c, tipoDeToken type_Qx)
{
    state = Q0_inicial;
    if (type_Qx == CAD)
    {
        printf("\nCadena: %c\n\n", c);
    }
    else if (type_Qx == SEP)
    {
        printf("\nSeparador: %c\n\n", c);
    }
    limpiar_buffer();
    return crear_token(type_Qx);
}