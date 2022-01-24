#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
/* Prototipos para el manejo del buffer */
extern char buffer[200];
extern int bufferIndex;

void agregar_caracter(char); //Agrega caracter al buffer
void limpiar_buffer();       //Limpia el buffer

//Defino los tokens
enum token {FDT, CAD, SEP};
typedef enum token TOKEN;

//Prototipo para función get_token
TOKEN get_token(void);
#endif // SCANNER_H_INCLUDED
